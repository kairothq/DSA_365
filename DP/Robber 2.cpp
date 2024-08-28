class Solution {
public:
    int help(vector<int>& nums){
    int n=nums.size();
    int prev= nums[0];
    int prev2= 0;
    for(int i=1;i<n;i++){
        int take=nums[i];
        if(i>1) take+= prev2;
        int nottake= 0+ prev;
        int curi=max(take, nottake);
        prev2= prev;
        prev=curi;
    }
    return prev;
}

long long rob(vector<int>& valueInHouse) {
        vector<int> temp1, temp2;
         int n= valueInHouse.size();
         if(n==1) return valueInHouse[0]; // i.e when there's only one element
         for(int i=0; i<n; i++){
            if(i!=0) temp1.push_back(valueInHouse[i]);
            if(i!=n-1) temp2.push_back(valueInHouse[i]); // make 2 array, one where only last element is excluded and apply the robber logic on left part
         }
        
        return max(help(temp1), help(temp2));
    }
};