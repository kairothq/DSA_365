// m-1 iterative

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;
        while(l<=r){
            int mid = (l+r)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]<target)  l=mid+1;
            else r=mid-1;
            }
        return -1;
    }
};


// m-2 recursive


class Solution {
public:
    int bs(vector<int>&nums, int low, int high, int target){
    if(low>high) return -1; // base case

    int mid = (low+high)/2;
    if(nums[mid]==target) return mid;
    else if(nums[mid]<target) return bs(nums, mid+1,high , target);
    else return bs(nums, low, mid-1, target);
    }

    int search(vector<int>& nums, int target) {
        return bs(nums,0,nums.size()-1,target);
    }
};