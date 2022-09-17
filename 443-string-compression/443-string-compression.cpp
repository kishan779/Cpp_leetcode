class Solution {
public:
    int compress(vector<char>& chars) {
        int i =0; 
        int ansIndex = 0;
        int n = chars.size();
        
        while( i<n){
            
            int j= i+1;
            while( j<n && chars[i]== chars[j]){
                j++;
            }
            
            //yaha kab aaoge 
            // yaa to vector poora traverse krdia
            // ya fir new / Differnet character encounter kia hai
            
            // oldchar store karlo 
            
            chars[ansIndex++] = chars[i];
            
            int count = j-i;
            
            if( count > 1){
                // covering counting into single digit and saving in answer
                string cnt = to_string(count);
                for( char ch: cnt){
                    chars[ansIndex++] = ch;
                }
            }
            
            // moving to new/Different character 
            i=j;
            
        }
        return ansIndex;
        
        
        
    }
};