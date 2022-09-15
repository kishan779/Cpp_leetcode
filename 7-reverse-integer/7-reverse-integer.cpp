class Solution {
public:
    
   int  ans = 0;
    int reverse(int n) {
        
        while(n!=0){
            int digit = n %10;
            if ((ans > INT_MAX/10) || (ans < INT_MIN/10) ){
                return 0;
            }
                ans = (ans*10)+ digit;
            n = n/10;
            
            
        }   
         return ans;
    }
    
};






