class Solution {

        int[] orig;
        int size;
        public Solution(int[] nums) {
            orig = nums;
            size = orig.length;
        }

        /** Resets the array to its original configuration and return it. */
        public int[] reset() {
            return orig;
        }

        /** Returns a random shuffling of the array. */
        public int[] shuffle() {
            Random rand = new Random();
            int[] resp = new int[size];
            Set<Integer> st = new HashSet<>();

            for (int i = 0; i < size; i++) {
                int val = rand.nextInt(size);
                while (st.contains(val))
                    val = rand.nextInt(size);
                st.add(val);
                resp[i] = orig[val];
            }

            return resp;
        }
    }

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int[] param_1 = obj.reset();
 * int[] param_2 = obj.shuffle();
 */
