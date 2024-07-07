class Solution {
public:
    int reverse(int x) {
        string y = to_string(x);
        if(y[0]== '-'){
            std::reverse(y.begin()+1,y.end());
            
        }
        else{
        std:: reverse(y.begin(),y.end());
        }
        long long z = stoi(y); // Use long long to handle overflow cases
        
        if (z > INT_MAX || z < INT_MIN) { // this case is for keeping it under 32 bit case
            return 0;
        }
        return z;   
    }
};