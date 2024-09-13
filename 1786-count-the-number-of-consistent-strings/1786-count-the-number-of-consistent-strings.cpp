class Solution {
    
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<int>alpha(26,0);
        int ans = 0;
        for(auto it: allowed) alpha[it-'a'] = 1;
        for(auto it: words){
            int val = 1;
            for(auto chr: it){
                if(!alpha[chr-'a']){
                    val = 0;
                    break;
                }
            }
            ans += val;
        }
        return ans;
    }
};