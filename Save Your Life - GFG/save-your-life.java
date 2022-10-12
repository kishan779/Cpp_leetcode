//{ Driver Code Starts
import java.io.*;
import java.util.*;

// } Driver Code Ends
class Solution{
     static String maxSum(String w,char x[],int b[], int n){
        //code here
               int len = w.length();
        int[] arr = new int[len];
        for(int i = 0;i<len;i++){
            arr[i] = (int)w.charAt(i);
        }
        Map<Character,Integer> mp = new HashMap<>();
        for(int i = 0;i<n;i++){
            mp.put(x[i],b[i]);
        }
        for(int i = 0;i<len;i++){
            char c = w.charAt(i);
            if(mp.containsKey(c)){
                arr[i] = mp.get(c);
            }
        }
        //Using kadane's algorithm
        int sum = 0,max_so_far = Integer.MIN_VALUE,start=0,end=0,s=0;
        for(int i = 0;i<len;i++){
            sum+=arr[i];
            if(max_so_far<sum){
                max_so_far = sum;
                start = s;
                end = i;
            }
            if(sum<0){
                sum = 0;
                s = i+1;
            }
        }
        return w.substring(start,end+1);
    }

}

//{ Driver Code Starts.
class GFG
{
    public static void main(String args[])throws IOException
    {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while(t-- > 0)
        {
            String w = read.readLine();
            int n = Integer.parseInt(read.readLine());
            String TE[] = read.readLine().trim().split(" ");
            char x[] = new char[n];
            for(int i = 0;i<n;i++)
            {
                x[i] = TE[i].charAt(0);
            }
            
            String TR[] = read.readLine().trim().split(" ");
            int b[] = new int[n];
            for(int i = 0;i<n;i++)
            {
                b[i] = Integer.parseInt(TR[i]);
            }
           
            Solution ob = new Solution();
            System.out.println(ob.maxSum(w,x,b,n));
        }
    }
}
// } Driver Code Ends