class Solution {
    int gcf(int a,int b){
        if(b==0) return a;
        return gcf(b,a%b);
    }
    int lcf(vector<int>arr){
        int ans = arr[0];
        for(int i=1;i<arr.size();i++){
            int val = ans*arr[i];
            ans = ans>arr[i]?val/(gcf(ans,arr[i])):val/(gcf(arr[i],ans));
        }
        return ans;
    }
public:
    string fractionAddition(string expression) {
        int n = expression.size();
        vector<string>mpp;
        vector<int>lcm;
        int left = 0;
        for(int i=1;i<n;i++){
            if(expression[i]=='+' || expression[i]=='-'){
                int k = i-left;
                string str = expression.substr(left,k);
                mpp.push_back(str);
                int j = str.find('/');
                string c = str.substr(j+1); 
                int val = stoi(c);
                lcm.push_back(val);
                left = i;
            }
        }
        string s = expression.substr(left);
        int i = s.find('/');
        string c = s.substr(i+1);
        mpp.push_back(s);
        lcm.push_back(stoi(c));
        for(auto it: lcm)cout<<it<<" ";
        cout<<endl;
        int ans = lcf(lcm);
        cout<<ans<<endl;
        int res = 0;
        for(auto it: mpp){
            int val = stoi(it);
            int i = it.find('/');
            string c = it.substr(i+1);
            int val2 = stoi(c);
            res += val*(ans/val2);
            cout<<res<<" "<<ans/val2<<endl;
        }
        int hcf = res>ans?gcf(res,ans):gcf(ans,res);
        res /= hcf;
        ans /= hcf;
        bool flag = false;
        if(res<0)flag = true;
        else if(ans<0)flag=true;
        res = abs(res);
        ans = abs(ans);
        string str = to_string(res) + "/" + to_string(ans);
        if(flag){
            str = '-'+str;
        }
        return str;
    }
};