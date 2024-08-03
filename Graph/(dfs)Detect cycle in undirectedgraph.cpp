// M-2 DFS
    class Solution{
    private:
    bool dfs(int node, int parent, int vis[], vector<int> adj[]){
        vis[node]=1; // in each dfs call make that node to be visited 
        for(auto adjacentNode: adj[node]){ // traverse through all neighbouring nodes
            if(!vis[adjacentNode]){ 
                if(dfs(adjacentNode, node, vis, adj)==true){ // move to all neighbouring nodes in component
                    return true;
                }
            }
            else if(adjacentNode !=parent) return true; // if already visited then check if not visited by parent then its cycic 
        }
        return false;
    }
    
    
    public: 
    bool isCycle(int V, vector<int> adj[]){
        int vis[V]={0};
         // now this next line need not to be written if there were a single component 
         // here we just visit all nodes once by the starting element of each component 
         // and not check for each component by each of the node in that component 
         for(int i=0; i<V; i++){
             if(!vis[i]){ // this only works when the no is not visiited 
                 if(dfs(i, -1, vis,adj)==true) return true;
             }
         }
        return false; 
        }
    };