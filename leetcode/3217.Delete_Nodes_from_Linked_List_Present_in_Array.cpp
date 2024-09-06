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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        set<int> to_delete(nums.begin(), nums.end());
        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy;
        ListNode* curr = head;
        while(curr) {
            int v = curr -> val;
            if (to_delete.find(v) != to_delete.end()) {prev -> next = curr -> next;}
            else {prev = curr;}
            curr = curr -> next;
        }
        ListNode* new_head = dummy -> next;
        delete dummy;
        return new_head;
    }
};
