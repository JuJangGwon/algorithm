function solution(cards) {
  var answer = [];
  const visited = new Array(cards.length+1).fill(false);
  for (let i = 0; i < cards.length; i++) {
      if(!visited[i]) {
          let k = cards[i];
          let count = 1;
          visited[i] = true;
          while (!visited[k-1]) {
              visited[k-1] = true;
              k = cards[k-1];
              count++;
          }
          answer.push(count);
      }
  }
  answer.sort((a,b)=>b-a);
  if(answer.length === 1)
      return 0;
  return answer[0] * answer[1];
}