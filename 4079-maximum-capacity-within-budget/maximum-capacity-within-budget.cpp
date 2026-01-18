class Solution {
public:
    int maxCapacity(vector<int>& costs, vector<int>& capacity, int budget) {
        int n = costs.size();
        vector<pair<int,int>> a(n);

        for(int i = 0; i < n; i++) {
            a[i] = {costs[i], capacity[i]};
        }

        sort(a.begin(), a.end());   // sort by cost

        // prefix max of capacities (best capacity up to index i)
        vector<int> pref(n);
        pref[0] = a[0].second;
        for(int i = 1; i < n; i++) {
            pref[i] = max(pref[i-1], a[i].second);
        }

        int ans = 0;

        // case 1: pick ONE machine
        for(int i = 0; i < n; i++) {
            if(a[i].first < budget) {
                ans = max(ans, a[i].second);
            }
        }

        // case 2: pick TWO machines
        for(int i = 1; i < n; i++) {
            int remain = budget - a[i].first;
            if(remain <= 0) continue;

            // find rightmost index j < i with cost[j] < remain
            int l = 0, r = i - 1, best = -1;
            while(l <= r) {
                int mid = (l + r) / 2;
                if(a[mid].first < remain) {
                    best = mid;
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }

            if(best != -1) {
                ans = max(ans, pref[best] + a[i].second);
            }
        }

        return ans;
    }
};
