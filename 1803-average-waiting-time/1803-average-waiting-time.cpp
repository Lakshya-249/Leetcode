class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int next = 0;
        int n = customers.size();
        double ans = 0;      
        for(auto it: customers){
            next = max(next,it[0]) + it[1];
            ans += next-it[0];
        }
        return ans/n;
    }
};