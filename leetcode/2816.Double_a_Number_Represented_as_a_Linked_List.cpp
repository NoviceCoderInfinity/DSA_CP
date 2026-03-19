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
// One pass two pointers approach
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = nullptr;

        int carry = 0;
        int dbl_val = 0;
        while (curr) {
            dbl_val = curr->val * 2;
            carry = dbl_val / 10;
            dbl_val = dbl_val % 10;

            curr->val = dbl_val;
            if (carry) {
                if (prev == nullptr) {
                    head = new ListNode(carry, curr);
                } else {
                    prev->val += 1;
                }
            }

            prev = curr;
            curr = curr->next;
        }
        return head;
    }
};

// One Pass Single Pointer Approach
// Key Idea (single pointer and one pass approach)
// We need to update the prev only when the current one doubling produces a carry
// a carry will be encountered only when the value is >= 5
// Time Complexity: O(n)
// Space Complexity: O(1) 
class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        if (head == nullptr) return head;
        if (head->val >= 5) {
            head = new ListNode(0, head);
        }

        ListNode* curr = head;
        while (curr) {
            int tmp = curr->val * 2;
            if (curr->next) {
                tmp += (curr->next->val >= 5);
            }
            curr->val = tmp % 10;
            curr = curr->next;
        }
        return head;
    }
};
