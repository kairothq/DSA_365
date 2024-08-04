class Solution {
private: 
    void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>>& board, int delrow[], int delcol[], int N, int M)
    {
        vis[row][col]=1;

        
    // check for top, right, bottom, left
    for(int i=0;i<4;i++){
        int nrow=row+ delrow[i];
        int ncol=col+ delcol[i];
        if(nrow>=0&&nrow<N&&ncol>=0&&ncol<M&&board[nrow][ncol]=='O'&&!vis[nrow][ncol]){
            dfs(nrow,ncol, vis, board, delrow, delcol,N, M);
        }
    }

    }

public:
    void solve(vector<vector<char>>& board) {
        int N=board.size();
        int M=board[0].size();
        int V=N*M;
        vector<vector<int>> vis(N, vector<int>(M,0));

        int delrow[]= {-1,0,1,0};
        int delcol[]= {0,1,0,-1};

        for(int j=0; j<M;j++){
            // first row
            if(!vis[0][j]&& board[0][j]=='O'){
                dfs(0,j,vis,board,delrow, delcol, N, M);
            }
            // last row
            if(!vis[N-1][j]&& board[N-1][j]=='O'){
                dfs(N-1,j,vis,board,delrow, delcol, N, M);
            }
        }
        for(int i=0;i<N;i++){
            // first column
            if(!vis[i][0]&&board[i][0]=='O'){
                dfs(i, 0, vis, board,delrow, delcol, N, M);
            }
            // last column
            if(!vis[i][M-1]&&board[i][M-1]=='O'){
                dfs(i,M-1, vis, board,delrow, delcol, N, M);   
            }
        }

        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(!vis[i][j]&& board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
    }
};