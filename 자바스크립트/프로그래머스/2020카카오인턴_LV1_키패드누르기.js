function solution(numbers, hand) {
  let answer = "";
  const keyPad = [[1,2,3],[4,5,6],[7,8,9],["*",0,"#"]]
  let leftHandPos = [3,0];    
  let rightHandPos = [3,2];    
  numbers.forEach((item,index)=>{
      if (item === 1 || item === 4 || item===7){
          answer+="L";
          leftHandPos = [Math.floor((item-1) / 3),0];
      }
      else if (item === 3 || item === 6 || item===9){
          answer+="R";
          rightHandPos = [Math.floor((item-1) / 3),2];
      } else {
          item = item-1
             let numPos = [Math.floor(item / 3),1];
          if (item === -1) {
              item = 0;
              numPos = [3,1]
          }

          const leftDist = Math.abs(numPos[0] - leftHandPos[0]) +  Math.abs(numPos[1] - leftHandPos[1])
          const rightDist = Math.abs(numPos[0] - rightHandPos[0]) +  Math.abs(numPos[1] - rightHandPos[1])
          if (leftDist === rightDist) {
              if (hand === "right") {
                  answer +="R";
                  rightHandPos = numPos;
              }
              else {
                  answer +="L";
                  leftHandPos =  numPos;
              }
          } else if (leftDist < rightDist){
              answer +="L";
              leftHandPos = numPos;
          } else  {
              answer += "R";
              rightHandPos =  numPos;
          }
      }
  })
  return answer;
}