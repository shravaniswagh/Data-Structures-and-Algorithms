class Solution {
public:
    int maxDepth(string s) {
        int maxdepth = 0;
        int currentdepth = 0;
        int n = s.size();
        for(int i=0;i<n;i++){
            if(s[i] == '('){
                currentdepth++;
                maxdepth = max(maxdepth,currentdepth);
            }
            else if(s[i] == ')'){
                currentdepth--;
            }
        }
        return maxdepth;
    }
};