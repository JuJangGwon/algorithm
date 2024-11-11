function solution(stones, k) {
  let pivot = [1, 200000000];

  const canMove = (mid) => {
    let nope = 0;
    for (let i = 0; i < stones.length; i++) {
      nope = stones[i] - mid > 0 ? 0 : nope + 1;
      if (nope === k) return false;
    }
    return true;
  };

  while (pivot[0] !== pivot[1]) {
    const mid = Math.floor((pivot[0] + pivot[1]) / 2);
    if (canMove(mid)) {
      pivot[0] = mid + 1;
    } else {
      pivot[1] = mid;
    }
  }
  return pivot[0];
}
