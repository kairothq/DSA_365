class Solution {
  public:
    // Function to find floor of x
    // n: size of vector
    // x: element whose floor is to find
    int findFloor(vector<long long> v, long long n, long long x) {
        int low=0;
        int high=n-1;
        int ans= -1;
        while(low<=high){
            int mid=low+ (high-low)/2;
            if(v[mid]==x) return mid;
            else if(v[mid]>x) high=mid-1;
            else {
                ans=mid;
                low=mid+1; 
            }
// so we want to find largest no which is less than or equal to that no
        }
        return ans;
    }
};


// even little code like this caused a lot of problem


