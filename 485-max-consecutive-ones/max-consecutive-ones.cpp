class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int highestcnt = 0;
        int cnt = 0;
        int n = nums.size();
        for(int i =0;i<n;i++){
            if(nums[i] == 1){
                cnt++;
                highestcnt = max(highestcnt , cnt);
            }
            else{
                cnt = 0;
            }
        }
        return highestcnt;
    }
};