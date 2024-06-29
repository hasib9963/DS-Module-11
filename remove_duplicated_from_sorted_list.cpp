// class Solution
// {
// public:
//     ListNode *deleteDuplicates(ListNode *head)
//     {
//         if (head == NULL)
//             return head;
//         ListNode *tmp = head;
//         while (tmp->next != NULL)
//         {
//             if (tmp->val == tmp->next->val)
//             {
//                 ListNode *deleteNode = tmp->next;
//                 tmp->next = tmp->next->next;
//                 delete deleteNode;
//             }
//             if (tmp->next == NULL)
//                 break;
//             else if (tmp->val != tmp->next->val)
//             {
//                 tmp = tmp->next;
//             }
//         }
//         return head;
//     }
// };



#include <bits/stdc++.h>
using namespace std;
class ListNode {
public:
    int val;
    ListNode* next;
    
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) // Check if the list is empty
            return head;
        
        ListNode* tmp = head; // Initialize the pointer to the head
        
        // Traverse the list
        while (tmp->next != nullptr) {
            if (tmp->val == tmp->next->val) { // Check for duplicates
                ListNode* deleteNode = tmp->next; // Node to be deleted
                tmp->next = tmp->next->next; // Skip the duplicate node
                delete deleteNode; // Free memory of the duplicate node
            } else {
                tmp = tmp->next; // Move to the next node if no duplicate
            }
        }
        
        return head; // Return the modified list
    }
};

int main() {
    // Create a sorted linked list for testing
    ListNode* head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(3);
    
    Solution solution;
    ListNode* newHead = solution.deleteDuplicates(head);
    
    // Print the modified list
    ListNode* tmp = newHead;
    while (tmp != nullptr) {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
    
    // Note: In a real application, you'd want to free the allocated memory.
    // Here, we skip that for simplicity as the program is about to end.

    return 0;
}