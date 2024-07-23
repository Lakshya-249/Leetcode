class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int>mpp;
        for(auto it: nums){
            mpp[it]++;
        }
        vector<pair<int, int>> freqVec(mpp.begin(), mpp.end());
        
        sort(freqVec.begin(), freqVec.end(), [&](const pair<int, int>& a, const pair<int, int>& b) {
            if (a.second == b.second) {
                return a.first > b.first;
            }
            return a.second < b.second;
        });

        vector<int>ans;
        for (auto it : freqVec) {
            for (int i = 0; i < it.second; ++i) {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};