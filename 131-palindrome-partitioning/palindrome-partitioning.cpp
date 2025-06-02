class Solution {
public:
    bool palindrome(string temp){
        int j = temp.size()-1;
        int i = 0;
        while(i<j){
            if(temp[i] != temp[j]) return false;
            i++;
            j--;
        }
        return true;
    } 
    void backtrack(int index,string s,vector<string>& path,vector<vector<string>>& ans){
        if(index == s.size()){
            ans.push_back(path);
            return;
        }
        for(int i=index;i<s.size();i++){
            string temp = s.substr(index,i-index+1);
            if(palindrome(temp)){
                path.push_back(temp);
                backtrack(i+1,s,path,ans);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s){
        int stringsize = s.size();
        vector<string>path;
        vector<vector<string>>ans;
        backtrack(0,s,path,ans);
        return ans;
    }
};