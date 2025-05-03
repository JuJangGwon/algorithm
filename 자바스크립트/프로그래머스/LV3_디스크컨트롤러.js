class Queue {
    constructor (){
        this.arr = []
    }
    compare (a,b) {
        if (this.arr[a].needTime < this.arr[b].needTime)
            return a
        if (this.arr[a].needTime > this.arr[b].needTime)
            return b
        if (this.arr[a].startTime < this.arr[b].needTime)
            return a
        if (this.arr[b].startTime > this.arr[a].needTime)
            return b
        if (this.arr[a].num < this.arr[b].num) 
            return a
        return b
    }
    push(num) {
        this.arr.push(num)
        let pivot = this.arr.length-1;
        let parent = Math.floor(pivot / 2)
        
        while(this.compare(pivot,parent) === pivot && pivot > 0){
            [this.arr[parent],this.arr[pivot]] =  [this.arr[pivot],this.arr[parent]]
            pivot = parent 
            parent = Math.floor(pivot / 2)
        }
    }
    pop(){
        if(!this.arr.length)
            return null
        if(this.arr.length === 1){
            return this.arr.pop()
        }
        const min = this.arr[0]
        this.arr[0] = this.arr.pop()
        
        let index = 0;
        
        while (true){
            const left  = index*2 + 1
            const right = index*2+2
            let iindex = index;
            
            if (left < this.arr.length && this.compare(left,iindex) === left){
                iindex = left
            }
            if (right < this.arr.length && this.compare(right,iindex)===right){
                iindex = right
            }
            if (iindex === index) {
                break;
            }
            [this.arr[iindex],this.arr[index]] = [this.arr[index],this.arr[iindex]]
            index = iindex
        }
        return min
    }
}

function solution(jobs) {
    var answer = 0;
    
    const q = new Queue()
    
    jobs.forEach((item,index)=>{
        q.push({num : index +1, needTime : item[1], startTime : item[0]})
    })

    jobs = jobs.sort((a,b)=>a[0]-b[0])
                    
    return Math.floor(answer / jobs.length);
}