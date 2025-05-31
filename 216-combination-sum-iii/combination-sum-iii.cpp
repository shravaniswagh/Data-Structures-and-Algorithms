class Solution {
public:
    void dfs(int index,vector<int>&current,vector<vector<int>>&ans,int k,int n,int count,int sum){
        if(sum>n) return;
        if(index>9) return;
        if(count > k) return;
        current.push_back(index);
        if(sum+index == n && count+1 == k){
            ans.push_back(current);
        }else{
            dfs(index+1,current,ans,k,n,count+1,sum+index);
        }
        current.pop_back();
        dfs(index+1,current,ans,k,n,count,sum);   
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>current;
        vector<vector<int>>ans;
        int count = 0;
        int sum = 0;
        dfs(1,current,ans,k,n,count,sum);
        return ans;        
    }
};