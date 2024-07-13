/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode*root){
        if(root==NULL) return 0;
        int left=maxDepth(root->left);
        int right=maxDepth(root->right);
        return max(left,right)+1;

    }

    bool isBalanced(TreeNode* root) {
        if(root==NULL) return 1;
        int rightDepth = maxDepth(root->left);
        int leftDepth = maxDepth(root->right);
        if(leftDepth-rightDepth>1 || rightDepth-leftDepth>1){
            return false;
        }
        return isBalanced(root->left) && isBalanced(root->right); 
        // this is the recursion step to check further too
        }
};