#include <bits/stdc++.h>
using namespace std;

// Creating Generic Node class for singly linked list
class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

// Function to find the middle element in a singly linked list
int getMiddle(Node *head) {//passing head as reference in getMiddle finction

  //solving using two pointers
  /*We can also solve it using twice traversal and stacks but here I am using two -pointers traversal technique*/
    Node* s = head;//Here S will act like a slow pointer
    Node* f = head;//f will act like a fast pointer
    
    while (f != NULL && f->next != NULL) {
        s = s->next;//slow pointer hving 1 hop traversal
        f = f->next->next;//fast pointer having 2 hops traversal
    }
    
    return s->data;
}


int main() {
   /*A/Q, There are n nodes, so taking input for n nodes */
    int n, val;
    cout << "Enter the number of nodes:\n ";
    cin >> n;
    cout << "Enter the values of all "<<n<<" nodes : ";
    cin >> val;
    Node* head = new Node(val); //creating the head for the linkedlist
    Node* tail = head; //creating the tail for the linked list
    for (int i = 1; i < n; i++) {
        cin >> val; 
        tail->next = new Node(val); //Taking all other values
        tail = tail->next;
    }
    
    // Using getMiddle function to find the middle value in a linked list
  //here head is passed as a reference
    int middle = getMiddle(head);
    
    // Printing the answer
    cout << "The middle element of the list is: " << middle << endl;
    
    return 0;
}
