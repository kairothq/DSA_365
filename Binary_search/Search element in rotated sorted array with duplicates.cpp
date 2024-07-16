class Solution {
public:
    bool search(vector<int>& nums, int target) {
    int low=0,high=nums.size()-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(nums[mid]==target) return true;

        if(nums[low]==nums[mid]&&nums[mid]==nums[high]) {
            low=low+1;
            high=high-1;
            continue; // so this is the only edge case where we don't able to trim down search space
            // therefore what happened is we move one pointer ahead and back in low, high and then
            // check again and continue directly i.e. all the next conditions will not perform
            // but they all will be skipped and next thing will start and check again. 
            // since maybe its like 3 3 1 2 3 3 3 3 3 -> such that even after moving low,high 
            // by one pointers we may still get the same values 
        }
        if(nums[low]<=nums[mid]){ // means left sorted
            if(nums[low]<=target&&nums[mid]>target){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        else{ // means right sorted 
            if(nums[high]>=target&& nums[mid]<target){ // here it should also be not nums[mid]<=target but only nums[mid]<target
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
    }
    return false;;
    }
};