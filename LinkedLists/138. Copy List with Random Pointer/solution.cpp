/* 
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     Node* next;
 *     Node* random;
 *     Node(int x) : val(x), next(NULL), random(NULL) {}
 * };
 */

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        // Step 1: Create a copy of each node and link them together
        Node* current = head;
        while (current) {
            Node* copy = new Node(current->val);
            copy->next = current->next;
            current->next = copy;
            current = copy->next;
        }

        // Step 2: Assign random pointers to the copied nodes
        current = head;
        while (current) {
            if (current->random) {
                current->next->random = current->random->next;
            }
            current = current->next->next;
        }

        // Step 3: Separate the original list and the copied list
        Node* original = head;
        Node* copyHead = head->next;
        Node* copy = copyHead;

        while (original) {
            original->next = original->next->next;
            if (copy->next) {
                copy->next = copy->next->next;
            }
            original = original->next;
            copy = copy->next;
        }

        return copyHead;
    }
};