class Solution {
public:
    double myPow(double x, int n) {
        if(x == 1|| n==0) return 1;
        double val = 1;
        int m = abs(n);
        while(m>0){
            if(m%2 == 1){
                val *= x;
            }
            x *= x;
            m /= 2;
        }
        if(n<0) val = 1/val;
        return val;
    }
};