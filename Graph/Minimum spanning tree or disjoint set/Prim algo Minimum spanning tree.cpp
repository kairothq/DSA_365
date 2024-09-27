{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // wt, node and not storing parent as we just need sum in this question and not where it 
        // came from
        priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> pq;
        int sum=0;
        pq.push({0,0});
        vector<int> vis(V, 0);
        while(!pq.empty()){
            auto it= pq.top();
            pq.pop();
            int node= it.second;
            int wt= it.first;
            
            if(vis[node]==1) continue;
            vis[node]=1;
            sum+=wt;
            for(auto it:adj[node]){
                int adjNode = it[0];
                int edW = it[1];
                if(!vis[adjNode]){ // means check if vis[adjNode] is false, means check if its
                //  not visited yet
                    pq.push({edW, adjNode});
                }
            }
        }
        return sum;
    }
};