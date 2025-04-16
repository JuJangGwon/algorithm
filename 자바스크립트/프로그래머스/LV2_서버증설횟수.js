function solution(players, m, k) {
    var answer = 0;
    
    const stack = Array.from({length : k},()=> 0)
    let nowCom = 1;
    players.forEach((item,index)=>{
        const b = stack.shift()
        nowCom -= b;
        if(nowCom * m <= item){
            if(!(item - (nowCom * m)) % m){
                const a = (item - ((nowCom-1)* m)) / m
                stack.push(a)
                nowCom+=a
                answer+=a
            } else {
                const a = Math.floor((item - ((nowCom-1) * m)) / m)
                stack.push(a)
                nowCom+=a
                answer+=a
            }
        } else {
            stack.push(0)
        }
    })
    return answer;
}