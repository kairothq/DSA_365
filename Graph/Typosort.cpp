class Solution
{
    private: 
    void dfs(int node, stack<int>& st, int vis[], vector<int> adj[]){
        vis [node]=1;
        for(auto it: adj[node]){
            if(!vis[it]) dfs(it, st, vis, adj);
        }
        st.push(node);
    }
	
	
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    int vis[V]={0};// this is defining a array of V elements to be 0
	    stack<int> st;
	    for(int i=0; i<V; i++){
	        if(!vis[i]){
	            dfs(i, st, vis, adj);
	        }
	    }
	   
	    vector<int> ans; // this is defining a single vector variable
	    while(!st.empty()){
	        ans.push_back(st.top());
	        st.pop();
	    }
	    return ans;
	    
	}
};