class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mday = INT_MAX;
        int n = prices.size();
        int ans = -1;
        for(int i=0;i<n;i++){
            mday = min(prices[i],mday);
            ans = max(ans, prices[i]-mday);
        }
        return ans;
    }
};