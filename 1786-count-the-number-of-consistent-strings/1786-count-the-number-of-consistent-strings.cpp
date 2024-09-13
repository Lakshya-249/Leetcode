class Solution {
    bool allow(string allowed,string given){
        int val = 0;
        for(auto it:given){
            for(auto itr: allowed){
                if(it == itr) val++;
            }
        }
        return val == given.size();
    }
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int ans=0;
        for(auto it: words){
            if(allow(allowed,it)) ans++;
        }
        return ans;
    }
};