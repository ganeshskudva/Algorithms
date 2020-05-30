class Solution {
    public int removeDuplicates(int[] nums) {
        Map<Integer, Integer> mp = new TreeMap<>();
        
        for (int i: nums)
            mp.put(i, mp.getOrDefault(i, 0)+1);
        
        int i = 0, cnt = 0;
        for (Integer key: mp.keySet()) {
            Integer val = mp.get(key);
            if (val >= 2) {
                nums[i++] = key;
                nums[i++] = key;
                cnt += 2;
            } else {
                for (int j = 0; j < val; j++, cnt++)
                    nums[i++] = key;
            }
        }
        
        return cnt;
    }
}
