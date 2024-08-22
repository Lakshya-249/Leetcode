class Solution {
    string removeDuplicates(string s){
        string ans = "";
        int i = 0;
        while(i<s.size()){
            char c = s[i];
            ans += c;
            while(i<s.size() && s[i]==c) i++;
        }
        cout<<ans;
        return ans;
    }
    int minTurn(int start,int end,vector<vector<int>>& dp,string s){
        if(start>=end) return 0;
        if(dp[start][end]) return dp[start][end];

        int ans = 1 + minTurn(start+1,end,dp,s);
        for(int i=start+1;i<end;i++){
            if(s[i] == s[start]){
                int newTurn = minTurn(start,i,dp,s) + minTurn(i+1,end,dp,s);
                ans = min(ans,newTurn);
            }
        }
        return dp[start][end] = ans;
    }
public:
    int strangePrinter(string s) {
        s = removeDuplicates(s);
        int n = s.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        return minTurn(0,n,dp,s);
    }
};