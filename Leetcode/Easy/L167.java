// 167. Two Sum II - Input array is sorted
class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int[] result = new int[2];
        int j = numbers.length - 1;
        for (int i = 0; i < j; ) {
            int sum = numbers[i] + numbers[j];
            if (sum == target) {
                result[0] = i + 1;
                result[1] = j + 1;
                return result;
            }
            if (sum < target) {
                i++;
            }
            if (sum > target) {
                j--;
            }
        }
        return result;
    }
}
