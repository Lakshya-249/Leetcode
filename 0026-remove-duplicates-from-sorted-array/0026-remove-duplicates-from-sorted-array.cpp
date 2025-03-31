class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n==1) return n;
        int k = 0;
        vector<int>ans;
        for (int i=0;i<n;i++){
            if(ans.size() && ans.back() == nums[i]) k++;
            else ans.push_back(nums[i]);
        }
        nums = ans;
        return n-k;
    }
};