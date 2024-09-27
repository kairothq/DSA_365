
class DisjointSet{
    vector<int> parent, size;
public:
    DisjointSet(int n){
    size.resize(n+1,1);  // initialse new nodes with value 1;
    parent.resize(n+1); // by default initilise the new nodes to zero
    for(int i=1;i<n+1;i++){ 
        parent[i]=i;
    } 
    }
    int findUPar(int node){
        if(parent[node]!=node){
            parent[node]=findUPar(parent[node]); // this step is imp for path compression
        }
        return parent[node];
    }
    void unionBySize(int u, int v){
        int rootU=findUPar(u);
        int rootV=findUPar(v);
        if(rootU==rootV){
            return;
        }
        if(rootU!=rootV){
            if(size[rootU]>=size[rootV]){
                parent[rootU]=rootV;
                size[rootV]+=size[rootU];
            }
            else{
                parent[rootV]=rootU;
                size[rootV]+=size[rootU];
            }
        }
    }
    
};


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // I will traverse the adj node of given no
        // then make a new adj node list where first parameter is wt
        // then sort it 
        // then start joining using the disjoint set union
            
        vector<pair<int,pair<int,int>>> edges;
        for(int i=0;i<V;i++){
            int node=i;
            for(auto it: adj[node]){
                int adjNode= it[0];
                int wt=it[1];
                edges.push_back({wt, {node, adjNode}});
            }
        }
        DisjointSedt ds(V);
            sort(edges.begin(),edges.end());
            int mstwt=0;
            for(auto it: edges){
                int wt=it.first;
                int u= it.second.first;
                int v= it.second.second;
                if(ds.findUPar(u)!=ds.findUPar(v)){
                    mstwt+=wt;
                    ds.unionBySize(u,v);
                }
            }
        return mstwt;
        }
};