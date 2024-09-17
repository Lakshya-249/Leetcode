class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        string str = "";
        unordered_map<string,int>mpp;
        for(auto it: s1){
            if(it == ' '){
                mpp[str]++;
                str = "";
            }else{
                str += it;
            }
        }
        mpp[str]++;
        str = "";
        for(auto it: s2){
            if(it == ' '){
                mpp[str]++;
                str = "";
            }else{
                str += it;
            }
        }
        mpp[str]++;
        vector<string>ans;
        for(auto [i,j]: mpp){
            if(j==1) ans.push_back(i);
        }
        return ans;
    }
};