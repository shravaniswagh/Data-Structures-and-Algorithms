class Solution {
public:
    string frequencySort(string s) {
        int n = s.size();
        unordered_map<char,int>freq;
        for(int i=0;i<n;i++){
            freq[s[i]]++;
        }
        sort(s.begin(),s.end(),[&](auto &a , auto &b){
            if(freq[a] == freq[b]){
                return a<b;
            }
            return freq[a]>freq[b];
        });
        return s;
    }
};