class Solution {
    pair<int,int> solution(vector<int>& mapping,int num){
        int val = num;
        int ans = 0,i=0;
        while(val/10){
            int rem = val%10;
            val /= 10;
            ans += (mapping[rem])*(pow(10,i));
            i++;
        }
        ans += mapping[(val%10)]*pow(10,i);
        cout<<ans<<endl;
        return {ans,num};
    }
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int,int>>vec;
        for(auto it: nums){
            pair<int,int> pr = solution(mapping,it);
            vec.push_back(pr);
        }
        sort(vec.begin(),vec.end(),[&](const pair<int,int> &a,const pair<int,int> &b){
            if(a.first == b.first){
                return false; 
            }
            return a.first<b.first;
        });
        vector<int>ans;
        for(auto it: vec)ans.push_back(it.second);
        return ans;
    }
};