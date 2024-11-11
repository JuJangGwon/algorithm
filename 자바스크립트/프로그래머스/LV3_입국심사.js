function solution(n, times) {
  var answer = 0;
  times = times.sort((a, b) => a - b);
  const num = [0, Math.max(...times) * n];

  while (num[0] <= num[1]) {
    let mid = Math.floor((num[0] + num[1]) / 2);
    let a = 0;
    for (let i = 0; i < times.length; i++) {
      a += Math.floor(mid / times[i]);
    }
    if (a >= n) {
      num[1] = mid - 1;
    } else {
      num[0] = mid + 1;
    }
  }

  return num[0];
}
