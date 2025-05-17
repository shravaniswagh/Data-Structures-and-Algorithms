class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        string ans;
        stack<string>st;
        string temp;
        for(int i=0;i<n;i++){
            if(s[i]!=' '){
                temp += s[i];
            }
            if((s[i] == ' ' || i == n-1)&& !temp.empty()){
                st.push(temp);
                temp.clear();
            }
        }
        while(!st.empty()){
            ans += st.top();
            st.pop();
            if(!st.empty()) ans += ' ';
        }
        return ans;
    }
};