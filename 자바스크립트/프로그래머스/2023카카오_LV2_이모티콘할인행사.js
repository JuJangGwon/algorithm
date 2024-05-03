// 10% 20% 30% 40%
// 이포티콘 서비스 가입자 최대로 
// 이모티콘 판매액을 최대로 .

// 각 이모티콘 모두 구매 
// 하지만 이모티콘 구매비용합보다 구독서비스가 싸다면 구독서비스 구매 


function solution(users, emoticons) {
  const answer = [0,0];
  const firstElements = users.map(user => user[0]);
  const saleRange = [Math.min(...firstElements),Math.max(...firstElements)]
  
  const rate = new Array(emoticons.length).fill(10);
  
  function sums(arr) {
      let ar = [0,0];
      users.forEach((user)=>{
          let results = 0;
          arr.forEach((arrItem,index)=>{
             {
                 if (arrItem >= user[0]) {
                  results += Math.floor(emoticons[index]- emoticons[index] / 100 * arrItem)
                 }
              }
          })
          if (results >= user[1]) {
              ar[0]++;
          } else {
              ar[1] += results;
          }
      })
      if (answer[0] < ar[0]){
          answer[0] = Math.max(answer[0],ar[0]);
          answer[1] = ar[1];
      } else if(answer[0]=== ar[0]) {
          answer[1] = Math.max(answer[1],ar[1]);
      }
  }
  
  function dfs(arr,num) {
      if (num === emoticons.length) {
          sums([...arr]);
          return ;
      }
      for(let j = 1; j <= 4; j++) {
          arr[num] = j * 10;
          dfs([...arr],num + 1);
          arr[num] = 10;
      }
  }
  dfs([...rate],0)
  return answer;
}