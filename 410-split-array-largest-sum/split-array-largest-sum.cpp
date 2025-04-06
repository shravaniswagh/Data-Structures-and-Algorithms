class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int left = *max_element(nums.begin(),nums.end());
        int right = accumulate(nums.begin(),nums.end(),0);
        int ans = 0;
        while(left<=right){
            int mid = left + (right - left) / 2;
            int kdup = countk(nums,mid);
            if(kdup>k){
                left = mid+1;
            }
            else{
                ans = mid;
                right = mid-1;
            }
        }
        return ans;
    }
    int countk(vector<int>& nums,int mid){
        int n = nums.size();
        int kdup = 1;
        int sum = 0;
        for(int i = 0; i<n;i++){
            if(sum + nums[i] <= mid){
                sum += nums[i];
            }
            else{
                kdup++;
                sum = nums[i];
            }
        }
        return kdup;
    }
};