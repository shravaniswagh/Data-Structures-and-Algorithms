class Solution {
public:
    void backtrack(int index,string digits,unordered_map<char,vector<char>>& map,string& current,vector<string>& ans){
        if(index == digits.size()){
            ans.push_back(current);
            return;
        }
        char c = digits[index];
        if(map.find(c) == map.end()){
            backtrack(index+1,digits,map,current,ans);
            return;
        }
        vector<char>letters = map[c];
        for(int i=0;i<letters.size();i++){
            current.push_back(letters[i]);
            backtrack(index+1,digits,map,current,ans);
            current.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return{};
        unordered_map<char,vector<char>>map = {{'2',{'a','b','c'}},{'3',{'d','e','f'}},{'4',{'g','h','i'}},{'5',{'j','k','l'}},{'6',{'m','n','o'}},{'7',{'p','q','r','s'}},{'8',{'t','u','v'}},{'9',{'w','x','y','z'}}};
        string current;
        vector<string>ans;
        backtrack(0,digits,map,current,ans);
        return ans;        
    }
};