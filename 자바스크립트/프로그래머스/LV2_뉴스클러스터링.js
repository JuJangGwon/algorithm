function solution(str1, str2) {
    let tmp1 = [];
    let tmp2 = [];
    let inter = 0;
    
    str1 = str1.toLowerCase();	
    str2 = str2.toLowerCase();

    for(let i=0; i<str1.length-1; i++)
    {
        const str = str1.slice(i,i+2)
        if (/^[a-z]+$/.test(str))
        {
            tmp1.push(str);
        }
    }
  for(let i=0; i<str2.length-1; i++)
    {
        const str = str2.slice(i,i+2)
        if (/^[a-z]+$/.test(str))
        {
            tmp2.push(str);
        }
    }

    for(let i=0; i<tmp1.length; i++)
    {
        const tmp = tmp1[i];
        
        for(let j=0; j<tmp2.length; j++)
        {
            if(tmp === tmp2[j])
            {
                inter ++;
                tmp2[j] = '.';
                break;
            }
        } 
    }
    const union = tmp1.length + tmp2.length - inter;
    return union === inter ? 65536 : Math.floor((inter/union) * 65536);
}