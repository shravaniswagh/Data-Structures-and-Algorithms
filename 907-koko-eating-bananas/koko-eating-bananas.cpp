class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h){

        int n = piles.size();

        int start = 1;
        int end =  *max_element(piles.begin(),piles.end());

        if(h == n) return end;       

        while(start<=end){
            int mid = start + (end - start) / 2;
            long long cnt = count(piles,mid);
            if(cnt>h){
                start = mid +1;
            }
            else{
                end = mid-1;
            }
        }
        return start;
    }

    long long count(vector<int>& piles,int mid){
        long long cnt = 0;
        for(int i:piles){
            cnt += (i + mid - 1) / mid;  //gives us the ceil value of bananas/mid;
        }    
        return cnt;
    }
};