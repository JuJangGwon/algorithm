const useable = Array.from({ length: 10 }, () => false);
const useable2 = Array.from({ length: 10 }, () =>
  Array.from({ length: 10 }, () => false)
);
let Dice;
let left = [];
let right = [];
const answer = [];

const MakeCombine2 = (arr, pivot, limit, arr2, left2) => {
  if (pivot === limit) {
    let sum = 0;
    for (let i = 0; i < limit; i++) {
      sum += parseInt(Dice[arr2[i]][arr[i]]);
    }
    if (left2) {
      left.push(sum);
    } else {
      right.push(sum);
    }
    return;
  }
  for (let i = 0; i < 6; i++) {
    if (!useable2[pivot][i]) {
      arr[pivot] = i;
      useable2[pivot][i] = true;
      MakeCombine2(arr, pivot + 1, limit, arr2, left2);
      useable2[pivot][i] = false;
    }
  }
};

const MakeCombine = (arr, pivot, num, limit) => {
  if (num === limit) {
    left = [];
    right = [];
    MakeCombine2([], 0, limit, arr, true);

    let tempArr = [];
    for (let i = 0; i < limit * 2; i++) {
      if (!useable[i]) {
        tempArr.push(i);
      }
    }

    MakeCombine2([], 0, limit, tempArr, false);
    left = left.sort((a, b) => a - b);
    right = right.sort((a, b) => a - b);
    let win = 0;

    for (let item of left) {
      let l = 0;
      let r = right.length - 1;
      let minium = 0;
      while (l <= r) {
        let mid = Math.floor((l + r) / 2);
        if (item > right[mid]) {
          l = mid + 1;
          minium = Math.max(l, minium);
        } else {
          r = mid - 1;
        }
      }
      win += minium;
    }
    answer.push({ win, arr: Array.from(arr).sort((a, b) => a - b) });
    return;
  }
  for (let i = pivot; i < limit * 2; i++) {
    if (!useable[i]) {
      arr[num] = i;
      useable[i] = true;
      MakeCombine(arr, i + 1, num + 1, limit);
      useable[i] = false;
    }
  }
};

function solution(dice) {
  Dice = dice;
  const result = MakeCombine([], 0, 0, dice.length / 2);
  answer.sort((a, b) => b.win - a.win);

  return answer[0].arr.map((i) => {
    return i + 1;
  });
}
