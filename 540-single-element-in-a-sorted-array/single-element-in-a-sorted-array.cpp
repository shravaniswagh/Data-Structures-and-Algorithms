class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0;
        int right =  nums.size()-1;
        if(right + 1 == 1) return nums[0];
        while(left<=right){
            int mid= left + (right-left)/2;

            if(mid<right && mid>0){
                if(nums[mid-1]!=nums[mid] && nums[mid]!=nums[mid+1]){
                    return nums[mid];
                }
            }
            if(mid == 0 && nums[mid]!=nums[mid+1]){
                return nums[mid];
            }    
            if(mid == right){
                if(right%2 == 0 && nums[mid] != nums[mid+1]){
                    return nums[mid];
                }
                if(right%2 != 0 && nums[mid-1] != nums[mid]){
                    return nums[mid];
                }
            }        
            
            if(mid%2 == 0){
                if(nums[mid]!=nums[mid+1]){
                    right = mid-1;
                }
                else{
                    left = mid+1;
                }
            }
            else{
                if(nums[mid]!=nums[mid-1]){
                    right = mid-1;
                }
                else{
                    left = mid+1;
                }
            }
        }
        return 0;
    }
};