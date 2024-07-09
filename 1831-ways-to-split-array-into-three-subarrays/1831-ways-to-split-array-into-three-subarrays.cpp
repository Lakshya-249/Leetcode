class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        int mod = (int) 1e9 + 7;
        vector<int>vec(n);
        vec[0] = nums[0];
        for(int i=1;i<n;i++) vec[i] = vec[i-1] + nums[i];
        int j = 0,k = 0;
        for(int i=0;i<n-1;i++){
            if(vec[i]*3 > vec[n-1]) break;
            j = max(j,i+1);
            while(j<n-1 && (vec[j] - vec[i])< vec[i]) j++;
            k = max(j,k);
            while(k<n-1 && (vec[k] - vec[i]) <= (vec[n-1] - vec[i])/2) k++;
            k--;
            ans = (ans + k - j + 1)%mod;
        }
        return ans;
    }
};