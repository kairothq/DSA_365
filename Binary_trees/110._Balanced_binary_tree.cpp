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

// this is my method but it takes O(N^2) as it traves the tree twice to first calc height and then to check is this balanced but we can make it of TC-> O(N)
// if we just do both the checking and calc height in one traversal 


class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return checkHeight(root) !=1;
    }

    int checkHeight(TreeNode* root){
     if(root==NULL) return 0;

    int leftHeight= checkHeight(root->left);
    
    if(leftHeight ==-1) return -1; // this also checked whether tree is balanced or not 
    
    int rightHeight= checkHeight(root-> right);

    if(rightHeight==-1) return -1;

    if(abs(leftHeight-rightHeight)>1) return -1;
    return max(leftHeight, rightHeight)+1; 
    }
};