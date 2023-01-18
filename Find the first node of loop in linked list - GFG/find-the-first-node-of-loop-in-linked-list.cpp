//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void loopHere(Node* head, Node* tail, int position)
{
    if(position==0) return;
    
    Node* walk = head;
    for(int i=1; i<position; i++)
        walk = walk->next;
    tail->next = walk;
}


// } Driver Code Ends
//User function Template for C++

/*struct Node
{
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }

*/

class Solution
{
    public:
    
   bool isCycle(Node*&slow,Node*&fast){
         while(fast!=NULL and fast->next!=NULL){
             fast=fast->next->next;
             slow=slow->next;
             if(slow==fast){
                 return 1;
             }
         }
         return 0;
     }
    int findFirstNode(Node* head)
    {
        
        if(head==NULL or head->next==NULL)return -1;
        Node*slow=head,*fast=head;
        bool ans=isCycle(slow,fast);
        if(ans==0)return -1;
        else{
            fast=head;
            while(slow!=fast){
            slow=slow->next;
            fast=fast->next;
        }
        return slow->data;
            }
           
        }
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, num;
        cin>>n;
        
        Node *head, *tail;
        cin>> num;
        head = tail = new Node(num);
        
        for(int i=0 ; i<n-1 ; i++)
        {
            cin>> num;
            tail->next = new Node(num);
            tail = tail->next;
        }
        
        int pos;
        cin>> pos;
        loopHere(head,tail,pos);
        
        Solution ob;
        int ans = ob.findFirstNode(head);
        cout<<ans<<"\n";
    }
	return 0;
}
// } Driver Code Ends