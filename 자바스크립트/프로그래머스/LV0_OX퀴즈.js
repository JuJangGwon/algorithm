function solution(quiz) {
    var answer = [];
    
    quiz.map((event)=>{
             lists = event.split(" ");
            let temp;
            if (lists[1] === '-')
            {
                    temp = Number(lists[0]) - Number(lists[2]);
            }
            else if (lists[1] === '+')
            {
                    temp = Number(lists[0]) + Number(lists[2]);
            }
            if(temp === Number(lists[4]))
                answer.push("O");
            else if(temp !== Number(lists[4]))
                answer.push("X");
    });
    return answer;
}