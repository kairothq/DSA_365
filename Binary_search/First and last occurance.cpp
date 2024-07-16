class Solution {
public:

    int firstOccurance(vector<int>&nums, int target){
        int n= nums.size();
        int low=0, high=n-1;
        int first =-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==target) {
                first=mid;
                high=mid-1;
            }
            else if(nums[mid]>target){
                    high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return first;
    }

    int lastOccurance(vector<int>&nums, int target){
        int n=nums.size();
        int low=0, high=n-1;
        int last=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(target==nums[mid]) {
                last=mid;
                low=mid+1;
            }
            else if (nums[mid]<target){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
    return last;
    }


    vector<int> searchRange(vector<int>& nums, int target) {
        int x= firstOccurance(nums,target);
        if(x==-1) return {-1,-1}; // even here it is very important to write(x==-1 rather than x=-1 if checking)
        int y= lastOccurance(nums,target);
        return {x,y};
    }
};



// this can also be done through direct lower and upper bound but lower bound also return values for no which doesn't exist so we need to change the 
// condition inside lower bound for that and thats all 
// in upper bound we need to return a no less than that since finding the last occurance and not the no after it 