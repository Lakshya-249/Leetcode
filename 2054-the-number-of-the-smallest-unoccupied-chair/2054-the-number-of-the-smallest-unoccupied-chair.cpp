class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        vector<int> order(n);

        priority_queue<int,vector<int>, greater<int>>pq1;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq2;

        for(int i=0;i<n;i++){
            order[i] = i; 
            pq1.push(i);
        } 
        sort(order.begin(),order.end(),[&times](int a,int b)->bool{
            return times[a][0] < times[b][0];
        });

        for(auto it: order){
            int arrival = times[it][0], leave = times[it][1];

            while(!pq2.empty() && pq2.top().first <= arrival){
                pq1.push(pq2.top().second);
                pq2.pop();
            }

            int seat = pq1.top();
            pq1.pop();

            if(it == targetFriend) return seat;
            
            pq2.push({leave, seat});
        }
        return -1;
    }
};