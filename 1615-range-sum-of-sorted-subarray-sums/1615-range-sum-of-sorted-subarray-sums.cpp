class Solution {
    int mod = 1e9 + 7;
    void subArray(vector<int>& nums,int n,vector<int>& ans){
        for(int i=0;i<n;i++){
            int val = 0;
            for(int j=i;j<n;j++){
                val += nums[j];
                ans.push_back(val);
            }
        }
    }
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int>vec;
        subArray(nums,n,vec);
        sort(vec.begin(),vec.end());
        int ans = 0;
        for(int i=left-1;i<right;i++){
            ans += vec[i];
            ans %= mod;
        }
        return ans;
    }
};