class Solution {
public:
    void dfs(int index,vector<int>&candidates,vector<int>&current,vector<vector<int>>&ans,int target){
        if(target == 0){
            ans.push_back(current);
            return;
        }
        for(int i = index;i<candidates.size();i++){
            if(i>index && candidates[i] == candidates[i-1]) continue;
            if(candidates[i] > target) return;
            current.push_back(candidates[i]);
            dfs(i + 1,candidates,current,ans,target - candidates[i]);
            current.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>current;
        sort(candidates.begin() , candidates.end());
        dfs(0,candidates,current,ans,target);
        return ans;
    }
};