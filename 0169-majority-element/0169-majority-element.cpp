class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans = -1;
        int n = nums.size();
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(!cnt){
                ans = nums[i];
            }
            if(nums[i] == ans) cnt++;
            else cnt--;
        }
        return ans;
    }
};