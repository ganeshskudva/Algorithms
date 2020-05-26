class Solution {
 public int maxSubArrayLen(int[] nums, int k) {
        if (nums == null || nums.length == 0)
            return 0;
        int n = nums.length;
        for (int i = 1; i < n; i++)
            nums[i] += nums[i - 1];
        Map<Integer, Integer> map = new HashMap<>();
        map.put(0, -1); // add this fake entry to make sum from 0 to j consistent
        int max = 0;
        for (int i = 0; i < n; i++) {
            if (map.containsKey(nums[i] - k))
                max = Math.max(max, i - map.get(nums[i] - k));
            if (!map.containsKey(nums[i])) // keep only 1st duplicate as we want first index as left as possible
                map.put(nums[i], i);
        }
        return max;
    }
}
