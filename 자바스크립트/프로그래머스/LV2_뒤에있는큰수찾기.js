function solution(numbers) {
    const stk = [numbers[numbers.length-1]]
    numbers[numbers.length-1] = -1
    for (let i = numbers.length-1 ; i>0 ; i--){
        
        let num = stk.pop()
        
        while (stk.length && num <= numbers[i-1]) num = stk.pop()
    
        if ( num > numbers[i-1]) {
            stk.push(num)
            stk.push(numbers[i-1])
            numbers[i-1] = num
        } else if (!stk.length){
            stk.push(numbers[i-1])
            numbers[i-1]  =  -1
        }
    }
    return numbers
}