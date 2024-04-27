function solution(book_time) {
  var answer = 0;
  
  const bookTime = book_time.map((item)=>{
      const startTime = item[0].split(":");
      const endTime = item[1].split(":");
      return [parseInt(startTime[0]) * 60 +  parseInt(startTime[1]),parseInt(endTime[0]) * 60 +  parseInt(endTime[1]) + 10];
  })
  const Times = [];
  bookTime.sort((a,b)=> a[0]-b[0]);
  bookTime.forEach((item)=>{
      if (Times.length === 0){
          Times.push(item[1]);
          answer = Math.max(answer,Times.length)
      }
      else {
          while(Times.length  && Times[0] <= item[0]) {
              Times.shift();
          }
          Times.push(item[1]);
          Times.sort((a,b)=>a-b);
          answer = Math.max(answer,Times.length);
      }
  })
  return answer;
}