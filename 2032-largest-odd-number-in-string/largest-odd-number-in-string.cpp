class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size();
        int markindex = -1;
        string ans;
        for(int i=n-1;i>=0;i--){
            if(num[i]%2 == 1){
                markindex = i;
                break;
            }
        }
        for(int i=0;i<=markindex;i++){
            ans += num[i];
        }
        return ans;
    }
};