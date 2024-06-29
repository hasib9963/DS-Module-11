// class Solution
// {
// public:
//     void deleteNode(ListNode *node)
//     {
//         node->val = node->next->val;
//         ListNode *deleteNode = node->next;
//         node->next = node->next->next;
//         delete deleteNode;
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
    // Function to delete a node given only access to that node
    void deleteNode(ListNode *node)
    {
        if (node == nullptr || node->next == nullptr)
        {
            // This function assumes the node is not the tail
            return;
        }
        node->val = node->next->val;       // Copy value of next node to current node
        ListNode *deleteNode = node->next; // Save the next node to be deleted
        node->next = node->next->next;     // Bypass the next node
        delete deleteNode;                 // Delete the next node to free memory
    }
};

int main()
{
    // Create a linked list for testing
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    // Assume we want to delete the node with value 3
    Solution solution;
    solution.deleteNode(head->next->next); // Passing the node with value 3

    // Print the modified list
    ListNode *tmp = head;
    while (tmp != nullptr)
    {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
    return 0;
}
