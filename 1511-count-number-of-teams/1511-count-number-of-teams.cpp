class Solution {
    
public:
    int numTeams(vector<int>& rating) {
        int ans = 0;
        int n = rating.size();
        for(int i=0;i<n-1;i++){
            int L[2]={0},R[2]={0};
            for(int j=0;j<i;j++)L[rating[j]<rating[i]]++;
            for(int k=i+1;k<n;k++) R[rating[k]<rating[i]]++;
            ans += L[1]*R[0] + L[0]*R[1];
        }
        return ans;
    }
};