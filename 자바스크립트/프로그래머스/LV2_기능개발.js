function solution(progresses, speeds) {
  var answer = [];

  while (progresses.length) {
    let finish = 0;
    while (progresses[0] >= 100) {
      progresses.shift();
      speeds.shift();
      finish += 1;
    }
    progresses.forEach((item, index) => (progresses[index] += speeds[index]));
    finish ? answer.push(finish) : null;
  }
  return answer;
}
