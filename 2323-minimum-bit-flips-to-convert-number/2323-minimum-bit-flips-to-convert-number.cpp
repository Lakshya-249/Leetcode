class Solution {
public:
    int minBitFlips(int start, int goal) {
        int xorv = (start ^ goal);
        int ans = 0;
        while(xorv>0){
            ans += xorv&1;
            xorv >>= 1;
        }
        return ans;
    }
};