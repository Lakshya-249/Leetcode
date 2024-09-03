class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long sum = 0;
        sum = accumulate(chalk.begin(), chalk.end(), sum);
        long long remaining = k%sum;
        for(int i=0;i<chalk.size();i++){
            if(remaining<chalk[i]) return i;
            remaining -= chalk[i];
        }
        return 0;
    }
};