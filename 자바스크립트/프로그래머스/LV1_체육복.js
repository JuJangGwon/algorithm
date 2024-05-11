function solution(n, lost, reserve) {
  let realLost = lost.filter(l => !reserve.includes(l));
  let realReserve = reserve.filter(r => !lost.includes(r));
  
  realLost.sort((a, b) => a - b);
  realReserve.sort((a, b) => a - b);

  let answer = n - realLost.length;

  for (let i = 0; i < realLost.length; i++) {
      let index = realReserve.findIndex(r => Math.abs(r - realLost[i]) === 1);
      if (index !== -1) {
          answer++;
          realReserve.splice(index, 1);
      }
  }

  return answer;
}