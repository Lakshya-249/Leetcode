class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int minDis = 0,maxDis = nums.back() - nums.front();
        while(minDis<maxDis){
            int mid = (minDis + maxDis)/2;
            if(solution(nums,mid)<k){
                minDis = mid+1;
            }else{
                maxDis = mid;
            }
        }
        return minDis;
    }
    int solution(vector<int>& nums,int target){
        int cnt = 0,left = 0;
        for(int right=1;right<nums.size();right++){
            while(nums[right]-nums[left]>target) left++;
            cnt += right-left;
        }
        return cnt;
    }
};