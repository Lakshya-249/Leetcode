class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans = 0;
        for(auto it: details){
            string str = it.substr(11,2);
            int age = stoi(str);
            // cout<<age<<endl;
            if(60<age) ans++; 
        }
        return ans;
    }
};