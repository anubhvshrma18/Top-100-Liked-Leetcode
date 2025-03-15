#include <vector>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Compare {
public:
    bool operator() (ListNode* a, ListNode* b) {
        return a->val > b->val; // Min-heap based on node value
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Compare> minHeap;

        // Push the head of each list into the min-heap
        for (ListNode* list : lists) {
            if (list) {
                minHeap.push(list);
            }
        }

        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (!minHeap.empty()) {
            ListNode* node = minHeap.top();
            minHeap.pop();
            tail->next = node; // Append the smallest node to the merged list
            tail = tail->next; // Move the tail pointer

            if (node->next) {
                minHeap.push(node->next); // Push the next node from the same list
            }
        }

        return dummy.next; // Return the merged list, which starts from dummy.next
    }
};