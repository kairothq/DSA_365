// Memoisation and normal recursive method 

class Solution {
public:

    int f(int i, int j, vector<vector<int>> &dp){
        if(i==0 && j==0) return 1;
        if(i<0|| j<0) return 0;
        if(dp[i][j] !=-1) return dp[i][j];
        int up= f(i-1, j, dp);
        int left = f(i, j-1, dp);
        return dp[i][j]=up+left; 
    }


    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n,-1)); // declaring the 2D array here 
        return f(m-1, n-1, dp);
    }
};


// Tabulation here 
class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[m][n];
        for(int i=0; i<m;i++){
            for(int j=0; j<n;j++){
                if(i==0 & j==0) dp[i][j]=1; // since there is only one way to reach 0,0
                else{
                    int up=0; // this is making sure that if it is in the top row or maybe in the left most row i.e. these cell don't have a way from where the element comes from therefore we need to check that element is not here since then it will don't have any up or left
                    int left=0; // Also reseting it in every iteration won't cause any problem since we need to store up, left new for each iteratoin
                    if(i>0) up= dp[i-1][j]; // // this is making sure that if it is in the top row or
                    // maybe in the left most row i.e. these cell don't have a way from where the element comes 
                    // from therefore we need to check that element is not here since then it will don't have any up or left
                    if(j>0) left = dp[i][j-1]; // And what this up or left store is no of ways to reach upto the upper cell or left cell
                    dp[i][j]= up+left; // this store the no of ways to reach this cell since it can only come from left or up cell to this 
                }
            }
        }
        return dp[m-1][n-1];
    }
};


// Finally space optimistion 
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> prev(n,0);
        for(int i=0; i<m;i++){
            vector<int> curr(n,0); // current row
            for(int j=0; j<n;j++){
                if(i==0 & j==0) curr[j]=1;
                else{
                    int up=0;
                    int left=0;
                    if(i>0) up= prev[j];
                    if(j>0) left = curr[j-1];
                    curr[j]= up+left;
                }
            }
            prev = curr;
        }
        return prev[n-1];
    }
};


