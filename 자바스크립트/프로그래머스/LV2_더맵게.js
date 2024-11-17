class Queue {
  constructor() {
      this.heap = []
  }
  getSize() {
      return this.heap.length
  }
  push(num) {
      
      let pivot = this.getSize();
      this.heap[pivot] = num;
      
      let parentPivot = Math.floor((pivot -1)/ 2 )
      
      while(this.heap[parentPivot]  && pivot >= 0 && this.heap[pivot] < this.heap[parentPivot]) {
          [this.heap[parentPivot],this.heap[pivot]] = [this.heap[pivot],this.heap[parentPivot]]
          pivot = parentPivot
          parentPivot =  Math.floor((pivot-1) / 2)
      }
  }
  pop() {
      let pivot = 0;
      let leftPivot = pivot *2 +1;
      let rightPivot = pivot *2 +2;
      const result = this.heap[0];
      [this.heap[0],this.heap[this.getSize()-1]] = [this.heap[this.getSize()-1],this.heap[0]]
      this.heap.pop()
      
      while((this.heap[leftPivot] && this.heap[leftPivot] < this.heap[pivot]) || (this.heap[rightPivot] && this.heap[rightPivot] < this.heap[pivot])) {
          let minPivot = leftPivot;
          if (this.heap[rightPivot] && this.heap[minPivot] > this.heap[rightPivot]) {
              minPivot =rightPivot;
           }
          [this.heap[pivot],this.heap[minPivot]] = [this.heap[minPivot],this.heap[pivot]]
          pivot = minPivot
          leftPivot = pivot *2 +1;
          rightPivot = pivot *2 +2;
      }
       return result;
  }
}

function solution(scoville, K) {
  var answer = 0;
  const q = new Queue()
  scoville.forEach((item)=>{
      q.push(item)
  })
  while(q.getSize() >= 2){
      let a = q.pop()
      if (a >= K)
          return answer
      let b = q.pop()
      q.push(a + b*2)
      answer ++
  }   
  if(q.pop() >= K)
      return answer

  return -1;
}