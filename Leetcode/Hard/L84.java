class Solution {
   public int largestRectangleArea(int[] heights) {
        if (heights == null || heights.length == 0)
            return 0;

        int[] nsl = NSL(heights), nsr = NSR(heights);
        int max = Integer.MIN_VALUE;

        for (int i = 0; i < heights.length; i++) {
            int area = (nsr[i] - nsl[i] - 1) * heights[i];
            max = Math.max(area, max);
        }

        return max == Integer.MIN_VALUE?0:max;
    }

    private int[] NSL(int[] n) {
        int[] ret = new int[n.length];
        ArrayDeque<Integer> st = new ArrayDeque<>();
        int idx = 1;
        ret[0] = -1;
        st.push(0);

        for (int i = 1; i < n.length; i++) {
            while (!st.isEmpty() && n[st.peek()] >= n[i])
                st.pop();
            if (!st.isEmpty())
                ret[idx++] = st.peek();
            else
                ret[idx++] = -1;
            st.push(i);

        }

        return ret;
    }

    private int[] NSR(int[] n) {
        int[] ret = new int[n.length];
        ArrayDeque<Integer> st = new ArrayDeque<>();
        int idx = n.length - 2;
        ret[n.length - 1] = n.length;
        st.push(n.length - 1);

        for (int i = n.length - 2; i >= 0; i--) {
            while (!st.isEmpty() && n[st.peek()] >= n[i])
                st.pop();
            if (!st.isEmpty())
                ret[idx--] = st.peek();
            else
                ret[idx--] = n.length;
            st.push(i);
        }

        return ret;
    }
}
