function solution(survey, choices) {
  var answer = "";
  const personalityType = new Map();
  personalityType.set("R", 0);
  personalityType.set("T", 0);
  personalityType.set("C", 0);
  personalityType.set("F", 0);
  personalityType.set("J", 0);
  personalityType.set("M", 0);
  personalityType.set("A", 0);
  personalityType.set("N", 0);

  survey.forEach((item, index) => {
    const personalitys = item.split("");
    const result = choices[index] - 4;
    if (result < 0) {
      personalityType.set(
        personalitys[0],
        personalityType.get(personalitys[0]) + Math.abs(result)
      );
    } else if (result > 0) {
      personalityType.set(
        personalitys[1],
        personalityType.get(personalitys[1]) + Math.abs(result)
      );
    }
  });

  if (personalityType.get("R") < personalityType.get("T")) {
    answer += "T";
  } else {
    answer += "R";
  }
  if (personalityType.get("C") < personalityType.get("F")) {
    answer += "F";
  } else {
    answer += "C";
  }
  if (personalityType.get("J") < personalityType.get("M")) {
    answer += "M";
  } else {
    answer += "J";
  }
  if (personalityType.get("A") < personalityType.get("N")) {
    answer += "N";
  } else {
    answer += "A";
  }
  return answer;
}
