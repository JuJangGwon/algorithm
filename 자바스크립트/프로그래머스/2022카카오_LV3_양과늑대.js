class Node {
  constructor(num, animalType) {
    this.nodeNum = num;
    this.animalType = animalType;
    this.left = null;
    this.right = null;
  }
}
class BinaryTree {
  constructor() {
    this.head = null;
  }
}

function solution(info, edges) {
  const treeNode = Array.from({ length: info.length }, () => []);
  const visited = Array.from({ length: info.length }, () => false);
  let willVisted = [];
  var answer = 0;
  edges.sort((a, b) => a[0] - b[0]);
  edges.forEach((edge, index) => {
    treeNode[edge[0]].push(edge[1]);
  });

  function DFS(nowNode, sheep, wolf, nextvisited) {
    if (sheep === wolf) {
      return;
    }
    answer = Math.max(answer, sheep);
    if (answer === 5) {
      for (let i = 0; i < visited.length; i++) {
        console.log(i + "-" + visited[i]);
      }
    }

    visited[nowNode] = true;
    if (treeNode[nowNode]) {
      nextvisited = [
        ...nextvisited.filter((item) => item !== nowNode),
        ...treeNode[nowNode],
      ];
    }
    for (let i of nextvisited) {
      const nextNode = i;
      if (!visited[i]) {
        if (info[i] === 0) {
          visited[i] = true;
          DFS(nextNode, sheep + 1, wolf, nextvisited);
          visited[i] = false;
        } else if (info[i] === 1 && sheep > wolf + 1) {
          visited[i] = true;
          DFS(i, sheep, wolf + 1, nextvisited);
          visited[i] = false;
        }
      }
    }
  }
  DFS(0, 1, 0, treeNode[0]);
  return answer;
}
