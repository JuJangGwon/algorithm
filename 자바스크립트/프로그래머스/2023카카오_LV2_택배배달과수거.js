function solution(cap, n, deliveries, pickups) {
    var answer = 0;
    
    let deliveriesEnd = deliveries.length -1
    let pickupsEnd = deliveries.length - 1
    
    while(!deliveries[deliveriesEnd] && deliveriesEnd >= 0) {
        deliveriesEnd-=1
    }
     while(!pickups[pickupsEnd] && pickupsEnd >= 0) {
        pickupsEnd-=1
    }
    
    while (deliveriesEnd > -1 || pickupsEnd > -1)
    {
        let d = cap;
        let p = cap;
        answer += Math.max(deliveriesEnd+1,pickupsEnd+1)*2
        
        while (d > 0 && deliveriesEnd > -1) {
            if(deliveries[deliveriesEnd] > 0){
                if (d >= deliveries[deliveriesEnd]){
                    d -= deliveries[deliveriesEnd]
                    deliveries[deliveriesEnd] = 0
                    deliveriesEnd -=1
                } else {
                    deliveries[deliveriesEnd] -= d
                    d = 0
                }
            }
            while(!deliveries[deliveriesEnd] && deliveriesEnd >= 0){
                deliveriesEnd-=1;
            }
        }
          while (p > 0&& pickupsEnd >-1 ) {
             if(pickups[pickupsEnd] > 0){
                if (p >= pickups[pickupsEnd]){
                    p -= pickups[pickupsEnd]
                    pickups[pickupsEnd] = 0
                    pickupsEnd -=1
                } else {
                    pickups[pickupsEnd] -= p
                    p = 0
                }
            }
            while(!pickups[pickupsEnd] && pickupsEnd >= 0){
                pickupsEnd-=1;
            }
        }     
    }
    
    return answer;
}
