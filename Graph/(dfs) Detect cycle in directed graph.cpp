//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private: 
    bool detect(int node,int pathvis[], vector<int> adj[], int vis[]){
        vis[node]=1;
        pathvis[node]=1;
        
        // traverse for adjacent nodes
        for(auto it : adj[node]){
            // when the node is not visited 
            if(!vis[it]){
                if(detect(it, pathvis, adj, vis)) return true;
            }
            // when the node is visited but needs to be visited on same path
            else if (pathvis[it]) return true;
        }
        pathvis[node]=0;
        return false;
    }
    
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // main difference from undirected graph with this is 
        // make a visited array and then if some node is visited and not a part of parent node then its a cyclic graph
        int vis[V]={0};
        int pathvis[V]={0};
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(detect(i,pathvis,adj,vis)==true) return true;
            }
            
        }
        return false;
        }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends