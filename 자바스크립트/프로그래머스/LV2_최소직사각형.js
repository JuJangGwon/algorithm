function solution(sizes) {
  let maxWidth = -1;
  let maxHeight = -1;

  sizes
    .map((item) => {
      return item[0] < item[1] ? [item[1], item[0]] : [item[0], item[1]];
    })
    .forEach((item) => {
      maxWidth = Math.max(maxWidth, item[0]);
      maxHeight = Math.max(maxHeight, item[1]);
    });

  return maxWidth * maxHeight;
}
