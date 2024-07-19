class Solution {
public:
    int findMin(vector<int>& nums) {
        int low=0, high=nums.size()-1;
        int ans=INT_MAX;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]<=nums[high]){// right half is sorted
                if(nums[mid]<ans){
                    ans=nums[mid];
                }
                high=mid-1;
            }
            else{
                if(nums[low]<ans){
                    ans=nums[low]; // or like ans = min(nums[low],ans);
                }
                low=mid+1;  // if we already saved the least thing from that sorted part in ans
                // then move to another part while elimating this one 
            }
        }
        return ans;
    }
};