// 303. Range Sum Query - Immutable
class NumArray {
    List<Integer> lst;
    public NumArray(int[] nums) {
        lst = new ArrayList(nums.length);
        
        if(nums.length > 0) {
        lst.add(nums[0]);
        for (int i=1; i < nums.length; i++) {
            lst.add(lst.get(i-1) + nums[i]);
        }
        }
    }
    
    public int sumRange(int i, int j) {
        
        if (lst.size() == 0)
            return 0;
        else {
        if (i ==0 )
            return lst.get(j);
        else 
            return lst.get(j) - lst.get(i-1);
        }
    }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
