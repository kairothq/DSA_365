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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
         // if its a empty tree then just return a new node as root
        // so here we need to traverse through the Tree such that no after it and before are bigger and smaller that this 
        // and this can be done in two ways eg right, left. So lets just select one way and move though it 
        if( root==NULL) return new TreeNode(val);
            if(root->val>val){
                root->left = insertIntoBST(root->left, val);
            }
            else{
                root->right = insertIntoBST(root->right, val);
            }
        return root;

    }
};