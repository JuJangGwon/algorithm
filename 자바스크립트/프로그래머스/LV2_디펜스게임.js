class Heap {
  constructor() {
    this.heap = [];
  }
  getSize() {
    return this.heap.length;
  }

  push(num) {
    let pivot = this.getSize();
    this.heap[this.getSize()] = num;
    let parentPivot = Math.floor((pivot - 1) / 2);

    while (
      this.heap[parentPivot] &&
      this.heap[parentPivot] < this.heap[pivot]
    ) {
      [this.heap[pivot], this.heap[parentPivot]] = [
        this.heap[parentPivot],
        this.heap[pivot],
      ];
      pivot = parentPivot;
      parentPivot = Math.floor((pivot - 1) / 2);
    }
  }
  pop() {
    const r = this.heap[0];
    [this.heap[0], this.heap[this.getSize() - 1]] = [
      this.heap[this.getSize() - 1],
      this.heap[0],
    ];
    this.heap.pop();
    let pivot = 0;
    let left = pivot * 2 + 1;
    let right = pivot * 2 + 2;

    while (
      (this.heap[left] > 0 && this.heap[left] > this.heap[pivot]) ||
      (this.heap[right] > 0 && this.heap[right] > this.heap[pivot])
    ) {
      let p = left;
      if (this.heap[right] > 0 && this.heap[right] > this.heap[left]) {
        p = right;
      }
      [this.heap[p], this.heap[pivot]] = [this.heap[pivot], this.heap[p]];
      pivot = p;
      left = p * 2 + 1;
      right = p * 2 + 2;
    }
    return r;
  }
}

function solution(n, k, enemy) {
  var answer = 0;
  let sum = 0;
  const h = new Heap();
  enemy.forEach((item) => {
    sum += item;
    h.push(item);
    if (sum > n) {
      if (k === 0) return answer;
      else {
        sum -= h.pop();
        k -= 1;
      }
    }
    answer += 1;
  });

  return answer;
}
