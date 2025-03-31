class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // int zero = 0;
        int n = nums.size();
        vector<int>temp(n,0);
        int i = 0;
        for(auto it: nums){
            // if(!it) zero++;
            if(it) {
                temp[i] = it;
                i++;
            }
            // i++;
        }
        nums = temp;
    }
};