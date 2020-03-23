class Solution {
    public int divisorSum(int num){
        int sum = 0;
        int count = 0;
        for(int i=1; i * i <= num; i++){
            int remainder = num % i;
            int divisor = num / i;
            if( remainder == 0){
                if(divisor != i){
                    sum = sum + i + divisor;
                    count += 2;
                }else{
                    sum = sum + i;
                    count += 1;
                }
            }
            if(count > 4) break;
        }
        if(count != 4) sum = 0;
        return sum;
    }
    
    public int sumFourDivisors(int[] nums) {
        int res = 0;
        for(int i=0; i<nums.length; i++){
            res += divisorSum(nums[i]);
        }
        return res;
    }
}
