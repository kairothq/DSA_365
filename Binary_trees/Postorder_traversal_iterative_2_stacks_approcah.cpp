//m-2 

// so what we are trying to do here is traverse the binary tree poster traversal without the recursion i.e. by iterative
// And for that we be using 2 stacks 


// Pushing elements in the first one and reaching the left mostelement and after we got child in left side to be null
// then popping the top element of first stack, and printing the other side in tree i.e. child node in right side and then printing the popping elemetn  
// and then at end when first stack is empty then print all the elements of stack 2
class Solution {
    public:
    void posthelper(TreeNode* root, vector<int>&ans){
        stack<TreeNode*> s1,s2;  //Here stack elements will hold the pointers to treenode
        // eg if TreeNode* current = root then it means ->// This declares 'current' as a pointer to TreeNode and initializes it with 'root'
        s1.push(root); // so started with pushing the top first in s1 and popped too first before any element 
        while(!s1.empty()){
            TreeNode* node= s1.top(); 
            s1.pop();
            s2.push(node);
            if(node->left!=NULL)  s1.push(node-> left); // pushed this first as in first in and last out 
            if(node-> right!=NULL)  s1.push(node-> right); 
        }
        while(!s2.empty()){
            ans.push_back(s2.top()-> val);
            s2.pop(); // LIFO
        }
    }
    vector<int> postorderTraversal(TreeNode* root) {
            vector<int> ans;
        if(root==NULL) return ans;
        posthelper(root, ans);
        return ans;
    }
};