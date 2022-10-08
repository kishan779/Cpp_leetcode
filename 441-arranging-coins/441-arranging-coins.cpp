class Solution {
public:
    int arrangeCoins(int n) {
        
        int cnt=0;
        for (int i=1; i<=n; i++){
            if((n-i)<0)break;
            cnt++;
            n= n-i;
            
        }
        return cnt;
    }
    
};