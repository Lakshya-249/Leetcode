class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();
        vector<int>minutes;

        for(auto it: timePoints){
            int h = stoi(it.substr(0,2));
            int m = stoi(it.substr(3));
            int temp = h*60 + m;
            minutes.push_back(temp);
        }

        sort(minutes.begin(),minutes.end());
        int ans = INT_MAX;
        for(int i=0;i<n-1;i++){
            ans = min(ans,minutes[i+1]-minutes[i]);
        }
        ans = min(ans,1440 - minutes.back() + minutes.front());
        return ans;
    }
};