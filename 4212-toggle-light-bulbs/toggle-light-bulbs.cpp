class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        unordered_map<int,int>mp;
        vector<int>ans;
        for(int i:bulbs){
            mp[i]++;
        }
        int j=0;
        for(auto j : mp){
            if(j.second%2 ==1){
                ans.push_back(j.first);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};