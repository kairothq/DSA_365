class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low=0,high=nums.size()-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]== target)
                return mid;
            if(nums[low]<=nums[mid]){ // this is the case of unique elements // this means left is sorted
                if(target<=nums[mid]&&target>=nums[low]){ // checking if the element is left half or not 
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
            else{ // right half is sorted 
                if(target>=nums[mid]&&target<=nums[high]){
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }
    }
    return -1;
    }
};