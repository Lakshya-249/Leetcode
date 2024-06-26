class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int num = 0;
        for(auto it:nums){
            num = max(it,num);
        }
        int ans = 0;
        while(k>0){
            ans += num++;
            k--;
        }
        return ans;
    }
};