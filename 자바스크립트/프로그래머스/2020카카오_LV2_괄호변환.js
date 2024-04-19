const checker = (string) => {
  let index = 0;
  for (let st of string) {
      if (st === '(') index++;
      else {
          index--;
          if (index < 0) return false;
      }
  }
  return index === 0
}

function solution(p) {
  if (checker(p)) return p;
  const length = p.length
  if (!length) return '';
  let u, v
  for (let i = 0, tmp = 0; i < length; i++) {
      if (p[i] === '(') tmp ++;
      else tmp--;
      if (!tmp) {
          u = p.slice(0, i+1)
          v = p.slice(i+1)
          break
      }
  }
  if (checker(u)) {
      return u + solution(v)
  }
  return `(${solution(v)})${[...u.slice(1,-1)].map(x => x === '(' ? ')' : '(').join('')}`
}