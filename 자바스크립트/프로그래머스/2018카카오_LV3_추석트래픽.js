function solution(lines) {
    const times = lines.map(line => {
        const [date, time, duration] = line.split(' ');
        const [hh, mm, ss] = time.split(':').map(Number);
        const end = (hh * 3600 + mm * 60 + parseFloat(ss)) * 1000;
        const term = parseFloat(duration.slice(0, -1)) * 1000;
        const start = end - term + 1;
        console.log(start,end,term)
        return [start, end];
    });

    let maxCount = 0;

    times.forEach(([_, end]) => {
        const windowStart = end;
        const windowEnd = end + 999;

        const count = times.filter(([s, e]) => !(e < windowStart || s > windowEnd)).length;
        maxCount = Math.max(maxCount, count);
    });

    return maxCount;
}