// Leetcode Question Link "https://leetcode.com/problems/group-anagrams/submissions/"
// Leetcode 49. Group Anagrams

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string>> ans;
        vector<string> sorted;
        string t;
        for(string s:strs)
        {
            t=s;
            sort(t.begin(),t.end());
            sorted.push_back(t);
        }
        vector<int> hash(strs.size(),1);
        vector<string> temp;
        for(int i=0;i<strs.size();i++)
        {
            if(hash[i]==1)
            {
                temp.push_back(strs[i]);
                for(int j=i+1;j<strs.size();j++)
                {
                    if(sorted[j]==sorted[i] && hash[j]==1)
                    {
                        temp.push_back(strs[j]);
                        hash[j]=0;
                    }  
                }
                ans.push_back(temp);
                temp.clear();
            }
        }
        return ans;
    }
};
