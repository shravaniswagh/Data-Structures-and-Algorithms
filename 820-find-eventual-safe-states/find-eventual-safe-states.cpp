class Solution {
public:
    bool bfs(int j, vector<int>& outdegree, vector<vector<int>>& graph,
             set<int>& terminated, vector<int>& vis) {

        if (terminated.count(j)) return true;
        if (vis[j] == 1) return false;  // cycle detected
        if (vis[j] == 2) return true;   // already known safe

        vis[j] = 1; // visiting

        for (int nei : graph[j]) {
            if (!bfs(nei, outdegree, graph, terminated, vis)) {
                return false;
            }
        }

        vis[j] = 2;      // safe
        terminated.insert(j);
        return true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> outdegree(n);
        set<int> terminated;
        vector<int> vis(n, 0);

        for (int i = 0; i < n; i++) {
            outdegree[i] = graph[i].size();
            if (outdegree[i] == 0) {
                terminated.insert(i);
                vis[i] = 2; // safe
            }
        }

        for (int i = 0; i < n; i++) {
            bfs(i, outdegree, graph, terminated, vis);
        }

        return vector<int>(terminated.begin(), terminated.end());
    }
};
