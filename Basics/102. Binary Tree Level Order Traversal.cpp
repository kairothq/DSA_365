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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root== NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){ // until the queue is not empty i.e. until we don't get all child node as null 
            int size = q.size();  // this is the size we decide once before each for loop ending
            // and its 1 at the start as there is only one root node
            vector<int> level;
            for(int i=0;i<size;i++){ // for loop run for the size 
                TreeNode *node = q.front(); // then we define a node and pop it and add its children to other end
                q.pop();
                if(node->left !=NULL) q.push(node->left);
                if(node->right !=NULL) q.push(node->right);
                level.push_back(node->val); // after all the child of all elements together get pushed in lvl
            }
            ans.push_back(level); // this pushesh that lvl to ans
        }
        return ans; // finally return the ans
    }


// so push items first in queue and then put them in array as vector as levels and remove from the queue 
// and also push their child nodes from left to right in the queue 
};