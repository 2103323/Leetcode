//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


struct node
{
    int data;
    struct node* next;
    
    node(int x){
        data = x;
        next = NULL;
    }
    
};

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


// } Driver Code Ends
/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
    struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
    }*head;
*/

class Solution
{
    public:
    pair<struct node * , struct node *> solve(struct node *head , int k){
        struct node *current = head;
        struct node *prev = NULL;
        struct node *next = NULL;
        int cnt = 0;
        while(current != NULL && cnt < k){
              next = current -> next;
              current -> next = prev;
              prev = current;
              current = next;
              cnt++;
    }
    
        return {prev , current};
    }
    struct node *reverse (struct node *head , int k)
    { 
          node *prev = NULL;
          node *ans;
          int f = 1;
          while(head)
          {
           pair<struct node * , struct node *> t = solve (head , k);
           if(f) ans = t.first;
           f = 0 ;
           if(prev)
             prev -> next = t.first;
             
           prev = head;
           head = t.second;
           
           
          }
          return ans;
    }
    
};


//{ Driver Code Starts.

/* Drier program to test above function*/
int main(void)
{
    int t;
    cin>>t;
     
    while(t--)
    {
        struct node* head = NULL;
        struct node* temp = NULL;
        int n;
        cin >> n;
         
        for(int i=0 ; i<n ; i++)
        {
            int value;
            cin >> value;
            if(i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }
        
        int k;
        cin>>k;
        
        Solution ob;
        head = ob.reverse(head, k);
        printList(head);
    }
     
    return(0);
}


// } Driver Code Ends