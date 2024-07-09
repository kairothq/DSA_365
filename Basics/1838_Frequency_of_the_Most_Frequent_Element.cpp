class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        long long int maxFreq = 0, l=0, r=0, total=0, n=nums.size();

        for(r=0; r<n; r++){ // to increase the r 
            total += nums[r];

            
            while(l+1<=r && (nums[r]*(r-l+1)) > total+k){ // to shrink the sliding window by increasing the l 
                total-= nums[l];
                l++;
            }
            maxFreq = std:: max(maxFreq, r-l+1);
        }
    return maxFreq;
    }
};
 
// very imp to not define the length outside the while otherwise it will give wrong ans 