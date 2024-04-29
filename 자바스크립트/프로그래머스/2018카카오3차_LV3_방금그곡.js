// 앞뒤가 연결된걸수도있음
// 음악을 중간에 끊을경구 원본음악에는 네오가 기억한 멜로디가 그 곡이 아닌걸수도있음
// 기억한 멜로디와 재생시간, 제공된 악보로 직접 비교 

// 음악은 반드시 첨부터
// 음악 길이 < 재생 시간 일시 음악 한번더 재생
// 음악 길이 > 재생시간 재생시간만큼만

// 조건 일치하는 음악이 여러개 일 경우 라디오에 재생된 시간이 제일 긴 음악 제목을 반환.
// 같은경우 먼저 입력된 음악 제목 반환
// 없을경우 "none"


function solution(m, musicinfos) {
  let answer = [];
  
  const arr = [];
  
      const umm = m.split('');
      const m2 = [];
      for (let i = 0; i < umm.length; i++) {
          if (umm[i] === "#") {
              m2[m2.length-1] = m2[m2.length-1] + "#";
          } else {
              m2.push(umm[i]);
          }
      }
  
  musicinfos.forEach((item)=>{
      const music = item.split(',');
      const times = [...music[0].split(":")];
      const startTime = parseInt(times[0]*60) + parseInt(times[1]);
      
      const times2 = [...music[1].split(":")];
      const endTime = parseInt(times2[0]*60) + parseInt(times2[1]);
      
      const um = music[3].split('');
      const arrs = [];
      for (let i = 0; i < um.length; i++) {
          if (um[i] === "#") {
              arrs[arrs.length-1] = arrs[arrs.length-1] + "#";
          } else {
              arrs.push(um[i]);
          }
      }
      let melody = [];
      const timelength = endTime-startTime;
      for(let k = 0; k < (Math.floor(timelength/arrs.length)); k++) {
          melody = [...melody,...arrs];
      }
        for(let k = 0; k < timelength % arrs.length; k++) {
          melody.push(arrs[k]);
      }
      console.log(melody,melody.length);
      console.log(m2,m2.length);
      for(let k = 0; k < melody.length - m2.length+1; k++) {
          for (let j = 0; j < m2.length; j++) {
              if (k+j > melody.length)
                  break;
              if (melody[k+j] !== m2[j]) {
                  break;
              }
              if (j === m2.length-1) {
                  answer.push({song : music[2], len : endTime-startTime, num : answer.length})
                  break;
              }
          }
      }
  })
  if (!answer.length)
      return "(None)";
  answer.sort((a,b)=>b.len-a.len);
  
  return   answer.filter((item)=>answer[0].len === item.len).sort((a,b)=>a.num - b.num)[0].song;
;
}