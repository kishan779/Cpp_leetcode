class Solution {
public:
    bool isPowerOfTwo(int n) {
        
        
        int ans =1;
        for(int i=0; i<=30; i++){
            
            // cout<<"ans"<<ans<<endl;
            
            if (ans == n){
                return true;
            }
            
            if(ans <INT_MAX/2)
            ans = ans *2; // purana waala ans baar baar multiply hota rahega 2 se
            // ans * 2 - to ye 2 power 31 waala bhi include ho jaayega ...so condition laagao.
            
            
        }
        return false;
    }
};