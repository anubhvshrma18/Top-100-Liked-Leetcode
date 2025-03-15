class Solution {
    public:
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
            int r=matrix.size();
            int c=matrix[0].size();
            int i=0,j=c-1;
            while(i<r && j>=0 ){
                int ref=matrix[i][j];
                if(target==ref){
                    return true;
                }
                else if(target< ref){
                    j--;
                }
                else{
                    i++;
                }
            }
            return false;
        }
    };