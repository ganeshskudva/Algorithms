class Solution {
    public TreeNode bstFromPreorder(int[] preorder) {
        int n = preorder.length;
    if (n == 0) return null;

    TreeNode root = new TreeNode(preorder[0]);
    Deque<TreeNode> deque = new ArrayDeque<TreeNode>();
    deque.push(root);

    for (int i = 1; i < n; i++) {

      TreeNode node = deque.peek();
      TreeNode child = new TreeNode(preorder[i]);

      while (!deque.isEmpty() && deque.peek().val < child.val)
        node = deque.pop();

      if (node.val < child.val) node.right = child;
      else node.left = child;

      deque.push(child);
    }
    return root;
    }
}
