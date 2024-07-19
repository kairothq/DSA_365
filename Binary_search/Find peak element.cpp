class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        // so here we want peak elements i.e. both the no on its side are shorter than the no
        // kindof same concept as the single element
        // [1,2,3,5,4,3,2,5,4,1]


        // WHAT I DIDN'T ABLE TO NOTICE WAS EVEN IF YOU KEEP CHECKING JUST YOUR NEXT INDEX
        // TO BE MORE THAN YOU THEN ITS A INCREASING CURVE BY ITSELF

        // Also here the edge cases can be dealed seprately and low and high can be start from 
        // one index after the edges 
        int n=nums.size();
        if(n==1) return 0;
        if(nums[0]>nums[1]) return 0;
        if(nums[n-1]>nums[n-2]) return n-1;
        int low=1, high=n-2;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]>nums[mid+1]&& nums[mid]>nums[mid-1]) return mid;
            else if(nums[mid]<=nums[mid+1]) low=mid+1; // means on the increasing side so peak on right
            else high=mid-1;
        } 
        return -1;
    }
};