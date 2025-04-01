class Solution {
public:

    int canbloom(vector<int>& bloomDay , int m, int k, int days){
        int count =0;
        int bouquets =0;

        for(int i : bloomDay){
            if(i  <= days){
                count++;
                if(count == k){
                    bouquets++;
                    count = 0;
                }
            }
            else{
                count = 0;
            }
        }
        return bouquets>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long totalflowers = (long long) m * k;
        if(bloomDay.size()<totalflowers) return -1;
        int left = *min_element(bloomDay.begin(),bloomDay.end());
        int right = *max_element(bloomDay.begin(),bloomDay.end());
        int ans = -1;
        while(left<=right){
            int mid = left + (right - left) / 2;
            if(canbloom(bloomDay,m,k,mid)){
                ans = mid;
                right = mid -1;
            }
            else{
                left = mid +1;
            }
        }
        return ans;
    }
};