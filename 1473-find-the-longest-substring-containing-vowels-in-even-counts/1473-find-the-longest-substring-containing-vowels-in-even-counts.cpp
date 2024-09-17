class Solution {
    bool check(char ch){
        return ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u';
    }
public:
    int findTheLongestSubstring(string s) {
        int n = s.size();
        unordered_map<char,int>vowel = {{'a',0},{'e',1},{'i',2},{'o',3},{'u',4}};
        unordered_map<int,int>last_occur;
        last_occur[0] = -1;
        int curr = 0;
        int len = 0;

        for(int i=0;i<n;i++){
            if(check(s[i])){
                curr ^= (1<<vowel[s[i]]);
            }

            if(last_occur.find(curr) != last_occur.end()){
                len = max(len, i-last_occur[curr]);
            }else{
                last_occur[curr] = i;
            }
        }

        return len;
    }
};