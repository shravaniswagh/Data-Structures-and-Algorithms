class Solution {
public:
    int reversePairs(vector<int>& nums) {
        return mergesort(nums.begin(),nums.end());
    }
    int mergesort(vector<int>::iterator low, vector<int>::iterator high){
        
        if(high-low<=1) return 0;
        auto mid = low + (high-low) / 2;   
        //auto automatically adapts, eg low and high were LL then it automatically changes to LL
        int cnt = mergesort(low,mid) + mergesort(mid,high);
        for(auto left = low,right = mid;left<mid;left++){
            while(right<high && *left>2LL*(*right)) right++;
            cnt += right - mid;
        }

        inplace_merge(low,mid,high);    //no need of merge function
        return cnt;
    }


            
    
};                      