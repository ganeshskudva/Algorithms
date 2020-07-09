class Solution {
    public int validSubarrays(int[] nums) {
        Stack<Integer> stack = new Stack<>();
	int count = 0;
	for (int num: nums) {
		while (!stack.isEmpty() && stack.peek() > num) {
			stack.pop();
		}
		stack.add(num);
		count += stack.size();
	}
	return count;
    }
}
