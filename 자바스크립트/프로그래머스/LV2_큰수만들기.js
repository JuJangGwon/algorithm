function solution(number, k) {
    var answer = [];
    let deleteCount = 0;
    for (let i = 0; i < number.length; i++)
    {
        while(deleteCount < k && number[i] > answer[answer.length-1])
        {
            answer.pop();
            deleteCount++;
        }
        if (answer.length < number.length -k)
        {
            answer.push(number[i]);
        }
    }
    return answer.join('');
}