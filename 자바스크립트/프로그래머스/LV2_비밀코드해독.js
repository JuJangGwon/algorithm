function solution(n, q, ans) {
    var answer = 0;
    const used = Array.from({length :31},()=>false)
    const arr = []
    const dfs = (a,b) =>{
        if(b === 5){
            if(q.every((item,index)=> item.filter((item2)=> arr.includes(item2)).length == ans[index])) {
               answer+=1 
            }
            return ;
        }
        for(let i = a; i <= n; i++){
          if(!used[i]){
              used[i] = true
              arr[b] = i
              dfs(i+1,b+1)
               used[i] = false
          }
        }
    }
    dfs(1,0)
    return answer;
}