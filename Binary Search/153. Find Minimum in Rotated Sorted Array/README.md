# 153. Find Minimum in Roated Sorted Array

Leetcode Problem Link - [here](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/?envType=study-plan-v2&envId=top-100-liked)!

Youtube Video - 

### [Solution]():

```cpp
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0,r=nums.size()-1;
        while(l<=r){
            int mid = l+(r-l)/2;
            
            if(nums[mid]==nums[r]){
                r--;
            }
            else if(nums[mid] < nums[r]){
                // l=mid+1;
                r=mid;
            }
            else{
                l=mid+1;
            }
        }
        return nums[l];
    }
};
```