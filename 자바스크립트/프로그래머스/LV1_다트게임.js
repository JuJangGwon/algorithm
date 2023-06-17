function solution(dartResult) {
    let dart = dartResult.split("");
    let score = [];
  
    for (let i = 0; i < dart.length; i++) {
      if (dart[i] === "0" && dart[i - 1] === "1") dart[i] = 10;
      if (dart[i] === "S") score.push(Math.pow(dart[i - 1], 1));
      if (dart[i] === "D") score.push(Math.pow(dart[i - 1], 2));
      if (dart[i] === "T") score.push(Math.pow(dart[i - 1], 3));
      if (dart[i] === "*") score.push("*");
      if (dart[i] === "#") score.push("#");
    }
  
    for (let i = 0; i < score.length; i++) {
      if (score[i] === "#") {
        score[i - 1] = score[i - 1] * -1;
      }
  
      if (score[i] === "*") {
        if (isNaN(score[i - 2])) {
          score = score.map((val, index) =>
            index < i && index >= i - 3 && !isNaN(val) ? val * 2 : val
          );
        } else {
          score = score.map((val, index) =>
            index < i && index >= i - 2 && !isNaN(val) ? val * 2 : val
          );
        }
      }
    }
    return score.filter((val) => !isNaN(val)).reduce((acc, cur) => acc + cur, 0);
  }