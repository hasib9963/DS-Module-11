// class Solution
// {
// public:
//     void reverse(ListNode *&head, ListNode *cur)
//     {
//         if (cur->next == NULL)
//         {
//             head = cur;
//             return;
//         }
//         reverse(head, cur->next);
//         cur->next->next = cur;
//         cur->next = NULL;
//     }
//     ListNode *reverseList(ListNode *head)
//     {
//         if (head == NULL)
//             return head;
//         reverse(head, head);
//         return head;
//     }
// };

#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    // Helper function to reverse the list using recursion
    void reverse(ListNode *&head, ListNode *cur)
    {
        if (cur->next == nullptr)
        {               // Base case: end of the list
            head = cur; // Set the new head
            return;
        }
        reverse(head, cur->next); // Recurse to the end of the list
        cur->next->next = cur;    // Reverse the current node's next pointer
        cur->next = nullptr;      // Set the current node's next pointer to nullptr
    }

    // Public function to reverse the list
    ListNode *reverseList(ListNode *head)
    {
        if (head == nullptr) // Check if the list is empty
            return head;
        reverse(head, head); // Call the helper function to reverse the list
        return head;         // Return the new head of the reversed list
    }
};

int main()
{
    // Create a linked list for testing
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution solution;
    ListNode *newHead = solution.reverseList(head);

    // Print the reversed list
    ListNode *tmp = newHead;
    while (tmp != nullptr)
    {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
    return 0;
}
