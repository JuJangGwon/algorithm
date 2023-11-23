function checker(filterditem,skill){  
    for(let i = 0; i <filterditem.length; i++)
    {
        if(filterditem[i] !== skill[i])
            return false;
    }
    return true
}

function solution(skill, skill_trees) {
    let answer = 0;
    skill_trees.map((item)=>{
        const filterditem = item.split('').filter((it)=>skill.indexOf(it)!==-1).join('')
       if(checker(filterditem,skill)) answer+=1;
    })
    return answer;
}