// class Solution
// {
// public:
//     bool hasCycle(ListNode *head)
//     {
//         ListNode *slow = head;
//         ListNode *fast = head;
//         while (fast != NULL && fast->next != NULL)
//         {
//             slow = slow->next;
//             fast = fast->next->next;
//             if (slow == fast)
//             {
//                 return true;
//             }
//         }
//         return false;
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
    bool hasCycle(ListNode *head)
    {
        ListNode *slow = head; // Initialize slow pointer
        ListNode *fast = head; // Initialize fast pointer

        // Traverse the list
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;       // Move slow pointer by 1 step
            fast = fast->next->next; // Move fast pointer by 2 steps

            // Check if slow and fast pointers meet
            if (slow == fast)
            {
                return true; // Cycle detected
            }
        }
        return false; // No cycle
    }
};

int main()
{
    // Create a list with a cycle for testing
    ListNode *head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    head->next->next->next->next = head->next; // Creating a cycle

    Solution solution;
    if (solution.hasCycle(head))
    {
        std::cout << "Cycle detected!" << std::endl;
    }
    else
    {
        std::cout << "No cycle." << std::endl;
    }

    return 0;
}
