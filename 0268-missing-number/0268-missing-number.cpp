class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int total = 0;
        for(auto it: nums) total += it;
        n = (n*(n+1))/2;
        return n - total;
    }
};