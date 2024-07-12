class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> st1;
        vector<int> postorder;
        if(root == NULL) return postorder;
        st1.push(root);
        while(!st1.empty())
        {
            root = st1.top();
            st1.pop();
            postorder.push_back(root->val);
            if(root->left != NULL)
            {
                st1.push(root->left);
            }
            if(root->right != NULL)
            {
                st1.push(root->right);
            }
        }
        reverse(postorder.begin(),postorder.end());
        return postorder;
    }