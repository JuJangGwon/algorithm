function solution(strlist) {
    var answer = [];
    strlist.map((e)=> {
       answer.push(e.slice().length);
    });
    return answer;
}