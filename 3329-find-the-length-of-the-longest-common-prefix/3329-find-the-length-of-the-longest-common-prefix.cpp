class Solution {
    unordered_map<int,int>mpp;
    void getPrefixes(int num){
        while(num != 0){
            mpp[num]++;
            num /= 10;  
        }
    }
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int ans = INT_MIN;
        for(auto it: arr1){
            getPrefixes(it);
        }
        for(auto it: arr2){   
            while(it != 0){
                if(mpp.find(it) != mpp.end()){
                    string tmp = to_string(it);
                    int val = tmp.size();
                    ans = max(ans,val);
                }
                it /= 10;
            }
        }
        if(ans<0) ans = 0;
        return ans;
    }
};