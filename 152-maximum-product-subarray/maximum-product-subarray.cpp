class Solution {
public:
    int maxProduct(vector<int>& nums) {
        long long pre = 1;
        long long suff = 1;
        long long ans = INT_MIN;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(pre == 0) pre=1;
            if(suff ==0) suff = 1;

            pre = pre * nums[i];
            suff = suff * nums[n-i-1];
            ans =  max(ans,max(pre,suff));
        }
        return ans;
    }
};