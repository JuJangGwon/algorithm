function solution(id_pw, db) {
    let result = '';
    
    db.map((item) => {if(id_pw[0] === item[0] && id_pw[1] === item[1]) result = "login"
      else if(id_pw[0] === item[0] && id_pw[1] !== item[1]) result =  "wrong pw"
      else if(id_pw[0] !== item[0] && id_pw[1] !== item[1]) result = "fail"})
      
    return result
  }