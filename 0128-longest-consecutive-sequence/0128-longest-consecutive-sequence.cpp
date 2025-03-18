class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        unordered_map<int,int>mpp;
        int maxnum = 0;
        for (auto it: nums){
            if(mpp.find(it-1) != mpp.end()){
                mpp[it] = mpp[it-1] + 1;
            }
            else{
                mpp[it] = 1;
            }
            maxnum = max(mpp[it], maxnum);
        }
        return maxnum;
    }
};