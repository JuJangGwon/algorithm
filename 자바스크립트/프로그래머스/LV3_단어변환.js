function solution(begin, target, words) {
    const queue = [];
    const visited = new Set();
    queue.push({ word: begin, num: 0 });

    if (!words.includes(target)) return 0;

    while (queue.length) {
        const { word, num } = queue.shift();

        if (word === target) return num;

        for (let i = 0; i < words.length; i++) {
            if (!visited.has(words[i]) && isOneCharDiff(word, words[i])) {
                visited.add(words[i]);
                queue.push({ word: words[i], num: num + 1 });
            }
        }
    }

    return 0;
}

function isOneCharDiff(word1, word2) {
    let diffCount = 0;
    for (let i = 0; i < word1.length; i++) {
        if (word1[i] !== word2[i]) {
            diffCount++;
            if (diffCount > 1) return false;
        }
    }
    return diffCount === 1;
}
