/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
 class Solution {
    public:
        ListNode* swapPairs(ListNode* head) {
            if (head == nullptr || head->next == nullptr) 
                return head;
            ListNode* cur = head;
            ListNode* newHead = head->next;
            while (cur != nullptr && cur->next != nullptr) {
                ListNode* tmp = cur;
                cur = cur->next;
                tmp->next = cur->next;
                cur->next = tmp;
                cur = tmp->next;
                if (cur != nullptr && cur->next != nullptr) 
                    tmp->next = cur->next;
            }
            return newHead;
        }
    };