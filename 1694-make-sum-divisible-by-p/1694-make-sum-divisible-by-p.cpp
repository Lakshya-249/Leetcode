class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long total = 0;
        for(int it: nums) total += it;

        int rem = total%p;
        if(rem == 0) return 0;
        unordered_map<int,int>prefixSum;
        prefixSum[0] = -1;
        long sum = 0;
        int n = nums.size();

        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            int val = sum%p;
            int target = (val - rem + p)%p;

            if(prefixSum.find(target) != prefixSum.end()) n = min(n,i-prefixSum[target]);

            prefixSum[val] = i;
        }

        return n == nums.size() ? -1 : n;
    }
};