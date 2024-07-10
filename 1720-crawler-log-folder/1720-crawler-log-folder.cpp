class Solution {
public:
    int minOperations(vector<string>& logs) {
        int ans = 0;
        for(auto it:logs){
            if(it=="../") {
                ans--;
                if(ans < 0) ans = 0;
            }else if(it=="./") continue;
            else ans++;
        }
        return ans;
    }
};