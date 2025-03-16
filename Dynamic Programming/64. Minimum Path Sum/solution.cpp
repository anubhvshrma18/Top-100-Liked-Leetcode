class Solution {
    public:
        vector<vector<int>> generate(int numRows) {
            vector<vector<int>> ans(numRows);
            ans[0]={1};
            if(numRows == 1) return ans;
            ans[1]={1,1};
            if(numRows == 2) return ans;
            
            for(int i=2;i<numRows;i++) {
                vector<int> temp(i+1);
                temp[0]=1, temp[i]=1;
                for(int j=1;j<i;j++) {
                    temp[j]=ans[i-1][j-1]+ans[i-1][j];
                }
                ans[i]=temp;
            }
            return ans;
        }
    };