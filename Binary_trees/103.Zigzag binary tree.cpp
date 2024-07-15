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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        // so if we push in stack 
        // 3, then pop
        // 9, 20 . 20 pop and its chilren push 15, 7 and , 9 pop and then its children nothing.
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        if (root==NULL) return ans;
        q.push(root);
        bool lefttoRight= true; // flag
        while(!q.empty()){
            int size= q.size();
            vector<int> level;
        for(int i=0;i<size; i++){
            TreeNode* node = q.front();
            q.pop();
            if(node->left!=NULL) q.push(node->left);
            if(node->right!=NULL) q.push(node->right);
            level.push_back(node->val);
        }
        if(!lefttoRight){
            reverse(level.begin(),level.end());
        }
        ans.push_back(level);
        lefttoRight=!lefttoRight; //toggled direction
        }
        return ans;
    }
};