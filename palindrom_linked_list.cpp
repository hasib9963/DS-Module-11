// class Solution
// {
// public:
//     void insert_tail(ListNode *&head, ListNode *&tail, int val)
//     {
//         ListNode *newNode = new ListNode(val);
//         if (head == NULL)
//         {
//             head = newNode;
//             tail = newNode;
//             return;
//         }
//         tail->next = newNode;
//         tail = tail->next;
//     }
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
//     void print_list(ListNode *head)
//     {
//         ListNode *tmp = head;
//         while (tmp != NULL)
//         {
//             cout << tmp->val << " ";
//             tmp = tmp->next;
//         }
//     }
//     bool isPalindrome(ListNode *head)
//     {
//         ListNode *newHead = NULL;
//         ListNode *newTail = NULL;
//         ListNode *tmp = head;
//         while (tmp != NULL)
//         {
//             insert_tail(newHead, newTail, tmp->val);
//             tmp = tmp->next;
//         }
//         reverse(newHead, newHead);
//         print_list(newHead);
//         tmp = head;
//         ListNode *tmp2 = newHead;
//         while (tmp != NULL)
//         {
//             if (tmp->val != tmp2->val)
//             {
//                 return false;
//             }
//             tmp = tmp->next;
//             tmp2 = tmp2->next;
//         }
//         return true;
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
    // Function to insert a new node at the tail of the list
    void insert_tail(ListNode *&head, ListNode *&tail, int val)
    {
        ListNode *newNode = new ListNode(val);
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
            return;
        }
        tail->next = newNode;
        tail = tail->next;
    }

    // Function to reverse the list using recursion
    void reverse(ListNode *&head, ListNode *cur)
    {
        if (cur->next == nullptr)
        {
            head = cur;
            return;
        }
        reverse(head, cur->next);
        cur->next->next = cur;
        cur->next = nullptr;
    }

    // Function to print the list
    void print_list(ListNode *head)
    {
        ListNode *tmp = head;
        while (tmp != nullptr)
        {
            cout << tmp->val << " ";
            tmp = tmp->next;
        }
        cout << endl;
    }

    // Function to check if the list is a palindrome
    bool isPalindrome(ListNode *head)
    {
        ListNode *newHead = nullptr;
        ListNode *newTail = nullptr;
        ListNode *tmp = head;

        // Create a new list with the same values as the original list
        while (tmp != nullptr)
        {
            insert_tail(newHead, newTail, tmp->val);
            tmp = tmp->next;
        }

        // Reverse the new list
        reverse(newHead, newHead);

        // Print the reversed list (for debugging purposes)
        print_list(newHead);

        // Compare the original list and the reversed list
        tmp = head;
        ListNode *tmp2 = newHead;
        while (tmp != nullptr)
        {
            if (tmp->val != tmp2->val)
            {
                return false;
            }
            tmp = tmp->next;
            tmp2 = tmp2->next;
        }
        return true;
    }
};

int main()
{
    // Create a linked list for testing
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);

    Solution solution;
    bool result = solution.isPalindrome(head);

    if (result)
    {
        cout << "The list is a palindrome." << endl;
    }
    else
    {
        cout << "The list is not a palindrome." << endl;
    }
    return 0;
}
