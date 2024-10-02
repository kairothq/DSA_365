// recursion + memoisation 

class Solution {
public:
    int f(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp){
        if(j<0 || j>=matrix[0].size()) return 1e9; // this is also imp that this line comes before the next one i.e. the base case since it checks the out of bound cases 
        if(i==0) return matrix[0][j];
        if (dp[i][j]!=-1) return dp[i][j];
        int u= matrix[i][j]+f(i-1,j, matrix,dp);  
        int ld= matrix[i][j]+ f(i-1,j-1, matrix, dp); // this means it went to left diagnol in opposite, which is this matrix + same kind of recursion i.e. f in left side above therefore f(i-1, j-1, matrix);
        int rd= matrix[i][j]+ f(i-1,j+1, matrix, dp);
        return dp[i][j]=min(u, min(ld, rd));
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int minimum=1e9;
        for(int j=0; j<m; j++){
            minimum = min(minimum, f(n-1, j, matrix,dp));
        }
        return minimum;
    }
};


// tabulation

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n= matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for(int j=0;j<m;j++){
            dp[0][j]=matrix[0][j];
        }
        
        for(int i=1; i<n;i++){
            for(int j=0; j<m; j++){
            int u= matrix[i][j]+ dp[i-1][j];
            int ld=1e9, rd=1e9; // we need to reset these every time these will be the by default edge cases each time next if statement is not satisfied 
            if(j-1>=0) {
                ld= matrix[i][j]+ dp[i-1][j-1];
            }
            if(j+1<m){
                rd= matrix[i][j]+ dp[i-1][j+1];
            } 
            dp[i][j] = min(u, min(ld, rd));
            }
        }

        int minimum=1e9;
        // Find the min value in the last row of dp, which represents the min path sums ending at each cell
        for(int j=0;j<m;j++){
        minimum= min(minimum, dp[n-1][j]);
        }

        return minimum;
    }
};