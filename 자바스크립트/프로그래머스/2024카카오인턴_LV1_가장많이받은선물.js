function solution(friends, gifts) {
    const answer = Array.from({length : friends.length}, ()=> 0)
    const friendsMap = new Map();
    const giftScoreArr = new Array(friends.length).fill(0);
    const gift2ARR = Array.from({length : friends.length}, ()=> Array.from({length : friends.length},()=>0))
          
    friends.forEach((item,index)=> friendsMap.set(item,index));
    gifts.forEach((item)=>{
        const giftFriend = item.split(' ');
        gift2ARR[friendsMap.get(giftFriend[0])][friendsMap.get(giftFriend[1])] +=1;
        
        giftScoreArr[friendsMap.get(giftFriend[0])]+=1;
        giftScoreArr[friendsMap.get(giftFriend[1])]-=1;
    })
    for (let i = 0; i < friends.length; i++) {
        for (let j = i; j < friends.length; j++){
            if (i===j)
                continue;
            if (gift2ARR[i][j] > gift2ARR[j][i]){
                answer[i]+=1;
            } else if (gift2ARR[i][j] < gift2ARR[j][i]) {
                answer[j] +=1;
            } else {
                
                if (giftScoreArr[i] > giftScoreArr[j])
                answer[i]+=1
                else if (giftScoreArr[i] < giftScoreArr[j])
                answer[j]+=1
            }
        }
    }
   
    return Math.max(...answer);
}