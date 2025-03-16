class Solution {
    public:
        int minPathSum(vector<vector<int>>& grid) {
            int n=grid.size(),m=grid[0].size();
            int dp[n][m];
            dp[n-1][m-1]=grid[n-1][m-1];
            for(int r=n-2,c=m-1;r>=0;r--){
                dp[r][c]=dp[r+1][c]+grid[r][c];
            }
            for(int i=m-2;i>=0;i--){
                dp[n-1][i]=dp[n-1][i+1]+grid[n-1][i];
            }
            
            for(int i=n-2;i>=0;i--){
                for(int j=m-2;j>=0;j--){
                    dp[i][j]=min(dp[i+1][j]+grid[i][j],dp[i][j+1]+grid[i][j]);
                }
            }
            return dp[0][0];
        }
    };