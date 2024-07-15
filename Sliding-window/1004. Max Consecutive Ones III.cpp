class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0,r=0;
        int len=0;
        int n = nums.size();
        int zeros=0;
        while(r<n){
            if(nums[r]==0){
                zeros++;
            }
                while(zeros>k){
                    if(nums[l]==0){
                        zeros--;
                    }
                    l++;
                }
                len = max(len, r-l+1);
                r++;
        }
        return len;
    }
};


// so what we want to do here is find max no of 1's and that will be stopped if there 0 in b/w

// flip atmostmost k 0's 
