const TABLE ={
    "A" : 1,
    "B" : 2,
    "C" : 3,
    "D" : 4,
    "E" : 5,
    "F" : 6,
    "G" : 7,
    "H" : 8,
    "I" : 9,
    "J" : 10,
    "K" : 11,
    "L" : 12,
    "M" : 13,
    "N" : 14,
    "O" : 15,
    "P" : 16,
    "Q" : 17,
    "R" : 18,
    "S" : 19,
    "T" : 20,
    "U" : 21,
    "V" : 22,
    "W" : 23,
    "X" : 24,
    "Y" : 25,
    "Z" : 26,
}

function solution(name) {
    var answer = 0;
    let word = ""
    let c = 0;
    for (let i = 0; i < name.length; i++){
        word +="A"
    }
    let wordList = name.split("").map((item)=>{
        c +=Math.min(Math.abs(TABLE[item]-TABLE["A"]), Math.abs(TABLE[item] - 26 - TABLE["A"]))
        return Math.min(Math.abs(TABLE[item]-TABLE["A"]), Math.abs(TABLE[item] - 26 - TABLE["A"]))
    })
    answer += wordList.length-1;
    for (let i = 0; i < name.length; i++){
        let next = i + 1;
        while (next < wordList.length && wordList[next] === 0){
            next+=1
        }
        answer = Math.min(answer, i * 2 +name.length- next, (name.length - next) * 2 +i)
    }
    
    return c+answer;
}