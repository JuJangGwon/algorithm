function solution(edges) {
  var answer = [0, 0, 0, 0];

  let maxNode = 0;
  edges.forEach(edge => {
      maxNode = Math.max(maxNode, edge[0], edge[1]);
  });

  const incomingEdges = new Array(maxNode + 1).fill(0);
  const outgoingEdges = new Array(maxNode + 1).fill(0);

  edges.forEach(([from, to]) => {
      outgoingEdges[from]++;
      incomingEdges[to]++;
  });

  for (let i = 1; i <= maxNode; i++) {
      if (incomingEdges[i] === 0 && outgoingEdges[i] > 0) {
          answer[0] = i; 
          break;
      }
  }
  // 그래프 유형 판별
  edges.forEach(([from, to]) => {
      if (from === answer[0]) {
          if (outgoingEdges[to] === 1 && incomingEdges[to] === 1) {
              answer[1]++;
          } else if (outgoingEdges[to] === 1) {
              answer[2]++; 
          } else {
              answer[3]++;
          }
      }
  });

  return answer;
}