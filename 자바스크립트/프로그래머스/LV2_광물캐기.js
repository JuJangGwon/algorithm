function solution(picks, minerals) {
  var answer = 0;
  const picksSum = picks.reduce((re,i)=>re+=i);
  const arr = [];
  for (let i = 0; i < minerals.length; i+=5) {
      if (i === picksSum * 5)
          break;
      let j = i;
      let sum = 0; 
      while(minerals[j] && j <i+5){
          switch (minerals[j]) {
              case "diamond":
                  sum +=25;
                  break;
              case "iron":
                  sum +=5;
                  break;
              case "stone":
                  sum +=1;
                  break;
          }
          j++
      }
      arr.push({sum, num : i});
  }
  arr.sort((a,b)=>b.sum - a.sum);
  console.log(arr);
  arr.forEach((a)=>{
      if (picks[0] > 0) {
          picks[0]-=1;
           const c = minerals.slice(a.num,a.num+5);
          answer += c.length;
      } else if(picks[1] > 0) {
           picks[1]-=1;
           const c = minerals.slice(a.num,a.num+5);
           const dia = c.filter((a)=>a==="diamond")
           const iron = c.filter((a)=>a==="iron")
           const stone = c.filter((a)=>a==="stone")
           answer += dia.length * 5 + iron.length + stone.length;
      } else if (picks[2] > 0){
           picks[2]-=1;
           const c = minerals.slice(a.num,a.num+5);
           const dia = c.filter((a)=>a==="diamond")
           const iron = c.filter((a)=>a==="iron")
           const stone = c.filter((a)=>a==="stone")
           console.log(dia,iron,stone);
           answer += dia.length * 25 + iron.length * 5 + stone.length;
      }
  })
  return answer;
}