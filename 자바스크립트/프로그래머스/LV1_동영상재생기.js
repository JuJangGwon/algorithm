function solution(video_len, pos, op_start, op_end, commands) {
  let [videoH, videoM] = video_len.split(":").map(Number);
  const videoLength = videoH * 60 + videoM;

  let [nowTimeH, nowTimeM] = pos.split(":").map(Number);
  let nowTime = nowTimeH * 60 + nowTimeM;
  let [opStartH, opStartM] = op_start.split(":").map(Number);
  let [opEndH, opEndM] = op_end.split(":").map(Number);
  const opStart = opStartH * 60 + opStartM;
  const opEnd = opEndH * 60 + opEndM;

  commands.forEach((item) => {
    if (nowTime >= opStart && nowTime <= opEnd) {
      nowTime = opEnd;
    }
    if (item === "next") {
      nowTime += 10;
      if (nowTime >= videoLength) {
        nowTime = videoLength;
      }
    } else if (item === "prev") {
      nowTime -= 10;
      if (nowTime < 0) {
        nowTime = 0;
      }
    }
  });
  if (nowTime >= opStart && nowTime <= opEnd) {
    nowTime = opEnd;
  }

  let answerHour =
    Math.floor(nowTime / 60) < 10
      ? "0" + Math.floor(nowTime / 60)
      : Math.floor(nowTime / 60);
  let answerMinitue = nowTime % 60 < 10 ? "0" + (nowTime % 60) : nowTime % 60;

  return answerHour + ":" + answerMinitue;
}
