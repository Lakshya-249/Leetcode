class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char,int>mpp;
        for(auto it: word) mpp[it]++;
        int n = mpp.size();
        int num = (n-1)/8;
        if(!num){
            return word.size();
        }
        int val = n - (8*num);
        int ans = 0;
        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto [it,itr]:mpp){
            pq.push(itr);
        }
        while(!pq.empty()){
            int itr = pq.top();
            pq.pop();
            cout<<itr<<endl;
            if(!val){
                num--;
                val = n - (8*num);
            }
            ans += itr*(num+1);
            val--;
            n--;
        }

        return ans;

    }
};