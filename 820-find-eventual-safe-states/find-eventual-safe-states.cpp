class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        //kahn's algorithm
        int n = graph.size();
        vector<int>outdegree(n,0);
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
            outdegree[i] = graph[i].size();
            for(int j : graph[i]){
                adj[j].push_back(i);
            }
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(outdegree[i] == 0){
                q.push(i);
            }
        }
        vector<int>safe(n,0);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            safe[node] = 1;
            for(int p : adj[node]){
                outdegree[p]--;
                if(outdegree[p] == 0){
                    q.push(p);
                }
            }
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(safe[i])ans.push_back(i);
        }
        return ans;
    }
};