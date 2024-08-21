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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == nullptr || head -> next == nullptr || left == right) {return head;}

        ListNode* curr = head; int count = 0;
        ListNode* new_list = new ListNode(0);
        ListNode* new_list_iterator = new_list;
        while (curr) {
            ++count;

            if (count < left || count > right) {
                new_list_iterator -> next = curr;
                new_list_iterator = new_list_iterator -> next;  
                curr = curr -> next; }
            else {
                stack<ListNode*> st;
                while(count <= right) {
                    st.push(curr);
                    curr = curr -> next;
                    ++count;
                }
                while(st.size()) {
                    new_list_iterator -> next = st.top();
                    st.pop(); new_list_iterator = new_list_iterator -> next;
                }
            }
        }

        new_list_iterator -> next = nullptr;
        return new_list -> next;
    }
};
