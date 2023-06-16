function solution(n, arr1, arr2) {
    var answer = [];
    
    for (let i =0; i < n; i++)
    {
        const temp = (arr1[i] | arr2[i]).toString(2);
        let line = [];
        for (let j = temp.length-n; j < temp.length; j++)
        {
                if(temp[j]==='1')
                    line.push('#');
                else
                    line.push(' ');
        }
        answer.push(line.join(''));
    }
    return answer;
}