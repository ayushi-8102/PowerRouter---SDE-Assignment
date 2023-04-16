
import java.util.Scanner;

// Creating Generic Node class for singly linked list
class Node {
    int data;
    Node next;

    Node(int val) {
        data = val;
        next = null;
    }
}

public class Main {
   // Function to find the middle element in a singly linked list
    public static int getMiddle(Node head) {//passing head as reference in getMiddle finction


      //solving using two pointers
  /*We can also solve it using twice traversal and stacks but here I am using two -pointers traversal technique*/
      
        Node s = head;//Here S will act like a slow pointer
        Node f = head;//f will act like a fast pointer

        while (f != null && f.next != null) {
            s = s.next; //slow pointer hving 1 hop traversal
            f = f.next.next; //fast pointer having 2 hops traversal
        }

        return s.data;
    }

   
    public static void main(String[] args) {
        /*A/Q, There are n nodes, so taking input for n nodes */
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number of nodes: ");
        int n = sc.nextInt();
        System.out.println("Enter the values of all each node : ");
        int val = sc.nextInt();
        Node head = new Node(val); //creating the head for the linkedlist
        Node tail = head; 
        for (int i = 1; i < n; i++) {
            val = sc.nextInt();
            tail.next = new Node(val);
            tail = tail.next; //Taking all other values
        }

       // Using getMiddle function to find the middle value in a linked list
  //here head is passed as a reference
        int middle = getMiddle(head);

         // Printing the answer
        System.out.println("The middle element is: " + middle);
    }
}
