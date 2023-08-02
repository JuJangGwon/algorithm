function solution(phoneBook) {
    var result = true;
     for(var idx in phoneBook){
         var phone = phoneBook[idx];
     for (var idx2 in phoneBook){
         if(idx2 !== idx && phone.indexOf(phoneBook[idx2]) === 0)
             result = false;
     }
         }
 
     return result;
 }