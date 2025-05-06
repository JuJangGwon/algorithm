// 퍼즐 난이도 DIFF
// 소요 시간 TIME_CUR
// 이전 퍼즐 소요시간 TIME-PREV
// 숙련도 LEVEL

function solution(diffs, times, limit) {
    var answer = 0;
    
    const checker = (lv) =>{
        let time = times[0];
        let i = 1;
        for (; i< diffs.length ;i++){
            if(lv >= diffs[i]) {
                time += times[i]
            } else {
                time += (diffs[i] - lv) * (times[i-1] + times[i]) + times[i]
            }
            if (time > limit) {
                return -1
            }
        }
        return [i,time]
    }
    const binarySearch = () => {
        let left = 1;
        let right = diffs.reduce((a, b) => Math.max(a, b), -Infinity);
        let mid = Math.floor((left + right) / 2 ) 
        
        while (left <= right) {
             mid = Math.floor((left + right) / 2 ) 
             const c = checker(mid)
             if (c===-1){
                 left = mid + 1
             } else if (c[0] === diffs.length) {
                 answer = mid;
                 right = mid - 1; 
             } else {
                 right = mid -1
             }
        }
    }
    binarySearch()
    return answer;
}