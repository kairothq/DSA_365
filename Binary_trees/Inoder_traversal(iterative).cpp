/* Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};*/
class Solution {
public:
    vector<int> inOrder(Node* root)
    {
        stack<Node*> s;
        Node* node= root;
        vector<int> ans;
        while(true){// this will keep running until its stopped with a break
            if(node!=NULL ){
                s.push(node);
                node = node-> left;
            }
            else{
                if(s.empty()== true) break;
                node = s.top();
                s.pop();
                ans.push_back(node->data);
                node = node-> right;
            }
        }
        return ans;
    }
};