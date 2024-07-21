class Solution{

public:
    int floor(Node* root, int x) {
        if(root==NULL) return -1;
        
        int floor=-1;
        while(root){
            if(root->data==x){
                floor=root->data;
                return floor;
            }
            else if(x<root->data){
                root=root->left;
            }
            else{
                floor=root->data;
                root=root->right;
            }
        }
        return floor;
    }
};