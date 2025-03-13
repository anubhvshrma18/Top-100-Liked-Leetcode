class Solution {
    public:
        vector<vector<int>> ans;
        void temp(vector<int> &arr,vector<int> &res,int id,int tar,int ssf){
            if(id == arr.size()){
                if(ssf==tar){
                    ans.push_back(res);
                }
                return;
            }
            if(ssf > tar){return;}
            if(ssf==tar){
                ans.push_back(res);
                return;
            }
            
            for(int i=id;i<arr.size();i++){
                res.push_back(arr[i]);
                temp(arr,res,i,tar,ssf+arr[i]);
                res.pop_back();
            }
        }
        vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
            vector<int> res;
            temp(candidates,res,0,target,0);
            return ans;
        }
    };