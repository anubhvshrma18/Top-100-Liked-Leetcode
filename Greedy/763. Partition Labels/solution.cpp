class Solution {
    public:
        vector<int> partitionLabels(string s) {
            vector<int> l(26);
            for (int i=0;i<s.size();++i)
                l[s[i]-'a'] = i;
            int j = 0, ac = 0;
            vector<int> ans;
            for (int i = 0; i < s.size(); ++i) {
                j = max(j, l[s[i]-'a']);
                if (i == j) {
                    ans.push_back(i-ac+1);
                    ac=i+1;
                }
            }
            return ans;
        }
    };