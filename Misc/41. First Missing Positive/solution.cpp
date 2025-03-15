class Solution {
    public:
        int firstMissingPositive(vector<int>& nums) {
            int n=nums.size();
            for(int i=0;i<n;i++) {
                while(nums[i]>0 && nums[i]<=n && nums[nums[i]-1]!=nums[i]) {
                    swap(nums[i], nums[nums[i]-1]);
                }
            }
            for(auto a:nums) {
                cout << a << " ";
            }
            int idx=0;
            for(;idx<n;) {
                if(nums[idx]!=idx+1) {
                    return idx+1;
                }
                idx++;
            }
            return n+1;
        }
    };