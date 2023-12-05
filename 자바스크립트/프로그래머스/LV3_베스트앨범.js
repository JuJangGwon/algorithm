function solution(genres, plays) {
    var answer = [];
    let arr = new Map();
    let arr2 = new Map();
    
    genres.map((item,index)=>{
        if(!arr.get(item))
        {
            arr.set(item,[{plays : plays[index], id : index}])
            arr2.set(item,parseInt(plays[index]));
        } else{
            arr.set(item,[...arr.get(item), {plays : plays[index], id : index}])
            arr2.set(item, parseInt(arr2.get(item)) + parseInt(plays[index]));
        }
    })
    arr.forEach((value,key)=>{
        arr.set(key,Array.from(value).sort((a,b)=>b.plays - a.plays))
    })
    arr2 = Array.from(arr2).sort((a,b)=>b[1] - a[1]);
    arr2.map((item)=>{
        for (let i = 0; i < 2; i++)
        {
            if (i ===1 && arr.get(item[0]).length <2)
                break;
            answer.push(arr.get(item[0])[i].id);
        }
    })
    return answer;
}