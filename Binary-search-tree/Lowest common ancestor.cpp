/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // so what we try to do here is find the path to some element and move until 
        // both the elements have same path and as soon as both of them moves to other dirn
        // then that element is LCA, and if one of them moves then also that element itself 
        // is LCA 
        if(root==NULL)  return NULL;
        if(root->val>p->val &&root-> val > q->val) return (lowestCommonAncestor(root->left,p,q));
        else if(root->val<p-> val &&root-> val < q->val) return (lowestCommonAncestor(root->right,p,q));
        return root;
        }
};