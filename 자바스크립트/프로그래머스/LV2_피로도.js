function solution(k, dungeons) {
    var answer = -1;

    let visited = Array.from({ length: dungeons.length }, () => false);

    function dfs(pirodo, num) {
        answer = Math.max(answer, num);
        for (let i = 0; i < dungeons.length; i++) {
            if (visited[i] === false && dungeons[i][0] <= pirodo) {
                visited[i] = true;
                dfs(pirodo - dungeons[i][1], num + 1);
                visited[i] = false;
            }
        }
    }
    dfs(k, 0);
    return answer;
}