class Solution {
    int sum;
    int[] map;
    public int pathSum(int[] nums) {
        map = new int[67];
        Arrays.fill(map, -1);
        sum = 0;
        for (int num : nums)
            map[num / 10] = num % 10;
        traverse(nums[0] / 10, 0);
        return sum;
    }
    public void traverse(int pos, int preSum){
        int level = pos / 10;
        int idx = pos % 10;
        int right = (level + 1) * 10 + idx * 2;
        int left = right - 1;
        preSum += map[pos];
        if (map[left] == -1 && map[right] == -1) {
            sum += preSum;
            return;
        }
        if (map[left] >= 0) 
            traverse(left, preSum);
        if (map[right] >= 0)
            traverse(right, preSum);
    }
}
