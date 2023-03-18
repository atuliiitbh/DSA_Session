// GFG https://practice.geeksforgeeks.org/problems/edit-distance3702/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
class Solution {
  public:
  
    int fun(string s,string t,int i,int j,int (&dp)[101][101])
    {
        if(i==s.length() && j<=t.length()){return t.length()-j;}
        if(i<s.length() && j==t.length()){return s.length()-i;}
        if(dp[i][j]!=-1){return dp[i][j];}
        if(s[i]==t[j]){return dp[i][j]=fun(s,t,i+1,j+1,dp);}
        else
        {
            int ins=1+fun(s,t,i,j+1,dp);
            int rem=1+fun(s,t,i+1,j,dp);
            int rep=1+fun(s,t,i+1,j+1,dp);
            return dp[i][j]=min(ins,min(rem,rep));
        }
    }
    int editDistance(string s, string t) {
        // Code here
        int m=s.length();
        int n=t.length();
        if(m>n){swap(s,t);}
        int dp[101][101];
        memset(dp,-1,sizeof(dp));
        return fun(s,t,0,0,dp);
    }
};
