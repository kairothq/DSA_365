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


// M-2

class Solution {
public:
    int reverse(int x) {
        int r =0;
        while(x!=0){
            if(r>INT_MAX/10 || r<INT_MIN/10){ // here its very important to also do INT_MIN,MAX/10 because it makes sure to not overflow before the updation of r 
                return 0;
            }
            r= r*10+ x%10; // it also covers the negative cases
            x/=10;
        }
        return r;
        }
};

//-5277 /10 = -527 /10 = -52/10 = -5/10,,, -527%10= -7 
// 