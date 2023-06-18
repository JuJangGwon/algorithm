function solution(lottos, win_nums) {
    var answer = [];
    let zero = lottos.filter(e=>e===0).length;
    let mins = 0;
    for (let i = 0; i < 6; i++)
    {
        if (lottos.find(e => e===win_nums[i]))
            mins++;
    }
    let max = (zero + mins) > 1 ? 7 - (zero + mins) : 6;
    mins =  mins > 1 ? 7 - mins : 6;
    return [max,mins];
}