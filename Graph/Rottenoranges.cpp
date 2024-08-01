class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int N=grid.size();
        int M=grid[0].size();
        int vis[N][M];
        int cntFresh=0;
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }
                else{
                    vis[i][j]=0;
                }
                if(grid[i][j]==1) cntFresh++;
            }
        }
        int tm= 0;
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1}; // making array
        int cnt=0;

        while(!q.empty()){
            int r= q.front().first.first;
            int c= q.front().first.second;
            int t=q.front().second;
            tm = max(tm, t);
            q.pop();
            
            // checking the 4 neighbours
            for(int i=0; i<4; i++){
//       neighbouring row, column no by adding the delat in the r,c
            int nrow= r+drow[i];
            int ncol= c+dcol[i]; 
        
            // checking if the given row and column are even valid at that point in for loop for that no
            if(nrow>=0 && nrow<N && ncol>=0&& ncol<M && vis[nrow][ncol]==0 && grid[nrow][ncol]==1){
                q.push({{nrow,ncol},t+1});
                vis[nrow][ncol]=2;
                cnt++;
            }
            }
        }
    
    if(cntFresh!=cnt) return -1;
    
    return tm;
    }
};