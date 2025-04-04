class Solution {
public:
    void sortColors(vector<int>& nums) {
        int start = 0;
        int ptr = 0;
        int last = nums.size()-1;
        while(ptr<=last){
            if(nums[ptr] == 0){
                swap(nums[ptr],nums[start]);
                start++;
                ptr++;
            }else if(nums[ptr] == 2){
                swap(nums[ptr],nums[last]);
                last--;
            }else{
                ptr++;
            }
        }
    }
};