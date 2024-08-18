class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int>ugNum(n+1);
        ugNum[1] = 1;
        int t2 = 1,t3 = 1,t5 = 1;
        for(int i=2;i<=n;i++){
            int num1 = ugNum[t2]*2;
            int num2 = ugNum[t3]*3;
            int num3 = ugNum[t5]*5;
            ugNum[i] = min(num1,min(num2,num3));
            if(ugNum[i] == num1) t2++;
            if(ugNum[i] == num2) t3++;
            if(ugNum[i] == num3) t5++;
        }
        return ugNum[n];
    }
};