class Solution {
    
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int total = 0;
        unordered_map<string,int>mp;
        return calculate(nums,0,0,target,mp);
    }

    int calculate(vector<int>nums,int i,int sum,int target,unordered_map<string,int>&mp){
        if(i == nums.size()){
            if(target==sum) return 1;
            else return 0;
        }
        string key = to_string(i) + "-" + to_string(sum);
        if(mp.find(key) != mp.end()) return mp[key];
        return mp[key] = calculate(nums,i+1,sum - nums[i],target,mp) + calculate(nums,i+1,sum + nums[i],target,mp);
    }
};
