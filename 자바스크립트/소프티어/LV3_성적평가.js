const fs = require("fs");
const scoresGroup = fs
  .readFileSync("input.txt", "utf8")
  .trim()
  .split("\n")
  .slice(1)
  .map((v) => v.split(" ").map((v, i) => [i, +v]));
const number = scoresGroup[0].length;

const totalScores = [];
for (let index = 0; index < number; index++) {
  let sum = 0;
  scoresGroup.forEach((scores) => {
    sum += scores[index][1];
  });
  totalScores.push([index, sum]);
}
scoresGroup.push(totalScores);
const sortedScoresGroup = scoresGroup.map((scores) =>
  scores.sort((a, b) => b[1] - a[1])
);
const result = [];

sortedScoresGroup.forEach((scores) => {
  let prevRank = undefined;
  let prevScore = undefined;
  const rankList = Array.from({ length: number });

  scores.forEach((index_score, rank) => {
    const [index, score] = index_score;
    if (prevScore !== undefined && prevScore === score) {
      rankList[index] = prevRank;
    } else {
      rankList[index] = rank + 1;
      prevScore = score;
      prevRank = rank + 1;
    }
  });
  result.push(rankList);
});

console.log(result.map((v) => v.join(" ")).join("\n"));
