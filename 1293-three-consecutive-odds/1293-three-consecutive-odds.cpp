class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int count  = 0;
        int n = arr.size();
        for(int i=0;i<n;i++){
            int val = arr[i]%2;
            if(val == 0) count = 0;
            else count++;
            if(count>=3) return true;
        }
        return false;
    }
};