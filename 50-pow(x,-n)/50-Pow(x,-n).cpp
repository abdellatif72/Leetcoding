class Solution {
public:
    double myPow(double x, int n) {
        double ret = 1;
        if(n==0) return ret;
        
        bool inv = false;
        if(n<0) inv = true;
        
        while(n!=0){
            if(n&1){
                ret *= x;
                if(n<0) n++;
                else n--;
            } else {
                x=x*x;
                n = (n>>1);
            }
        }


        if(inv) ret = 1/ret;
    
        return ret;
    }
};