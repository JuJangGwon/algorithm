function solution(dirs) {
    var answer = 0;
    let myX =5;
    let myY =5;
    
    const arr = Array.from(Array(11), () => Array.from({length:11},()=>false));
    //arr[5][5] = true;
    
    dirs.split('').map((item)=>{
        switch(item)
        {
            case "U":
                if(myY === 10)
                    break;
                myY +=1;
                if(!(arr[myY][myX]&& arr[myY-1][myX]))
                {
                    answer+=1;
                    arr[myY-1][myX] = true
                }
                break;
             case "D":
                 if(myY === 0)
                    break;
                myY -=1;
                 if(!(arr[myY][myX]&& arr[myY+1][myX]))
                {
                    answer+=1;
                    arr[myY+1][myX] = true
                }
                break;
             case "R":
                if(myX === 10)
                    break;
                myX +=1;
              if(!(arr[myY][myX]&& arr[myY][myX-1]))
                {
                    answer+=1;
                    arr[myY][myX-1] = true
                }
                break;
             case "L":
                 if(myX === 0)
                    break;
                myX -=1;
              if(!(arr[myY][myX]&& arr[myY][myX+1]))
                {
                    answer+=1;
                    arr[myY][myX+1] = true
                }
                break;
        }
        console.log("X = ",myX, "Y = ",myY)
    });
    return answer;
}