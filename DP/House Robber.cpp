class Solution {
public:
//     int f(int ind, vector<int>&nums, vector<int> &dp){
//         if(ind==0) return nums[ind];
//         if(ind<0) return 0;
//         if(dp[ind]!=-1) return dp[ind];
//         int pick= nums[ind]+ f(ind-2, nums, dp); 
//         int notpick = 0 + f(ind-1,nums, dp);

//     return max(pick, notpick);
//     }


//     int rob(vector<int>& nums) {
//         int n =nums.size();
//         vector<int> dp(n, -1);
//     return f(n-1,nums, dp);
//     }
// };

// 

int rob(vector<int>& nums){
    int n=nums.size();
    int prev= nums[0];
    int prev2= 0;
    for(int i=1;i<n;i++){
        int take=nums[i];
        if(i>1) take+= prev2;
        int nottake= 0+ prev;
        int curi=max(take, nottake);
        prev2= prev;
        prev=curi;
    }
    return prev;
}
};