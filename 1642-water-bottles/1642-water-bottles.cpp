class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        // return numBottles + (numBottles - 1)/(numExchange - 1);
        int ans = numBottles;
        int emp = numBottles;

        while(emp/numExchange != 0){
            int val = emp/numExchange;
            int nemp = emp - val*numExchange;
            ans += val;
            emp = val + nemp;
        }
        return ans;
    }
};