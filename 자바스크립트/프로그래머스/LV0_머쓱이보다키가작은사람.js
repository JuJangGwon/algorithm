function solution(array, height) {
    var answer = array.filter((e)=> e > height).length;
    return answer;
}