class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int n = nums.size();
        int minimum = INT_MAX;
        int sum = 0;
        for(int i=0;i<n;i++){
            sum += nums[i];
            minimum = min(sum , minimum);
        }
        return max(1,1-minimum);
    }
};