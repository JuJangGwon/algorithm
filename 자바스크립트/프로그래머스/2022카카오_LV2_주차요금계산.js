function solution(fees, records) {
    var answer = [];
    let record = new Map();
    let times = new Map();     
    
    records.map((item)=> {
        const itemarr = item.split(" ");
        if(itemarr[2] === "IN") {
            record.set(itemarr[1],itemarr[0]);
        }
        else {
            const inTimes = record.get(itemarr[1]).split(":");
            const outTimes = itemarr[0].split(":");
            let timeSum = ((outTimes[0] - inTimes[0]) * 60); 
            timeSum += (outTimes[1] - inTimes[1]);
            
            if(times.get(itemarr[1])){
                times.set(itemarr[1], times.get(itemarr[1])+timeSum)
            }
            else 
                times.set(itemarr[1], timeSum);
            record.delete(itemarr[1]);
        }
    })
    record.forEach((value, key) => {
        const inTime = value.split(":");
        let timeSum = (23 - inTime[0]) * 60; 
        timeSum += (59 - inTime[1]);
        
         if(times.get(key))
            {
                times.set(key, times.get(key)+timeSum)
            }
            else 
                times.set(key, timeSum);
    });
    times.forEach((value,key)=> {
        if (value <= fees[0])
            times.set(key,fees[1])
        else {
            let overtime = Math.ceil((value - fees[0]) / fees[2],0) * fees[3] + fees[1];
            times.set(key, overtime);
        }
    })
    answer = [...times.entries()].sort().map((subArray) => subArray[1])
    return answer;
}