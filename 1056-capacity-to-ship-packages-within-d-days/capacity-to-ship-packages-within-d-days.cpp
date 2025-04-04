class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int sum = 0;
        for(int i : weights) sum += i;
        int left = 1;
        int right = sum;
        int ans= 0;
        while(left<=right){
            int mid = left + (right - left) / 2;

            int capacity = calculate(weights,days,mid);

            if(capacity>days){
                left = mid +1;
            }
            else{
                ans = mid;
                right = mid -1;
            }
        }
        return ans;
    }
    int calculate(vector<int>& weights,int days,int mid){
        int n = weights.size();
        int d = 1;
        int sum = 0;
        for(int i=0;i<n;i++){
            if(sum + weights[i]>mid){
                d++;
                sum = weights[i];
                if (sum > mid) return INT_MAX;
            }
            else{
                sum+=weights[i];
            }
        }
        return d;
    }
};