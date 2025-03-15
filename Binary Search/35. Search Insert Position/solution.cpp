class Solution {
    public:
        int searchInsert(vector<int>& nums, int target) {
            int r=nums.size()-1,c;
            int l=0;
            if(target > nums[r]){
                return r+1;
            }
            if(target < nums[l]){
                return l;
            }
            while(l<=r)
            {
                int mid=l+((r-l)/2);
                if(nums[mid]==target)
                    return mid;
                if(nums[mid]<target){
                    l=mid+1;
                    c=mid;
                }
                else{ 
                    r=mid-1;
                }
            }
            
            return c+1;
        }
    };