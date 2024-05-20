class Node {
  constructor(parent, nodeNum, width) {
    this.parent = parent;
    this.nodeNum = nodeNum;
    this.width = width;
    this.leftNode = null;
    this.rightNode = null;
  }
  setLeftNode(leftNode) {
    this.leftNode = leftNode;
  }
  setRighttNode(rightNode) {
    this.rightNode = rightNode;
  }
}
class BinaryTree {
  constructor(topNode) {
    this.top = topNode;
  }
  insert(node) {
    const nodeW = node.width;
    let pivotNode = this.top;
    while (true) {
      if (pivotNode.width > node.width) {
        if (!pivotNode.leftNode) {
          pivotNode.leftNode = node;
          return;
        } else {
          pivotNode = pivotNode.leftNode;
        }
      } else {
        if (!pivotNode.rightNode) {
          pivotNode.rightNode = node;
          return;
        } else {
          pivotNode = pivotNode.rightNode;
        }
      }
    }
  }

  preorderSerach() {
    const answer = [];
    function preOrder(topNode) {
      answer.push(topNode.nodeNum);
      if (topNode.leftNode) {
        preOrder(topNode.leftNode);
      }
      if (topNode.rightNode) {
        preOrder(topNode.rightNode);
      }
    }
    preOrder(this.top);
    return answer;
  }
  postOrderSearch() {
    const answer = [];
    function postOrder(topNode) {
      if (topNode.leftNode) {
        postOrder(topNode.leftNode);
      }
      if (topNode.rightNode) {
        postOrder(topNode.rightNode);
      }
      answer.push(topNode.nodeNum);
    }
    postOrder(this.top);
    console.log(answer);
    return answer;
  }
}

function solution(nodeinfo) {
  var answer = [[]];
  let maxNode = 0;
  let tree = {};
  nodeinfo.forEach((item, index) => {
    if (!tree[item[1]]) tree[item[1]] = [{ index: index + 1, w: item[0] }];
    else tree[item[1]] = [...tree[item[1]], { index: index + 1, w: item[0] }];
    maxNode = Math.max(item[1], maxNode);
  });
  Object.values(tree).forEach((item, index) => {
    item = item.sort((a, b) => a.w - b.w);
  });
  const Btree = new BinaryTree(
    new Node(null, tree[maxNode][0].index, tree[maxNode][0].w)
  );

  for (let i = maxNode - 1; i >= 0; i--) {
    if (!tree[i]) continue;
    tree[i].forEach((node) => {
      Btree.insert(new Node(null, node.index, node.w));
    });
  }
  Btree.preorderSerach();
  return [Btree.preorderSerach(), Btree.postOrderSearch()];
}
