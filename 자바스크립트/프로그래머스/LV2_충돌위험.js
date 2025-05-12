function solution(points, routes) {
    var answer = 0;
    const isEqual = (a, b) => 
    a.length === b.length && a.every((v, i) => v === b[i]);
    
    const myPoint = (nowPosition, destination) => {
        const [nowPositionY,nowPositionX] = nowPosition
        const [destinationY,destinationX] = points[destination-1]
        if (nowPositionY > destinationY) {
            return [nowPositionY-1, nowPositionX]
        } else  if (nowPositionY < destinationY){
            return [nowPositionY+1, nowPositionX]
        }
        else if (nowPositionX > destinationX) {
            return [nowPositionY, nowPositionX-1]
        } else  if (nowPositionX < destinationX){
            return [nowPositionY, nowPositionX+1]
        }
    }
    routes = routes.sort((a,b)=>a.length-b.length)
    routes = routes.map((item)=>  {
    const newItem = [...item]
    newItem[0] = points[item[0] - 1]
    return newItem;
})
   let docs2 = {};
    
    routes.forEach((item,index)=>{
           const abc = `y${item[0][0]}x${item[0][1]}`
            if (!docs2[abc]) {
                docs2[abc] = 1
            } else if (docs2[abc] === 1){
                docs2[abc] = 2
                answer+=1
            }
    })
    while (routes.length){
        let tempRoutes = [];
        let docs = {};
        routes.forEach((item,index)=>{
           
            const newPos = myPoint(item[0],item[1])
            const abc = `y${newPos[0]}x${newPos[1]}`
            if (!docs[abc]) {
                docs[abc] = 1
            } else if (docs[abc] === 1){
                docs[abc] = 2
                answer+=1
            }
            if(isEqual(newPos,points[item[1]-1])){
                if(item.length > 2) {
                    item.shift()
                    item[0] = newPos
                    tempRoutes.push(item)
                }
            } else {
                item[0] = newPos
                tempRoutes.push(item)
            }
        })
        routes = tempRoutes
    }
    
    return answer;
}

