class Solution {
    unordered_map<string,int>um;
    unordered_map<int, int> memo; 
    int solve(string& s,int ind){
        if(ind >= s.size()) return 0;
        if(memo.find(ind) != memo.end()) return memo[ind];
        int extra = INT_MAX;
        string temp = "";
        for(int i=ind;i<s.size();i++){
            temp += s[i];
            if(um.find(temp) != um.end()){
                extra = min(extra, solve(s,i+1));
            }
        }
        extra = min(extra, 1+solve(s,ind + 1));
        memo[ind] = extra;
        return extra;
    }
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        for(auto it: dictionary) um[it]++;
        return solve(s,0);
    }
};