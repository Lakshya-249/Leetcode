class Solution {
    vector<vector<int>>ans;
    void permutation(vector<int>& nums, vector<int>& ds, vector<int>& pem){
        if(ds.size() == nums.size()){
            ans.push_back(ds);
            return;
        }

        for(int i=0;i<nums.size();i++){
            if(!pem[i]){
                pem[i] = 1;
                ds.push_back(nums[i]);
                permutation(nums,ds,pem);
                ds.pop_back();
                pem[i] = 0;
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>ds;
        int n = nums.size();
        vector<int>pem(n,0);
        permutation(nums,ds,pem);
        return ans;
    }
};