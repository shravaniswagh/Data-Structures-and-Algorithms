class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.size();
        vector<int>groupsize;
        int i=0;
        while(i<n){
            int groupcount = 1;
            while(i+1 < n && s[i+1] == s[i]){
                groupcount++;
                i++;
            }
            groupsize.push_back(groupcount);
            i++;
        }
        int result = 0;
        for(int i=1;i<groupsize.size();i++){
            result += min(groupsize[i-1] , groupsize[i]);
        }
        return result;
    }
};