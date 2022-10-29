//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Node {
public:
    bool end;
    Node* children[26];
    Node() {
        this->end = false;
        for (int i = 0; i < 26; i++)
            this->children[i] = nullptr;
    }
};

class Trie {
public:
    Node* root;
    vector<string> arr;
    vector<vector<string>> result;
    
    Trie() {
        this->root = new Node();
    }
    
    void insert(string& str) {
        Node* curr = root;
        for (char& ch : str) {
            int k = ch - 'a';
            if (!curr->children[k])
                curr->children[k] = new Node();
            curr = curr->children[k];
        }
        curr->end = true;
    }
    void searchUtil(Node* root, string& str) {
        if (!root)
            return;
        if (root->end)
            arr.push_back(str);
        for (int k = 0; k < 26; k++) {
            char ch = k + 'a';
            str.push_back(ch);
            searchUtil(root->children[k], str);
            str.pop_back();
        }
    }
    void search(string& str) {
        Node* curr = root;
        for (char& ch : str) {
            int k = ch - 'a';
            if (!curr->children[k]) {
                result.push_back({"0"});
                return;
            }
            curr = curr->children[k];
        }
        arr.clear();
        searchUtil(curr, str);
        result.push_back(arr);
    }
    
};

class Solution {
public:
    vector<vector<string>> displayContacts(int n, string contact[], string str) {
        Trie T;
        for (int i = 0; i < n; i++){
            T.insert(contact[i]);
        }
        string _str = "";
        for (char& ch : str) {
            _str += ch;
            T.search(_str);
        }
        return T.result;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < s.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends