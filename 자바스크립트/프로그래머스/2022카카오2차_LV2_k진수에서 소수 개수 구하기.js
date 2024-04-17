function solution(n, k) {
    var answer = 0;
    
    let demical = n.toString(k);
     let maxNumber = Math.max(...demical.split('0').map(num => parseInt(num, 10)).filter(Boolean), n);
    let isPrime = Array.from({length : maxNumber+1},()=> true);
    isPrime[0] = false;
        isPrime[1] = false;
    
    for (let i = 2; i*i <= maxNumber; i++) {
        if (isPrime[i]) {
            for (let j = 2; j * i <= maxNumber; j++) {
            isPrime[i*j] = false;    
        }
        }
    }
    const arr = demical.split("0").filter((a)=> a!=="")
    arr.forEach((i)=> {if(isPrime[parseInt(i)]) answer++})     
    return answer;
}