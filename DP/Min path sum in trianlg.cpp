// recursion  by pwn
class Solution {
public:
    int f(int i, int j, vector<vector<int>>& triangle){
        if(i==triangle.size()-1) return triangle[i][j];// base case
        // there's no need to take the base case where i goes out of boundary bcz there's none
        int bottom = f(i+1, j, triangle);
        int right = f(i+1,j+1, triangle);
        return triangle[i][j]+min(bottom, right);
    }


    int minimumTotal(vector<vector<int>>& triangle) {
        return f(0, 0, triangle);
    }
};


/// memoisation

class Solution {
public:
    int f(int i, int j, vector<vector<int>>& triangle, vector<vector<int>>& dp){
        if(i==triangle.size()-1) return triangle[i][j];// base case
        // there's no need to take the base case where i goes out of boundary bcz there's none
        if(dp[i][j]!=-1) return dp[i][j];
        int bottom = f(i+1, j, triangle, dp);
        int right = f(i+1,j+1, triangle, dp);
        return dp[i][j]=triangle[i][j]+min(bottom, right);
    }


    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m=n;
        vector<vector<int>> dp(n, vector<int>(m,-1));
        return f(0, 0, triangle, dp);
    }
};


// tabulation
    // 1
    // 2 3
    // 5 9 6
    // 4 2 8 6
 int minimumTotal(vector<vector<int>>& triangle) {
    int n= triangle.size();
    vector<vector<int>>dp(n, vector<int>(n,0));
    for(int j=0; j<n; j++) dp[n-1][j]=triangle[n-1][j];// defining all base cases, starting from bottom
    
    for(int i= n-2; i>=0;i--) { // already defined the n-1, therefore start with top but i can go till n-2 then
        for(int j=i; j>=0; j--){ // this is defining all the possible values of parameters, since in every row, columnn can max be equal to no of rows
            int left = triangle[i][j] + dp[i+1][j];
            int top = triangle[i][j] + dp[i+1][j+1];
            dp[i][j]= min(left, top);
        }
    }
    return dp[0][0];
 }

// space opt 

class Solution {
public:
 int minimumTotal(vector<vector<int>>& triangle) {
    int n= triangle.size();
    vector<int> front(n,0) , curr(n,0); // front is last row and curr is row above that, so just storing adj rows
    for(int j=0; j<n; j++) front[j]=triangle[n-1][j];// defining base case 
    
    for(int i= n-2; i>=0;i--) {
        for(int j=i; j>=0; j--){ // this is defining all the possible values of parameters
            int left = triangle[i][j] + front[j];
            int top = triangle[i][j] + front[j+1];
            curr[j]= min(left, top);
        }
        front=curr;
    } 
    return front[0];
    }
};



