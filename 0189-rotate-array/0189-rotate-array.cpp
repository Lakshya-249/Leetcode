class Solution {
    void rotL(vector<int>& nums, int k , int n){
        if (!k) return;
        int temp = nums[n-1];
        for (int i=n-1;i>0;i--) nums[i] = nums[i-1];
        nums[0] = temp;
        rotL(nums, k-1, n);
    }
public:
    void rotate(vector<int>& nums, int k) {
        // int n = nums.size();
        // if (n==1) return;
        // cout<<n;
        // rotL(nums, k%n , n);
        int n = nums.size();
        k = k % n; // Handle cases where k > n

        // Reverse the entire array
        reverse(nums.begin(), nums.end());
        // Reverse first k elements
        reverse(nums.begin(), nums.begin() + k);
        // Reverse the remaining n-k elements
        reverse(nums.begin() + k, nums.end());
    }
};