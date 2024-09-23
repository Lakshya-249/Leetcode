class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<string>vec;
        for(int i=1;i<=n;i++){
            string str = to_string(i);
            vec.push_back(str);
        }
        sort(vec.begin(),vec.end());
        vector<int>res;
        for(auto it:vec){
            res.push_back(stoi(it));
        }
        return res;
    }
};