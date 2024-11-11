function solution(n, s) {
  const c = Math.floor(s / n);
  if (n > s) return [-1];
  const answer = Array.from({ length: n }, () => c);
  let sum = c * n;
  for (let i = 0; i < s - sum; i++) {
    answer[n - 1 - i] += 1;
  }

  return answer;
}
