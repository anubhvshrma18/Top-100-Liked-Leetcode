class Solution {
    public:
        int jump(vector<int>& nums) {
            int n = nums.size();
            vector<int> dp(n, 0);
            dp[n-1]=0;
            for(int i=n-2;i>=0;i--) {
                int mn = INT_MAX;
                for(int j=nums[i];j>=1;j--) {
                    int t = i+j;
                    if(t>=n-1) {
                        mn=1;
                    } else if(dp[t]!=0) {
                        mn = min(mn, 1+dp[t]);
                    }
                }
                dp[i]= mn==INT_MAX ? 0 : mn;
                cout << dp[i] << endl;
            }
            return dp[0];
        }
    };