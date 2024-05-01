function solution(targets) {
  var answer = 0;
  let arr = -1;
  targets.sort((a,b)=>{
        return a[1]-b[1];
  })
  targets.forEach((item)=>{
      if(arr === -1)
          arr = item[1];
      else if (arr <= item[0]) {
          answer+=1;
          arr = item[1];
      }
  })
  return arr === -1 ? answer : answer+1;
}