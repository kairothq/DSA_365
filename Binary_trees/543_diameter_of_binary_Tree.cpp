class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter=0;
        height(root,diameter);
        return diameter;
    }

    int height(TreeNode* root,int &diameter){
        if(root==NULL) return 0;
        int left= height(root->left,diameter);
        int right= height(root-> right,diameter);
        diameter= max(diameter,left+right);
        return 1+max(left,right);
    }
};


// so common mistake is we think adding the longest path from left and right till root is diameter but diameter could also be a case where the root is not included
// For example its the sum of longer 2 children on the right side

// Therefore to keep a track of them you need to send a variable with main variable which is named as diameter and its updating together with height

// And since we need to return the code of max height and calc diameter with it which we will access in another main funciton