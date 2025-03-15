/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(nullptr) {}
 * };
 */

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = nullptr;

        while (curr != nullptr) {
            next = curr->next; // Store next node
            curr->next = prev; // Reverse the link
            prev = curr;       // Move prev to current
            curr = next;       // Move to next node
        }
        return prev; // New head of the reversed list
    }
};