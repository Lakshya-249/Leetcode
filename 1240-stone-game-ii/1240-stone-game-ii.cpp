class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n,vector<int>(n));
        vector<int> suffixSum = piles;
        for(int i=n-2;i>=0;i--) suffixSum[i] += suffixSum[i+1];
        return maxStones(suffixSum,1,0,dp);
    }

    int maxStones(vector<int>& suffixSum,int m,int ind,vector<vector<int>>& dp){
        if(ind + 2*m >= suffixSum.size()) return suffixSum[ind];
        if(dp[ind][m] != 0) return dp[ind][m];
        int ans = INT_MAX;
        for(int i=1;i<=2*m;i++){
            ans = min(ans, maxStones(suffixSum,max(i,m),ind+i,dp));
        } 
        dp[ind][m] = suffixSum[ind] - ans;
        return dp[ind][m];
    }
};