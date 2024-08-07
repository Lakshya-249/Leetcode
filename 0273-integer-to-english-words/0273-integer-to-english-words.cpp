class Solution {
    string numbers1[20] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight","Nine","Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    string numbers2[10] = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", 
"Eighty", "Ninety"};
    string numbers3[5] = {"", "Thousand", "Million", "Billion"};
    
    void convert3digittoword(int number,stack<string>&st){
        int val = number%100;
        number /= 100;
        if(val<20 && val != 0){
            st.push(numbers1[val]);
        }else{
            int val2 = val%10;
            val = val/10;
            if(val2>0){
                st.push(numbers1[val2]);
                if(val!=0) st.push(numbers2[val]);
            }else if(val!=0) st.push(numbers2[val]);
        }
        if(number>0){
            st.push("Hundred");
            st.push(numbers1[number]);
        }
    }
public:
    string numberToWords(int num) {
        string ans = "";
        int n = 0;
        if(num==0) return "Zero";
        stack<string>st;
        while(num>0){
            int val = num%1000;
            num = num/1000;
            string str = "0";
            if(!st.empty()) str = st.top();
            // if(str == "" || str == " "){
            //     st.pop();
            //     if(!st.empty()) str = st.top();
            // }
            if(str == "Thousand" && numbers3[n]=="Million"){
                st.pop();
            }else if((str == "Million" || str == "Thousand") && numbers3[n]=="Billion"){
                st.pop();
            }
            st.push(numbers3[n]);
            convert3digittoword(val,st);
            n++;
        }
        while(!st.empty()){
            // cout<<st.top()<<endl;
            // // if(st.top() == "" || st.top() == " "){
            // //     st.pop();
            // //     continue;
            // // }
            ans += st.top()+" ";
            st.pop();
        }
        ans.erase(ans.find_last_not_of(' ')+1);
        ans.erase(0, ans.find_first_not_of(' '));
        return ans;
    }
};