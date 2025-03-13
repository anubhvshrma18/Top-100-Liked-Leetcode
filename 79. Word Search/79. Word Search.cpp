class Solution {
    public:
        int m,n;
        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        bool check(vector<vector<char>>& B, int i, int j, string& w, int id) {
            
            if (w[id] != B[i][j]) return false;
            if(id >= w.size()-1) return true;
            
            char temp = B[i][j];
            B[i][j]='.';
            for(int d=0;d<4;d++) {
                int a = i + dirs[d][0], b = j + dirs[d][1];
                if (a >= 0 && a < m && b >= 0 && b < n) {
                    if(check(B, a, b, w, id+1)) return true;
                }
            }
            B[i][j]=temp;
            return false;
            
        }
        bool exist(vector<vector<char>>& B, string W) {
            m = B.size(), n = B[0].size();
            for(int i=0;i<m;i++) {
                for(int j=0;j<n;j++) {
                        if(check(B, i, j, W, 0)) return true;
                }
            }
            return false;
        }
    };