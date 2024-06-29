// class Solution
// {
// public:
//     ListNode *middleNode(ListNode *head)
//     {
//         ListNode *slow = head;
//         ListNode *fast = head;
//         while (fast != NULL && fast->next != NULL)
//         {
//             slow = slow->next;
//             fast = fast->next->next;
//         }
//         cout << "My " << slow->val << endl;
//         return slow;
//     }




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
    ListNode *middleNode(ListNode *head)
    {
        ListNode *slow = head; // Initialize slow pointer
        ListNode *fast = head; // Initialize fast pointer

        // Traverse the list
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;       // Move slow pointer by 1 step
            fast = fast->next->next; // Move fast pointer by 2 steps
        }

        // Print the value of the middle node
        cout << "Middle node value: " << slow->val << endl;

        return slow; // Return the middle node
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
    ListNode *middle = solution.middleNode(head);

    if (middle)
    {
        cout << "Middle node value: " << middle->val << endl;
    }
    else
    {
        cout << "The list is empty." << endl;
    }
    return 0;
}
