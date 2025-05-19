class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.size();
        int m = t.size();
        unordered_map<char,char>mp1;
        unordered_map<char,char>mp2;
        if(n != m ) return false;
        for(int i=0;i<n;i++){
            char c1 = s[i];
            char c2 = t[i];
            if(mp1.count(c1)){
                if(mp1[c1] != c2) return false;
            }
            else{
                mp1[c1] = c2;
            }
            if(mp2.count(c2)){
                if(mp2[c2] != c1) return false;
            }
            else{
                mp2[c2] = c1;
            }
        }
        return true;
    }
};