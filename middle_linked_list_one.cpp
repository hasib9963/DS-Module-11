// class Solution
// {
// public:
//     int size(ListNode *head)
//     {
//         ListNode *tmp = head;
//         int cnt = 0;
//         while (tmp != NULL)
//         {
//             cnt++;
//             tmp = tmp->next;
//         }
//         return cnt;
//     }
//     ListNode *middleNode(ListNode *head)
//     {
//         int sz = size(head);
//         ListNode *tmp = head;
//         for (int i = 1; i <= sz / 2; i++)
//         {
//             tmp = tmp->next;
//         }
//         return tmp;
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
    // Function to calculate the size of the linked list
    int size(ListNode *head)
    {
        ListNode *tmp = head;
        int cnt = 0;
        while (tmp != nullptr)
        {
            cnt++;
            tmp = tmp->next;
        }
        return cnt;
    }

    // Function to find the middle node of the linked list
    ListNode *middleNode(ListNode *head)
    {
        int sz = size(head); // Get the size of the linked list
        ListNode *tmp = head;
        for (int i = 1; i <= sz / 2; i++) // Iterate to the middle node
        {
            tmp = tmp->next;
        }
        return tmp; // Return the middle node
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
        std::cout << "Middle node value: " << middle->val << std::endl;
    }
    else
    {
        std::cout << "The list is empty." << std::endl;
    }
    return 0;
}