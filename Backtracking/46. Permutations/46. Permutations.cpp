class Solution {
    public:
        vector<vector<int>> ans;
        void perm(vector<int> &nums,int r,int c){
            if(r == nums.size()){
                ans.push_back(nums);
                return;
            }
            for(int i=r;i<nums.size();i++){
                swap(nums[i],nums[r]);
                perm(nums,r+1,c);
                swap(nums[i],nums[r]);
            }
        }
        vector<vector<int>> permute(vector<int>& nums) {
            int n=nums.size();
            perm(nums,0,n);
            return ans;
        }
    };