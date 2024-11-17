class Queue {
  constructor() {
    this.heap = [];
  }
  getSize() {
    return this.heap.length;
  }
  push(num) {
    this.heap.push(num);
    let index = this.heap.length - 1;
    let parent = Math.floor((index - 1) / 2);

    while (
      this.heap[parent] !== undefined &&
      this.heap[parent] < this.heap[index]
    ) {
      [this.heap[parent], this.heap[index]] = [
        this.heap[index],
        this.heap[parent],
      ];
      index = parent;
      parent = Math.floor((index - 1) / 2);
    }
  }
  popMax() {
    const r = this.heap[0];

    let index = 0;
    let left = 1;
    let right = 2;
    [this.heap[this.getSize() - 1], this.heap[index]] = [
      this.heap[index],
      this.heap[this.getSize() - 1],
    ];
    this.heap.pop();

    while (
      (this.heap[left] !== undefined && this.heap[left] > this.heap[index]) ||
      (this.heap[right] !== undefined && this.heap[right] > this.heap[index])
    ) {
      let p = left;
      if (
        this.heap[right] !== undefined &&
        this.heap[right] > this.heap[left]
      ) {
        p = right;
      }
      [this.heap[p], this.heap[index]] = [this.heap[index], this.heap[p]];
      index = p;
      left = p * 2 + 1;
      right = p * 2 + 2;
    }
    return r;
  }
  popMin() {
    const end = this.getSize() - 1;

    const start = Math.floor((this.getSize() - 1) / 2);
    let mins = [this.heap[start], start];
    for (let l = start; l <= end; l++) {
      if (mins[0] > this.heap[l]) {
        mins = [this.heap[l], l];
      }
    }

    [this.heap[mins[1]], this.heap[end]] = [this.heap[end], this.heap[mins[1]]];
    return this.heap.pop();
  }
}

function solution(operations) {
  var answer = [];
  let h = new Queue();
  operations.forEach((item) => {
    item = item.split(" ");
    if (item[0] === "I") {
      h.push(parseInt(item[1]));
    }
    if (item[0] === "D") {
      if (h.getSize()) {
        if (item[1] === "1") {
          h.popMax();
        } else {
          h.popMin();
        }
      }
    }
  });
  if (!h.getSize()) return [0, 0];
  if (h.getSize() === 1) {
    const a = h.popMin();
    return [a, a];
  }
  return [h.popMax(), h.popMin()];
}
