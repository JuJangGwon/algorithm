function solution(data, col, row_begin, row_end) {
    var answer = 0;
      col--;
      data.sort((a,b)=>{
        if(a[col]>b[col]){
          return 1;
        }
        else if(a[col] === b[col]){
          if(a[0]<b[0]){
            return 1;
          }
          else{
            return -1;
          }
        }
        else{
          return -1;
        }
      })
    
      for(var i = row_begin;i<=row_end;i++){
        var sum = 0;
        data[i-1].forEach(element => {
          sum+=(element%i);
        });
        answer = answer ^ sum;
  
      }
    return answer;
  }