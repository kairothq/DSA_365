// m-1 Recurrsion and memoisation

class Solution {
public:

    int f(int i, int j, vector<vector<int>>& obstacleGrid,vector<vector<int>>&dp ){
        if(i>=0 && j>=0 && obstacleGrid[i][j]==1) return 0;
        if(i==0 && j==0) return 1;
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1 ) return dp[i][j];
        int up = f(i-1,j, obstacleGrid, dp);
        int left = f(i,j-1, obstacleGrid, dp);
        return dp[i][j]=up+left;
    }


    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        vector<vector<int>> dp(n, vector<int>(m,-1));
        return f(n-1,m-1, obstacleGrid, dp);
    }
};



//m-2 Tabulation

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        int dp[n][m];
        for(int i=0; i<n;i++){
            for(int j=0; j<m;j++){
                if(obstacleGrid[i][j]==1) dp[i][j]=0;
                else if(i==0 && j==0) dp[i][j]=1;
                else {
                    int up =0,left =0; // initialising this is also v imp 
                    if(i>0) up=dp[i-1][j];
                    if(j>0) left=dp[i][j-1]; // this is also imp to get values from dp rather than obstacleGrid[i][j-1]
                    dp[i][j]= up+left;
                }
            }
        }
        return dp[n-1] [m-1];
    }
};

// m-3 Space Optimisation 

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        vector<int> prev(m,0); // initialising as one row rather than defining a matrix
        vector<int> curr(m,0);
        for(int i=0; i<n;i++){
            for(int j=0; j<m;j++){
                if(obstacleGrid[i][j]==1) curr[j]=0; // changing all dp[i] to curr
                else if(i==0 && j==0) curr[j]=1;
                else {
                    int up =0,left =0; // initialising this is also v imp 
                    if(i>0) up=prev[j];
                    if(j>0) left=curr[j-1]; // changing all dp[i-1] to prev and all dp[i] to curr
                    curr[j]= up+left;
                }
            }
            prev=curr;
        }
        return  prev[m-1];
    }
};