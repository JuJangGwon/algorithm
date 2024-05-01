// k점 많이 맞춘사람이 점수를 가져감
// 똑같이 맞추면 어피치가 가져감
// 아무도 못맞추면 못얻음
// 최종 점수가 같을 경우 어피치가 이김

function solution(n, info) {
  var answer = [0, 0];
  let maxLion = 0;
  const arr = new Array(11).fill(0);
  let answerArr = [];
  function scoreCompare(leftK) {
    if (leftK > n) {
      return 0;
    }
    let aScore = 0;
    let bScore = 0;
    for (let i = 0; i < 10; i++) {
      if (arr[i] > info[i]) {
        bScore += 10 - i;
      } else if (!(arr[i] === info[i] && arr[i] === 0)) {
        aScore += 10 - i;
      }
    }

    if (answer[0] === bScore - aScore) {
      if (maxLion < bScore) {
        maxLion = bScore;
        answerArr = [...arr];
        answer = [bScore - aScore, leftK];
      } else if (answer[1] > leftK) {
        answerArr = [...arr];
        answer = [bScore - aScore, leftK];
      }
    } else if (answer[0] <= bScore - aScore) {
      maxLion = bScore;
      answerArr = [...arr];
      answer = [bScore - aScore, leftK];
    }
  }

  function dfs(ii, k) {
    if (k >= n) {
      return;
    }
    for (let i = ii + 1; i < 10; i++) {
      if (info[i] + 1 + k <= n) {
        arr[i] = info[i] + 1;
        scoreCompare(info[i] + 1 + k);
        dfs(i, k + info[i] + 1);
        arr[i] = 0;
      }
    }
  }
  dfs(-1, 0);
  if (answer[0] == 0) return [-1];
  answerArr[10] = n - answer[1];
  return answerArr;
}
