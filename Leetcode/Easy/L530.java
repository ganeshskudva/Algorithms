class Solution {
    public int getMinimumDifference(TreeNode root) {
        Stack<TreeNode> st = new Stack<>();
        st.push(root);
        TreeNode prev = null;
        int min = Integer.MAX_VALUE;

        while (!st.isEmpty()) {
            TreeNode node = st.pop();
            while (node != null) {
                st.push(node);
                node = node.left;
            }

            if (!st.isEmpty()) {
                node = st.pop();

                if (prev == null)
                    prev = node;
                else {
                    min = Math.min(min, Math.abs(node.val - prev.val));
                    prev = node;
                }
                
                st.push(node.right);

            }
        }
        
        return min;
    }
}
