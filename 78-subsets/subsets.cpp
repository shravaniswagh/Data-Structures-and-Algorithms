class Solution {
public:
    void dfs(int index,vector<int>nums,vector<int>&current,vector<vector<int>>&ans){
        int n = nums.size();
        if(index == n){
            ans.push_back(current);
            return;
        }
        current.push_back(nums[index]);
        dfs(index+1,nums,current,ans);
        current.pop_back();
        dfs(index+1,nums,current,ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>current;
        dfs(0,nums,current,ans);
        return ans;
    }
};