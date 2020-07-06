class Solution {
    public int findMin(int[] nums) {
          if (nums == null || nums.length == 0)
            return 0;

        if (nums.length == 1)
            return nums[0];

        int lo = 0, high = nums.length -1, mid = 0, n = nums.length;
        while (lo < high) {
            mid = lo + (high - lo)/2;
            if (nums[mid] < nums[high] ) {
                high = mid;
            } else if (nums[mid] > nums[high]){
                lo = (mid+1)%n;
            }

        }

        return nums[lo];
    }
}
