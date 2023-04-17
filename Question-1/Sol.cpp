#include<bits/stdc++.h>
using namespace std;

int findIndexOfCurrentElement(vector<char> OldQueue, int CurrentIndex, vector<char> NewQueue) {
    //  finding the index of the Current Index Member in the new Task Queue
    char CurrentIndexMem = OldQueue[CurrentIndex];// Outputs Current Index Member in the old queue
    
     // Find the index of the Current Index Member in the Old Task Queue
    int PrevIndex = find(OldQueue.begin(), OldQueue.end(), CurrentIndexMem) - OldQueue.begin();//to find the Index member in the Prev Task Queue
    
   
    vector<char> UpgradedQueue;
    //To remove those elements from the queue which are no longer participating in the Job 
    for (char i : OldQueue) {
        if (find(NewQueue.begin(), NewQueue.end(), i) != NewQueue.end()) {
            UpgradedQueue.push_back(i);
        }//This will upgrade the queue with only those Index Members which are participating in the Job scheduling.
    }
    
   
    int UpgradedIndex = find(UpgradedQueue.begin(), UpgradedQueue.end(), CurrentIndexMem) - UpgradedQueue.begin();//This outputs ythe current Index Mmber in the upgraded queue
    


  //Now,If the current member in the old task queue is no longer participating in job, locate the subsequent available member to serve as the current index member in the updated task queue.
    
    if (UpgradedIndex == UpgradedQueue.size()) {
        for (int i = 1; i < UpgradedQueue.size(); i++) {
            int index = (PrevIndex + i) % UpgradedQueue.size();
            if (find(NewQueue.begin(), NewQueue.end(), UpgradedQueue[index]) != NewQueue.end()) {
                return index;//locate the subsequent available member to serve as the current index member in the updated task queue.
            }
        }
    }
    
    return UpgradedIndex;//Returns the final answer!
}

int main() {
    // Take input from user to create the old and new task queues
    vector<char> PrevQueue;
    vector<char> CurrentQueue;
    int currentIndex, n;
    char member;
    cout << "Enter the number of members in the old task queue: ";
    cin >> n;
    cout << "Enter the members of the old task queue: ";
    for (int i = 0; i < n; i++) {
        cin >> member;
        PrevQueue.push_back(member);
    }
    cout << "Enter the index of the Current Index Member in the old task queue: ";
    cin >> currentIndex;
    cout << "Enter the number of members in the new task queue: ";
    cin >> n;
    cout << "Enter the members of the new task queue: ";
    for (int i = 0; i < n; i++) {
        cin >> member;
        CurrentQueue.push_back(member);
    }
    
    // Find the index of the Current Index Member in the new task queue
    int newIndex = findIndexOfCurrentElement(PrevQueue, currentIndex, CurrentQueue);
    
    // Print the index of the Current Index Member in the new task queue
    cout << "The index of the Current Index Member in the new task queue is: " << newIndex << endl;
    
    return 0;
}
