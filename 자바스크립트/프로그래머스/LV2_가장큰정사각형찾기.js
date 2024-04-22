function solution(board)
{
    let maxs = 0;
    
    for (let i = 0; i < board.length; i++) {
        maxs = Math.max(board[i][0], maxs);
    }
    for (let j = 0; j < board[0].length; j++) {
        maxs = Math.max(board[0][j], maxs);
    }
    
    for (let i = 1; i < board.length; i++) {
        for (let j = 1; j < board[0].length; j++) {
            if (board[i][j]=== 1) {
                board[i][j] = Math.min(board[i-1][j-1],board[i-1][j],board[i][j-1]) + 1;
                maxs = Math.max(board[i][j],maxs);
            }
        }
    }
    return maxs * maxs;
}