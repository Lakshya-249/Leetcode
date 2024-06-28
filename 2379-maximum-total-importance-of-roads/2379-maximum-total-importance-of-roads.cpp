class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int>vec(n,0);
        for(auto it: roads){
            vec[it[0]]++;
            vec[it[1]]++;
        }
        long long ans = 0;
        long long val = 1;
        sort(vec.begin(),vec.end());
        for(auto it: vec) ans += it*(val++);
        return ans;
        
    }
};