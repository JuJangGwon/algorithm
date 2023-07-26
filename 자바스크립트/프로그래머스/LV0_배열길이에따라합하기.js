function solution(arr, n) {
    if (arr.length % 2 === 0)
    {
        arr.map((item,index)=> index % 2 === 1 ? arr[index] += n : null);
    }
    if (arr.length % 2 === 1)
    {
        arr.map((item,index)=> index % 2 === 0 ? arr[index]  += n : null);
    }
    return arr;
}