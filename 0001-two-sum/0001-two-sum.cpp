class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mpp;
        int n = nums.size();
        for(int i=0;i<n;i++){
            int sub = target - nums[i];
            if(mpp.find(sub) != mpp.end()){
                return {i, mpp[sub]};
            }
            mpp[nums[i]] = i;
        }
        return {0,0};
    }
};