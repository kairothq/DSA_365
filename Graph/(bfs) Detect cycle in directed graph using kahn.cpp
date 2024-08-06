
    public: 
    bool isCyclic(int V, vector<int> adj[]){
        int indegree[V]={0};
        // this is how we made a indegree array
        for(int i=0; i<V; i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }
        queue<int> q;
        for(int i=0; i<V; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        // vector<int> topo;  rather than this just store a counter
        int cnt=0;
        while(!q.empty()){
            int node =q.front();
            q.pop();
            // topo.push_back(node);
            cnt++;
            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        if(cnt == V) return false;
        return true;
    }
};