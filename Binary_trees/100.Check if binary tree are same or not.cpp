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
    void preorder(TreeNode* m, vector<int>&ans){
        if(m==NULL){
            ans.push_back(INT_MIN);
            return;
        } 
        ans.push_back(m->val);
        preorder(m->left, ans);
        preorder(m->right, ans);
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int>ans1;
        vector<int>ans2;
        preorder(p, ans1);
        preorder(q, ans2);
        if(ans1.size()!=ans2.size()) return false;
        for(int i=0; i<ans1.size(); i++){
            if(ans1[i]!=ans2[i]) return false;
        }
        return true;
    }
};

// so what we need to do is print recursively i.e. root->left and right and when 