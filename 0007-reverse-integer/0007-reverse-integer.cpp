class Solution {
public:
    int reverse(int x) {
        long long ans = 0;
        while(x!=0){
            if((ans>INT_MAX) || (ans<INT_MIN)) return 0;
            ans += (x%10);
            ans *= 10;
            x = x/10;
        }
        return ans/10;
    }
};