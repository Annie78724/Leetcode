//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};




// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
  public:
    //Function to check whether the list is palindrome
    Node *getMid(Node *head)
    {
        Node *fast=head->next,*slow=head;
        while(fast and fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    Node *rev(Node* head)
    {
        Node* c=head,*p=NULL,*n;
        while(c)
        {
            n=c->next;
            c->next=p;
            p=c;
            c=n;
        }
        return p;
    }
    bool isPalindrome(Node *head)
    {
        //Your code here
        if(!head) return true;
        if(head->next==NULL) return true;
        Node* mid=getMid(head);
        Node *temp=mid->next;
        mid->next=rev(temp);
        while(mid->next)
        {
            if(head->data!=mid->next->data) return false;
            head=head->next;
            mid->next=mid->next->next;
        }
      temp=mid->next;
        mid->next=rev(temp);
        return true;
    }
};



//{ Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}


// } Driver Code Ends