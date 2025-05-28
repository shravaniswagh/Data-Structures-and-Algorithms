class Solution {
public:
    void dfs(int index,vector<int>candidates,vector<int>&current,vector<vector<int>>&ans,int target){
        if(target == 0){
            ans.push_back(current);
            return;
        }
        if(target<0 || index == candidates.size()){
            return;
        }
        current.push_back(candidates[index]); //include the number
        dfs(index,candidates,current,ans,target - candidates[index]);
        current.pop_back();
        dfs(index+1,candidates,current,ans,target); //exclude the number
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>current;
        int sum = 0;
        dfs(0,candidates,current,ans,target);
        return ans;
    }
};