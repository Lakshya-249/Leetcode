class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxone = 0;
        int x = 0;
        for(auto it: nums){
            if(!it) x = 0;
            else{
                x++;
                maxone = max(maxone,x);
            }
        }
        return maxone;
    }
};