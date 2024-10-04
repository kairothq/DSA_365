// recursion and memoisation

class Solution {
  public:
  
    int f(int i, int j, int k, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp){
        if(j<0 || j>=grid[0].size() || k<0 || k>=grid[0].size()) return -1e8;
        if(i==grid.size()-1) return j==k ? grid[i][j] : grid[i][j] + grid[i][k]; // this means two if loops inside each other and then if and else loop like these
        if (dp[i][j][k]!=-1) return dp[i][j][k];
        int maximum = -1e9;
        for(int l=-1;l<=1;l++){
            for(int m=-1;m<=1;m++){
                if(j+l >= 0 && j+l < grid[0].size() && k+m >= 0 && k+m < grid[0].size()){ //check if new positions are within the boundary
                    int curr = (j == k) ? grid[i][j] : grid[i][j] + grid[i][k];
                    int val = f(i+1, j+l, k+m, grid, dp);
                    maximum = max(maximum, curr + val);
        }
        }
    }
    return dp[i][j][k]=maximum;
    }
    
    int solve(int n, int m, vector<vector<int>>& grid) {
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m,vector<int>(m,-1)));
        int maximum = -1e9;
        return f(0,0,m-1, grid, dp);
    }
};


// tabulation

class Solution {
  public:
    int solve(int n, int m, vector<vector<int>>& grid) {
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m,0)));
        for(int j=0; j<m; j++){ // writing the base cases here
            for(int k=0; k<m; k++){
                if (j==k) dp[n-1][j][k]= grid[n-1][j];
                else dp[n-1][j][k]= grid[n-1][j]+grid[n-1][k];
            }
        }
        
        for(int i=n-2; i>=0; i--){
            for(int j=0; j<m; j++){
                for(int k=0;k<m; k++){
                    int maximum = -1e9;
                    for(int l=-1;l<=1;l++){
                        for(int m=-1;m<=1;m++){
                            if(j+l >= 0 && j+l < grid[0].size() && k+m >= 0 && k+m < grid[0].size()){ //check if new positions are within the boundary
                                int curr = (j == k) ? grid[i][j] : grid[i][j] + grid[i][k];
                                int val = dp[i+1][j+l][k+m];
                                maximum = max(maximum, curr + val);
                            }
                        }
                    }
                    dp[i][j][k]=maximum;
                }
            }
        }
        return dp[0][0][m-1];
    }
};

