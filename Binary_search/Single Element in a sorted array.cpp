class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // 1123344

        // if sorted order is given then try to think on the binary search side 
        // and since gn log(n) TC here then def its binary search 

        // Also we need to make sure to always check the edge cases too like when n=1, n=n-1;  

    // observation is, if we are standing on the single no then on its right the first no appearance is
    // (3,3,4,4,6,7,7,8,8) so here the first 3 on even index and so are all no.s
    // but all elements on its right will have (even, odd) index
    // and this single no will always be at odd place index since all the no before it will be in pair
    // also when standing at single element the both the right and left element will be different 

    int n=nums.size();
    if(n==1){
        return nums[0];
    }
    // this is the trick that since we need to write a lot of edge cases therefore directly take 
    // high and low as 1 no after the edges to save from hassle  
    else if(nums[0]!=nums[1]) return nums[0];
    else if (nums[n-1]!=nums[n-2]) return nums[n-1]; // i.e. we are taking the edge cases seprately
    // And starting the high and low from one no from the edges 

    int low = 1, high = n-2;
    while(low<=high){
       int mid=low+(high-low)/2;
       // now check if atleast one of the element on its sides is same, and eleminate that half where the same type no is present 
       if(nums[mid]!=nums[mid+1]&& nums[mid]!=nums[mid-1]){
        return nums[mid];
       } 
       if ((mid%2==0&& nums[mid]==nums[mid+1])|| (mid%2==1&&nums[mid]==nums[mid-1])){
         low=mid+1;
       }
       else{ // eleminating the right half
        high=mid-1;
       }
    }
    return -1;
    }
};