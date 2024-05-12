function solution(wallpaper) {
  var answer = [];  
  const dir = [51,51,0,0];
  wallpaper = wallpaper.map((item)=>{
      return item.split(''); 
  })
  for(let i = 0; i < wallpaper.length; i++) {
      for(let j = 0; j< wallpaper[0].length;j++) {
          if (wallpaper[i][j] === '#') {
              dir[0] = Math.min(dir[0],i);
              dir[1] = Math.min(dir[1],j);
              dir[2] = Math.max(dir[2],i + 1);
              dir[3] = Math.max(dir[3],j + 1);
          }
      }
  } 
  return dir;
}