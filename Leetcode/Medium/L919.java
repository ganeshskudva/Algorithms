/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class CBTInserter {

        private TreeNode root = null;
        public CBTInserter(TreeNode root) {
            this.root = root;
        }

        public int insert(int v) {
            Queue<TreeNode> q = new LinkedList<>();
            q.offer(root);
            TreeNode parent = null;
            while (!q.isEmpty()) {
                int size = q.size();
                for (int i = 0; i < size; i++) {
                    TreeNode node = q.poll();

                    if (node.left == null || node.right == null) {
                        if (node.left == null) {
                            node.left = new TreeNode(v);
                        } else {
                            node.right = new TreeNode(v);
                        }

                        parent = node;
                        break;
                    }
                    
                    if (node.left != null)
                        q.offer(node.left);
                    
                    if (node.right != null)
                        q.offer(node.right);
                }
                
                if (parent != null)
                    break;
            }
            
            return parent.val;
        }

        public TreeNode get_root() {
            return this.root;
        }
    }

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter obj = new CBTInserter(root);
 * int param_1 = obj.insert(v);
 * TreeNode param_2 = obj.get_root();
 */
