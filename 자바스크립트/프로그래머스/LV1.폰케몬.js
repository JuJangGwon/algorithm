function solution(nums) {
    const s = [...new Set(nums)];

    if (nums.length / 2 > s.length)
        return s.length;
    return nums.length / 2;
}