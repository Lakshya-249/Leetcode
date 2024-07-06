class Solution {
public:
    int passThePillow(int n, int time) {
        int ans = time/(n-1);
        if(ans%2 == 0) return time%(n-1) + 1;
        return n - time%(n-1);
    }
};