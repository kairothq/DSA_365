class DisjointSet {
    vector<int> parent, size;
    public:
    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    int findUPar(int U){
        if(parent[U]!=U){
            parent[U]=findUPar(parent[U]);
        }
        return parent[U];
    }
    void UnionBySize(int u, int v ){
        int pu=findUPar(u);
        int pv=findUPar(v);

        if(pu==pv) return; // prevent unnecessary unions 

        if(size[pu]<size[pv]){
            parent[pu]=pv;
            size[pv]+=size[pu];
        }   
        else{
            parent[pv]=pu;
            size[pu]+=size[pv];
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1) return -1;
    DisjointSet ds(n);
    for(auto it: connections){
        ds.UnionBySize(it[0], it[1]);
    }

    int components=0;
    for(int i=0;i<n;i++){
        if(ds.findUPar(i)==i){
            components++; // this condn is true for exactly one UP node in each component
        }
    }
    return components-1; // no of operation required to connect those n UP nodes with n-1 connections 

    }
};