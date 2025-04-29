// Using sets
// Time Complexity: O(n)
// Space Complexity: O(n)
// Result: Accepted
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode *> list_ptr;
        ListNode * curr_ptr = head; int n = 0;
        while(curr_ptr != nullptr && (n - list_ptr.size()) < 1) {
            list_ptr.insert(curr_ptr); ++n;
            curr_ptr = curr_ptr -> next;}
        if (curr_ptr == nullptr) {return false;}
        return true;
    }
};


// Using Hashmaps
// Time Complexity: O(n)
// Space Complexity: O(n)
// Result: Accepted
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode *, int> list_ptr;
        ListNode * curr_ptr = head;
        while(curr_ptr != nullptr) {
            if (list_ptr[curr_ptr] > 0) {return true;}
            list_ptr[curr_ptr] = 1;
            curr_ptr = curr_ptr -> next;}
        return false;
    }
};



// Floyd Algorithm
// Time Complexity: O(N+K) for K being the cyclic length
// Space Complexity: O(1)
// Result: Accepted
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr) {return false;}

        ListNode* slow = head;
        ListNode* fast = head->next;

        while (slow != fast) {
            if (fast == nullptr || fast -> next == nullptr) return false;
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return true;
    }
};
