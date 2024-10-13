class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        int currMax = INT_MIN;
        for(int i=0;i<nums.size();i++){
            pq.push({nums[i][0],i,0});
            currMax = max(currMax, nums[i][0]);
        } 

        vector<int> smallRange = {0, INT_MAX};
        while(!pq.empty()){
            vector<int> curr = pq.top();
            pq.pop();
            int currMin = curr[0], ind = curr[1], eind = curr[2];
            if(currMax - currMin < smallRange[1] - smallRange[0]){
                smallRange[0] = currMin;
                smallRange[1] = currMax;
            }

            if(eind + 1 < nums[ind].size()){
                int nextVal = nums[ind][eind + 1];
                pq.push({nextVal, ind, eind + 1});
                currMax = max(currMax, nextVal);
            }else break;
        }
        return smallRange;
    }
};