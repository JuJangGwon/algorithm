function solution(n) {
    for (let i = 1; i < 6 * n; i++){
        if ((6 * i) % n === 0){
            return i
        }
    }
}