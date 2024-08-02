class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int ones = count(nums.begin(), nums.end(), 1);
        int zeroes = count(nums.begin(),nums.begin()+ones,0);
        cout<<zeroes;
        int minzeroes = zeroes;
        for(int i=1;i<n;i++){
            if(nums[i-1]==0) zeroes--;
            if(!nums[(i+ones-1)%n]) zeroes++;
            minzeroes = min(minzeroes,zeroes);
        }
        return minzeroes;
    }
};