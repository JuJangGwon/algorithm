function solution(numbers) {

  const answer = [];
  for(let number of numbers){
      if(number % 2 === 0){ 
          answer.push(number+1)
      } else { 
          const numberBinary = number.toString(2);
          const position = numberBinary.lastIndexOf("0");
          if(position === -1)
              answer.push(parseInt("10"+numberBinary.slice(1), 2));
          else{
              const value = numberBinary.slice(0, position)+"10"+numberBinary.slice(position+2);
              answer.push(parseInt(value, 2));
          }    
      }
  }
  return answer;
}
