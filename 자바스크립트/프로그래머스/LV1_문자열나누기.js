function solution(s) {
    var answer = 0;
    let same;
    let x = 0;
    let y = 0;
    for (let i = 0; i < s.length; i++) {
        if (x === 0) {
            x = 1;
            same = s[i];
            answer++;
        }
        else {
            if (s[i] === same)
                x++;
            else
                y++;
            if (x === y) {
                x = 0;
                y = 0;
            }
        }
    }
    return answer;
}