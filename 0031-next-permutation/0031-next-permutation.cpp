class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size() - 1;
        int ind = -1;
        for(int i=n; i>0; i--){
            if(nums[i] > nums[i-1]){
                ind = i-1;
                break;
            }
        }
        if(ind == -1) {
            reverse(nums.begin(),nums.end());
            return;
        }
        for(int i=n;i>ind;i--){
            if(nums[i]>nums[ind]) {
                swap(nums[i], nums[ind]);
                break;
            }
        }
        reverse(nums.begin()+ind+1, nums.end());
    }
};