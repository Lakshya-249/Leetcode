class Solution {
public:
    int minimumPartition(string s, int k) {
        int ans = 0;
        long curr = 0;
        for(int i=0;i<s.size();i++){
            long val = (int) (s[i]-'0');
            if(val > k) return -1;
            curr = 10*curr + val;
            if(curr > k){
                ans += 1;
                curr = val;
            }
        }
        return ans+1;
    }
};