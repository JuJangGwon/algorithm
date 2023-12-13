function solution(m, n, puddles) {
    const pool = [];
    for(let i = 1; i <= n ; i++) pool.push(Array(m).fill(0));
    pool[0][0] = 1;
    puddles.forEach(item => {
        let [x, y] = item;
        pool[y-1][x-1] = -1;
    });
    pool.forEach((arr, y) => {
        arr.forEach((item, x) => {
            if(item !== -1){let n = item + (x > 0 && pool[y][x-1] !== -1 ? pool[y][x-1] : 0) +
                (y > 0 && pool[y-1][x] !== -1 ? pool[y-1][x] : 0);
                        n = n % 1000000007;
                        pool[y][x] = n;}
        })
    });
   return pool[n-1][m-1] % 1000000007;
}