
// Problem - set Bit (1) count krna hai 
class Solution {
public:
    int hammingWeight(uint32_t n) {
        
        int count =0;
       while(n!=0){
            // checking last bit 
           
           if (n&1){
               count++;
           }
        n = n>>1;
       }
        return count;  
        
    }
};


/*
// Ex - 0000........00110
count = 0
then right shift 
000.......0011
count = 1
then right shift 
00... 001
count =2;
then rightt shift ;
count = 3;

00..0000 

ab nhi hoga kyuki sab bits 0 hai;

*/