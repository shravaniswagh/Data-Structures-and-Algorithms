#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int left = 1, right = *max_element(nums.begin(), nums.end());
        int ans = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int sum = summation(nums, mid,threshold);

            if (sum > threshold) {
                left = mid + 1;  // Increase divisor
            } else {
                ans = mid;  
                right = mid - 1;  // Try a smaller divisor
            }
        }
        return ans;
    }

private:
    int summation(vector<int>& nums, int mid,int threshold) {
        long long sum = 0;
        for (int num : nums) {
            sum += (num + mid - 1) / mid;// Equivalent to ceil(num / mid)
            if (sum > threshold) break; 
        }
        return sum;
    }
};
