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
    bool checkroot(TreeNode* root, long long min, long long max){
        if(root==NULL) return true;
        if(root->val<=min || root->val >=max) return false;
        return checkroot(root->left, min, root->val) && checkroot(root->right, root->val, max);
    }

    bool isValidBST(TreeNode* root) {
        return checkroot(root, LONG_LONG_MIN, LONG_LONG_MAX);
    }
};