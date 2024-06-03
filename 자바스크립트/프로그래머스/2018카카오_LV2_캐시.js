function solution(cacheSize, cities) {
  var answer = 0;
  
  let queue =  [];
  cities.forEach((item)=>{
      item = item.toUpperCase()
      if (cacheSize === 0) {
          answer+=5;
      } else {
          if(queue.length === cacheSize) {
          const f = queue.filter((i)=> i !== item);
          if (f.length === queue.length) {
              queue.shift();
              answer+=5;
              queue.push(item);
          } else {
              queue = f;
              answer+=1;
              queue.push(item);
          }
      } else {
          const f = queue.filter((i)=> i !== item);
          if (queue.length > 0 && f.length !== queue.length) {
              queue = f;
              answer+=1;
              queue.push(item);
          } else {
              answer+=5;
              queue.push(item);
          }
      }}
  })
  return answer;
}