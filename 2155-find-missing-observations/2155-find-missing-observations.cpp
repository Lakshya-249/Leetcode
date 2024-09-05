class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int k = m+n;
        int total = k*mean;
        int rollSum = accumulate(rolls.begin(),rolls.end(),0);
        int nSum = total - rollSum;
        if(nSum > 6*n || nSum < n) return {};
        int dist = nSum/n;
        int mod = nSum%n;

        vector<int> ans(n,dist);
        for(int i=0;i<mod;i++) ans[i]++;
        return ans;
    }
};