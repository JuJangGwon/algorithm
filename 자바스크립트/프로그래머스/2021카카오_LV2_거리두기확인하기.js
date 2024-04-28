const dx = [0,0,1,-1];
const dy = [1,-1,0,0];

const dx2 = [1,-1,1,-1];
const dy2 = [1,-1,-1,1];


function solution(places) {
    const answer = [];
    function upDonwChekcer(place, x,y) {
        for(let i = 0; i < 4; i++) {
            for(let j = 1; j <= 2; j++) {
                const nowX = x+(dx[i] * j);
                const nowY = y+(dy[i] * j);
                if (nowX >= 0 && nowY >= 0 && nowX <= 4 && nowY <=4) {
                    if (j===1) {
                        if (place[nowY][nowX] === "P")
                            return false;
                        else if (place[nowY][nowX] === "X")
                            break;
                    } else {
                         if (place[nowY][nowX] === "P" && place[nowY-dy[i]][nowX-dx[i]]==="O")
                            return false;
                    }
                }
            }
        }
         return true;
    }
    function diagonal(place,x,y) {
        for(let i = 0; i < 4; i++) {
            const nowX = x + dx2[i];
            const nowY = y + dy2[i];
            
            if (!(nowX >= 0 && nowY >= 0 && nowX <= 4 && nowY <=4))
                continue;
            if (place[nowY][nowX] !== "P")
                continue;
            if (nowX >= 0 && y >= 0 && nowX <= 4 && y <=4) {
                if (place[y][nowX] !== "X")
                    return false;
            }
             if (x >= 0 && nowY >= 0 && x <= 4 && nowY <=4) {
                if (place[nowY][x] !== "X")
                    return false;
            }
        }
        return true;
    }
    
    function One(place) {
    for (let i = 0; i < place.length; i++) {
        place[i] = place[i].split('');
        for (let j = 0; j < place[0].length; j++) {
            if (place[i][j] === "P") {
               if(!upDonwChekcer(place,j,i))
                   return 0;
                if(!diagonal(place,j,i))
                    return 0;
            }            
        }
    }
        return 1;
    }
    places.forEach((item)=>answer.push(One(item)));
    return answer;
}