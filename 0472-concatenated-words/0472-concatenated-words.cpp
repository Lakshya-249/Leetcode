class Solution {
public:
unordered_map<string,int>mp;
int dp[31];
   bool conc(string &word,int i)
   {
       int n=word.size();
       if(i==n)
       return true;
       if(dp[i]!=-1)
       return dp[i];
       bool a=false;
       for(int j=1;j<=min(n-1,n-i);j++)//j is length of string from i'th index
       {
           if(mp[word.substr(i,j)]>0)
           {
               a=a||conc(word,i+j);
           }
       }
       return dp[i]=a;
   }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        sort(words.begin(),words.end());
        int n=words.size();
        for(int i=0;i<n;i++)
        {
            mp[words[i]]++;
        }  
        vector<string>ans;
        for(int i=0;i<n;i++)
        {
            memset(dp,-1,sizeof(dp));
           if(conc(words[i],0))
           ans.push_back(words[i]);
        }      
       return ans;
    }
};