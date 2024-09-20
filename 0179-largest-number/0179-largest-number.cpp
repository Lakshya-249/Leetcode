class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),[&](int a,int b){
            string n1 = to_string(a);
            string n2 = to_string(b);
            if(n1+n2 > n2+n1) return true;
            return false;
        });
        if(nums[0]==0) return "0";

        string ans = "";
        for(auto it: nums){
            string str = to_string(it);
            ans += str;
        }
        return ans;
    }
};