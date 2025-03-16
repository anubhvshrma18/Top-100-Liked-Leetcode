class Solution {
    public:
        int maxProduct(vector<int>& arr) {
            int maxSum = INT_MIN;
            int sum=1, pre=1, suff=1,n=arr.size();
            for(int i=0;i<n;i++){
                if (pre == 0) pre = 1;
                if (suff == 0) suff = 1;
                pre *= arr[i];
                suff *= arr[n - i - 1];
                maxSum = max(maxSum, max(pre, suff));
            }
            // maxSum = max(sum, maxSum);
            return maxSum;
        }
    };