import java.util.*;

public class Main {
public static int findIndexOfCurrentElement(List<Character> OldQueue, int CurrentIndex, List<Character> NewQueue) {
// Finding the index of the Current Index Member in the new Task Queue
char CurrentIndexMem = OldQueue.get(CurrentIndex); // Outputs Current Index Member in the old queue

// Find the index of the Current Index Member in the Old Task Queue
    int PrevIndex = OldQueue.indexOf(CurrentIndexMem); // To find the Index member in the Prev Task Queue
    
    List<Character> UpgradedQueue = new ArrayList<Character>();
    // To remove those elements from the queue which are no longer participating in the Job 
    for (char i : OldQueue) {
        if (NewQueue.contains(i)) {
            UpgradedQueue.add(i);
        } // This will upgrade the queue with only those Index Members which are participating in the Job scheduling.
    }
    
    int UpgradedIndex = UpgradedQueue.indexOf(CurrentIndexMem); // This outputs the current Index Member in the upgraded queue
    
    // Now, if the current member in the old task queue is no longer participating in the job, locate the subsequent available member to serve as the current index member in the updated task queue.
    if (UpgradedIndex == UpgradedQueue.size()) {
        for (int i = 1; i < UpgradedQueue.size(); i++) {
            int index = (PrevIndex + i) % UpgradedQueue.size();
            if (NewQueue.contains(UpgradedQueue.get(index))) {
                return index; // Locate the subsequent available member to serve as the current index member in the updated task queue.
            }
        }
    }
    
    return UpgradedIndex; // Returns the final answer!
}

public static void main(String[] args) {
    // Take input from user to create the old and new task queues
    List<Character> PrevQueue = new ArrayList<Character>();
    List<Character> CurrentQueue = new ArrayList<Character>();
    Scanner input = new Scanner(System.in);
    int currentIndex, n;
    char member;
    System.out.print("Enter the number of members in the old task queue: ");
    n = input.nextInt();
    System.out.print("Enter the members of the old task queue: ");
    for (int i = 0; i < n; i++) {
        member = input.next().charAt(0);
        PrevQueue.add(member);
    }
    System.out.print("Enter the index of the Current Index Member in the old task queue: ");
    currentIndex = input.nextInt();
    System.out.print("Enter the number of members in the new task queue: ");
    n = input.nextInt();
    System.out.print("Enter the members of the new task queue: ");
    for (int i = 0; i < n; i++) {
        member = input.next().charAt(0);
        CurrentQueue.add(member);
    }
    
    // Find the index of the Current Index Member in the new task queue
    int newIndex = findIndexOfCurrentElement(PrevQueue, currentIndex, CurrentQueue);
    
    // Print the index of the Current Index Member in the new task queue
    System.out.println("The index of the Current Index Member in the new task queue is: " + newIndex);
}
}
