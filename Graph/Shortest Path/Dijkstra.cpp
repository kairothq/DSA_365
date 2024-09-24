// also we need to solve one more question where we are calculting the shortest path using dijkstra


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
         // define a priority queue PQ
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        // define a array with all no and infinite value
        vector<int> dist(V, 1e9);
        // then push src element distance, node
        dist[S] = 0;
        pq.push({0,S});
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int dis = it.first;
            int node= it.second; 
            
            for(auto it: adj[node]){
                int adjNode= it[0];
                int edW= it[1];
                if(dis+edW < dist[adjNode])
                {
                    dist[adjNode]=dis+edW;
                    pq.push({dis+edW, adjNode});
                }
            }
        }
        
        return dist;
        // then check neighbour of that node and add the weights to distance of node
        // if that distance < already present distance in array 
        // then push the adj element dist and node in PQ
        // do this until we get last element of min heap
        
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends