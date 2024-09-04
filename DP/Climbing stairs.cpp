// recursion + memoisation

class Solution {
public:
    int f(int ind, vector<int>& dp){
        if(ind==0) return 1;
        if(ind==-1) return 1;
        int index=0, index2=0;
        if(dp[ind]!=-1) return dp[ind];
        if(ind>0)  index= f(ind-1, dp);
        if(ind>1)  index2=f(ind-2, dp);
        return dp[ind]=index+index2;
    }

    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return f(n,dp);
    }
};


// tabulation
class Solution {
public:
    int climbStairs(int n) {
    vector<int> dp(n+1,-1);
    dp[0]=1;
    dp[1]=1;
    for(int ind=2; ind<=n; ind++){
        dp[ind]=dp[ind-1]+dp[ind-2];
    }
    return dp[n];
    }
};


// space opt 
class Solution {
public:
    int climbStairs(int n) {
        int prev2=1,prev1=1; //initally at 0th and 1st index
        
        for(int i=2;i<=n;i++){
            int curr=prev1+prev2;
            prev2=prev1; //update pointers
            prev1=curr;
        }
        return prev1;
    }
};
