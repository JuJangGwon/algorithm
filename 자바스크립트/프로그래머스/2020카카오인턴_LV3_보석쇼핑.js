const solution = gems => {
    let answer = [-1, 100001]
    const max = [...new Set(gems)].length;
    const map = new Map();
    let [ start, end ] = [ 0, 0 ];
    
    while (start < gems.length) {
      while (max > map.size && end < gems.length) {
        map.set(gems[end], map.has(gems[end]) ? map.get(gems[end]) + 1 : 1);
        end += 1;
      }
      while (start < gems.length && map.get(gems[start]) !== 1) {
        map.set(gems[start], map.get(gems[start]) - 1);
        start += 1;
      }
      if (max === map.size && (answer[1] - answer[0] > end - start )) {
        answer = [ start, end ];
      }
      map.delete(gems[start])
      start += 1;
    }
  
    return [ answer[0] + 1, answer[1] ]
  }