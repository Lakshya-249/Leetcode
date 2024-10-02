class Solution {
    vector<int>vec;
    int findRank(int num){
        int l = 0,r = vec.size()-1;
        while(l<=r){
            int mid = (l+r)/2;
            // cout<<mid<<" ";
            if(vec[mid] == num) return mid+1;
            else if(vec[mid] > num) r = mid-1;
            else l = mid+1;
        }
        return -1;
    }
public:
    vector<int> arrayRankTransform(vector<int>& arr) {  
        set<int>st;
        for(auto it: arr) st.insert(it);
        for(auto it: st) vec.push_back(it);
        vector<int>res;
        for(auto it:arr){
            int ind = findRank(it);
            res.push_back(ind);
        }
        return res;
    }
};