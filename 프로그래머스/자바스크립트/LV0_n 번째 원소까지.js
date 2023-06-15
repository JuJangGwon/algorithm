function solution(num_list, n) {
    var answer = [];
    for (let i =0 ; i < n; i++)
        answer = num_list.slice(0,n);
    return answer;
}