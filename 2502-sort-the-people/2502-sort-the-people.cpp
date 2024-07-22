class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int,string>>vec;
        int n = names.size();
        for(int i=0;i<n;i++){
            vec.push_back({heights[i],names[i]});
        }
        sort(vec.begin(),vec.end(),[&](const pair<int,string> &a,const pair<int,string> &b){
            return a.first>b.first;
        });
        vector<string>ans;
        for(auto it: vec)ans.push_back(it.second);
        return ans;
    }
};