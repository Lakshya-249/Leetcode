class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {  
        set<int>st;
        unordered_map<int,int>mpp;
        for(auto it: arr) st.insert(it);
        int n = 1;
        for(auto it: st){
            mpp[it] = n;
            n++;
        }
        vector<int>res;
        for(auto it:arr){
            int ind = mpp[it];
            res.push_back(ind);
        }
        return res;
    }
};