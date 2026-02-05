class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        priority_queue<
            pair<int,pair<int,int>>,
            vector<pair<int,pair<int,int>>>,
            greater<pair<int,pair<int,int>>>
        >pq;
        vector<int>shorttime(n+1,1e9);
        vector<int>vis(n+1,0);
        if(times.size()<k) return -1;
        for(auto it : times){
            adj[it[0]].push_back({it[1],it[2]});
        }    
        shorttime[k] = 0;
        vis[k] = 1;
        pq.push({0,{k,k}});
        while(!pq.empty()){
            auto it = pq.top();
            int t = it.first;
            int s = it.second.first;
            int d = it.second.second;
            pq.pop();
            if(t > shorttime[d]) continue;
            for(auto iter : adj[d]){
                int dn = iter.first;
                int tn = iter.second;
                if(t + tn < shorttime[dn]){
                    shorttime[dn] = t + tn;
                    pq.push({shorttime[dn],{d,dn}});
                }
            } 
        }
        int ans = 0;
        for(int it=1;it<shorttime.size();it++){
            if(shorttime[it] == 1e9) return -1;
            ans = max(ans,shorttime[it]);
        }
        return ans;
    }
};