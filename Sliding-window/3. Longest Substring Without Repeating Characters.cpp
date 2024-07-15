class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int right =0, left=0;
        int n = s.size();
        int len=0;
        vector<int> mpp(256,-1);
        while(right<n){
            if(mpp[s[right]]!=-1) { // means its present in the map 
                // and we check whether it exist in map for >l, means its present in current substring
                // so if its present in current substring then move l to no just 1 greater than that
                // and if not present then just update the map value to current l 
                left = max(left, mpp[s[right]]+1); // here comparing l and the value of s[r] in map
                // eg if cadbeam and moving through this string then when it goes to other a 
                // then will try to move the left from c to d and not a in b/w since keeping the a before m in substring
                // but if acabmct when moving through this then when reach c then keep the left at a itself 
                // i.e. l is updated to max of current l or position of that no in map if its repeating 
                // and since here we consider the index of c to be 2nd place which is mpp[s[right]]
                }  
                mpp[s[right]] = right;
                len = max(len, right-left+1);
                right ++;
            }
            return len;
        }
};