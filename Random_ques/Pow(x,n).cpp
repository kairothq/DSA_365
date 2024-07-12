class Solution {
public:

    double y=1;
    double myPow(double x, int n) {
        if(n==1) return x;
        if(n==0) return 1;
        if(n==-1) return 1/x;
        double half = pow(x, n/2);
        if(n%2==0) {
            return half* half;
        }
        else{
            if(n>0){
                return half*half*x;
            }
            else{
                return half*half*1/x; //
            }
        }
    }
};

// 2^27 --> 2*half*half; which is 27/2 = 13 
// 2^-27 --> 1/2^27 --> but it will do 1/2^13*2^13 therefore also multiply by 1/2