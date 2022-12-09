//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

long long numOfWays(int n, int m);

int main() {
    // code
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        cout << numOfWays(n, m) << endl;
    }
    return 0;
}
// } Driver Code Ends


//Function to find out the number of ways we can place a black and a 
//white Knight on this chessboard such that they cannot attack each other.
long long safePlaces(int i, int j, int N, int M, int totalPos){
    int unsafe=0;
    // down
    if(i+2<N){
        if(j+1<M)
            unsafe++;
        if(j-1>=0)
            unsafe++;
    }
    // up
    if(i-2>=0){
        if(j+1<M)
            unsafe++;
        if(j-1>=0)
            unsafe++;
    }
    // right
    if(j+2<M){
        if(i+1<N)
            unsafe++;
        if(i-1>=0)
            unsafe++;
    }
    // left
    if(j-2>=0){
        if(i+1<N)
            unsafe++;
        if(i-1>=0)
            unsafe++;
    }
    return totalPos-unsafe;
}
long long numOfWays(int N, int M)
{
    // write code here
    int mod=1e9+7;
    vector<vector<int>>board(N,vector<int>(M,0));
    int ans=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            ans+=safePlaces(i,j,N,M,N*M-1); // 1 place fixed-> N*M-1
            ans%=mod;
        }
    }
    return ans;
}