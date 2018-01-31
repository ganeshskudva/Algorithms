//https://www.interviewbit.com/problems/identical-binary-trees/

int checkSimilarTree(TreeNode* A, TreeNode* B)
{
  if (!A && !B)
  {
    return 1;
  }
  
  if (!A || !B)
  {
    return 0;
  }
  
  if (A->val == B->val)
  {
    return checkSimilarTree(A->left, B->left) && 
    checkSimilarTree(A->right, B->right);
  }
  
  return 0;
}

int Solution::isSameTree(TreeNode* A, TreeNode* B) {
  
  return checkSimilarTree(A, B);
  
}
