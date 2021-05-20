// { Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


 // } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/


class Solution{
  public:
    //Function to sort the given linked list using Merge Sort.
    void mergesorting(Node **head)
    {
        Node *cur=*head,*first,*second;
        if(!cur || !cur->next)return;
        findmiddle(cur,&first,&second);
        mergesorting(&first);
        mergesorting(&second);
        *head=mergeboth(first,second);
    }
    Node *mergeboth(Node *first,Node *second)
    {
        Node *ans=NULL;
        if(!first) return second;
        else if(!second) return first;
        if(first->data<=second->data)
        {
            ans=first;
            ans->next=mergeboth(first->next,second);
        }
        else{
            ans=second;
            ans->next=mergeboth(first,second->next);
        }
        return ans;
    }
    void findmiddle(Node *cur,Node **first,Node **second)
    {
        Node *fast,*slow;
        slow=cur;
        fast=cur->next;
        while(fast!=NULL)
        {
            fast=fast->next;
            if(fast!=NULL)
            {
                fast=fast->next;
                slow=slow->next;
            }
        }
        *first=cur;
        *second=slow->next;
        slow->next=NULL;
    }
    Node* mergeSort(Node* head) {
       mergesorting(&head);
       return head;
        // your code here
    }
};


// { Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}  // } Driver Code Ends
