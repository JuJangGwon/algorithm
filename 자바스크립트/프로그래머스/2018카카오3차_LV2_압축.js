function solution(msg) {
    var answer = [];
    let map = new Map();
    for (let i = 0; i < 26; i++)
     map.set(String.fromCharCode(i+65),i+1);
    for (let i = 0; i < msg.length; i++)
    {
        let temp = msg[i];
        while (true)
        {
            let j = i+1;
            if (map.has(temp + msg[j]) === false)
            {
                answer.push(map.get(temp));
                map.set(temp+msg[j],map.size+1);
                break;
            }
            i++;
            temp += msg[j];
        }
    }
    return answer;
}