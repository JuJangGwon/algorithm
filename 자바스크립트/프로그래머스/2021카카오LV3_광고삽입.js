function solution(play_time, adv_time, logs) {
    const timeToSec = (time) => {
        const [h, m, s] = time.split(':').map(Number);
        return h * 3600 + m * 60 + s;
    };
    const secToTime = (sec) => {
        const h = String(Math.floor(sec / 3600)).padStart(2, '0');
        sec %= 3600;
        const m = String(Math.floor(sec / 60)).padStart(2, '0');
        const s = String(sec % 60).padStart(2, '0');
        return `${h}:${m}:${s}`;
    };

    const play = timeToSec(play_time);
    const adv = timeToSec(adv_time);
    const view = new Array(play + 2).fill(0); // 0~play+1초까지

    // 1. 시청 기록 반영 (차이 배열 방식)
    for (let log of logs) {
        const [start, end] = log.split('-');
        view[timeToSec(start)] += 1;
        view[timeToSec(end)] -= 1;
    }

    // 2. 첫 번째 누적합 → 초당 시청자 수
    for (let i = 1; i <= play; i++) {
        view[i] += view[i - 1];
    }

    // 3. 두 번째 누적합 → 0~i초까지 누적 시청 시간
    for (let i = 1; i <= play; i++) {
        view[i] += view[i - 1];
    }

    // 4. 슬라이딩 윈도우 → 광고 구간 중 가장 누적 시청시간이 긴 곳 찾기
    let maxTime = view[adv - 1];
    let maxStart = 0;
    for (let i = adv; i <= play; i++) {
        const total = view[i] - view[i - adv];
        if (total > maxTime) {
            maxTime = total;
            maxStart = i - adv + 1;
        }
    }

    return secToTime(maxStart);
}
