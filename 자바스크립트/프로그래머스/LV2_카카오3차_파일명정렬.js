function solution(files) {
    var answer = [];
    let arr = [];
    
    files.map((item)=>{
        let head = "";
        let number = "";
        let tail = "";
        
        let pivot = 0;
        let pivot2 = 0;
        for (let i = 0; i < item.length;i ++)
        {
            if (item[i] >= '0' &&item[i] <= '9')
            {
                pivot = i;
                break;
            }
        }
        for (let i = pivot; i < item.length;i ++)
        {
            if (!(item[i] >= '0' &&item[i] <= '9'))
            {
                pivot2 = i;
                break;
            }
        }
         head = item.slice(0,pivot);
         number = item.slice(pivot,pivot2);
        if (pivot2 !== item.length) tail= item.slice(pivot2,item.length);
        arr.push({head,number,tail});
    });
     arr.sort((a,b) => {
        let aHead = a.head.toLowerCase();
        let bHead = b.head.toLowerCase();
        if(aHead < bHead) return -1;
        else if(aHead > bHead) return 1;
        else {
            let aNumber = parseInt(a.number);
            let bNumber = parseInt(b.number);            

            if(aNumber < bNumber) return -1;
            else if(aNumber > bNumber) return 1;
            else return 0;
        }
    })
    arr.map((item)=>{
        answer.push(item.head+item.number+item.tail);
    })
    return answer;
}