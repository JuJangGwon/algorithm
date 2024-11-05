function solution(key, lock) {
    
  const result = lock.reduce((acc,item)=> {
      let number = 0;
      item.forEach((ba)=> {if(ba===0) number += 1})
      return acc +=number 
  },0)
  
  const rotateFunc = (key) => {
      const newArr = Array.from({length : key.length},()=>Array.from({length : key.length},()=>false))
      for (let i = 0; i < key.length; i++) {
          for (let j = 0; j < key.length; j++) {
              newArr[j][key.length - i - 1] = key[i][j];
          }
      }
      return newArr
  }
  
  const arr = Array.from({length : key.length *2 + lock.length -2},()=>Array.from({length : key.length *2 + lock.length -2},()=>2))
  for (let i = 0; i < lock.length; i++) {
      for (let j = 0; j < lock.length; j++) {
          arr[i+key.length-1][j+key.length-1] = lock[i][j]; 
      }
  }
  
  const checker = (x,y)=>{
      let a = 0;
      for (let k = 0; k <key.length; k++) {
          for (let c = 0; c < key.length ; c++) {
              if (key[k][c] === 0)
                  continue;
              else if (arr[k + y][c + x] === 0 )
              {
                  a+=1
              } else if (arr[k + y][c + x] ===2){
                  continue
              } 
              else {
                  return false;
              }
          }
      }
      return a
  }
  for (let r = 0; r <4; r++) {
      key = rotateFunc(key)
      for (let i = 0; i < lock.length + key.length -1; i++) {
       for (let j = 0; j < lock.length + key.length -1; j++){
            if(result === checker(j,i)) return true
          }
      }
  }
  
  return false;
}
