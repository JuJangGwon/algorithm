function solution(relation) {
  const cols = relation[0].length;
  const candidates = [];
  const allSets = [];

  function generateCombinations(arr, start, depth, maxDepth, currentSet) {
    if (depth === maxDepth) {
      allSets.push([...currentSet]);
      return;
    }

    for (let i = start; i < arr.length; i++) {
      currentSet.push(arr[i]);
      generateCombinations(arr, i + 1, depth + 1, maxDepth, currentSet);
      currentSet.pop();
    }
  }

  const colsArr = Array.from({ length: cols }, (_, index) => index);

  for (let i = 1; i <= cols; i++) {
    generateCombinations(colsArr, 0, 0, i, []);
  }

  allSets.forEach((set) => {
    const tmpSet = new Set();
    relation.forEach((row) => {
      const key = set.map((col) => row[col]).join(":");
      tmpSet.add(key);
    });

    if (tmpSet.size === relation.length && checkMinimality(candidates, set)) {
      candidates.push(set);
    }
  });

  return candidates.length;
}

function checkMinimality(candidates, currentSet) {
  return !candidates.some((candidate) =>
    candidate.every((elem) => currentSet.includes(elem))
  );
}
