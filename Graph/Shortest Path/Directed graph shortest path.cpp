// m-1 this is using normal method as we did for undirected graph

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        vector<vector<pair<int,int>>> adj(N); // need to use pair word when want to store a pair 
        for(auto it: edges){
            adj[it[0]].push_back({it[1],it[2]});
            }
        
        queue<int> q;
        q.push(0);
        vector<int> dist(N,1e9);
        dist[0]=0;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it: adj[node]){
                if(dist[it.first]>dist[node]+it.second){
                dist[it.first]=dist[node]+it.second;
                q.push(it.first); /// this thing of using first rather than it[1] here could v imp SM (silly mistake)
                }
            }
        }
        
        vector<int> ans(N);
        for(int i=0;i<N;i++){
            if(dist[i]==1e9){
                ans[i]=-1;
            }
            else{
                ans[i]=dist[i];
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends



// m-2 