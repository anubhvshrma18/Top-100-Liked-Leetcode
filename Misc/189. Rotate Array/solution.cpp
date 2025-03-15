class Solution {
    public:
        void rotate(vector<int>& nums, int k) {
            int n=nums.size();
            k=k%n;
            cout << k << endl;
            if(k==0) return;
            int l=0,r=n-k-1;
            while(l<r) {
                swap(nums[l++], nums[r--]);
            }
            l=n-k,r=n-1;
            while(l<r) {
                swap(nums[l++], nums[r--]);
            }
            l=0,r=n-1;
            while(l<r) {
                swap(nums[l++], nums[r--]);
            }
        }
    };