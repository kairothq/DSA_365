class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        // trying to follow bfs here by replicating the main mat to visited matrix and then 
        int N=mat.size(); // row
        int M= mat[0].size(); // column
        vector<vector<int>> vis(N, vector<int>(M,0));// initialised the matrix with 0 elements 
        vector<vector<int>> dist(N, vector<int>(M,0)); 
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
                else{
                    vis[i][j]=0;
                }
            }
        }
    int delrow[]= {-1,0,+1,0};
    int delcol[]= {0,+1,0,-1};

    while(!q.empty()){
        int row= q.front().first.first;
        int col= q.front().first.second;

        int steps= q.front().second;
        q.pop();
        dist[row][col]=steps;

        for(int i=0;i<4;i++){
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];

            if(nrow>=0&& nrow<N&& ncol>=0&& ncol<M&& vis[nrow][ncol]==0){ // not already visited
                vis[nrow][ncol]=1;
                q.push({{nrow,ncol}, steps+1});
            }
        }
    }
    return dist;
    }
};