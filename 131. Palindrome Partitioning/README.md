# 131. Palindrome Partitioning

Leetcode Problem Link - [here](https://leetcode.com/problems/palindrome-partitioning/description/?envType=study-plan-v2&envId=top-100-liked)!

Youtube Video - 

### [Solution]():

```cpp

class Solution {
    public:
        bool ispal(string &s,int st,int ed){
            while(st<=ed){
                if(s[st++]!=s[ed--]) return false;
            }
            return true;
        }
        void check(string &s ,vector<string> &res,vector<vector<string>> &ans,int id){
            if(id==s.size()){
                ans.push_back(res);
                return;
            }
            for(int i=id;i<s.size();i++){
                if(ispal(s,id,i)){
                    res.push_back(s.substr(id,i-id+1));
                    check(s,res,ans,i+1);
                    res.pop_back();
                }
            }
        }
        vector<vector<string>> partition(string s) {
            vector<string> res;
            vector<vector<string>> ans;
            check(s,res,ans,0);
            return ans;
        }
    };

```