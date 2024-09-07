/**
 * Definition for polynomial singly-linked list.
 * struct PolyNode {
 *     int coefficient, power;
 *     PolyNode *next;
 *     PolyNode(): coefficient(0), power(0), next(nullptr) {};
 *     PolyNode(int x, int y): coefficient(x), power(y), next(nullptr) {};
 *     PolyNode(int x, int y, PolyNode* next): coefficient(x), power(y), next(next) {};
 * };
 */

class Solution {
public:
    PolyNode* addPoly(PolyNode* poly1, PolyNode* poly2) {
        if (poly1 == nullptr && poly2 == nullptr) {return nullptr;}
        PolyNode* dummy = new PolyNode();
        PolyNode* curr = dummy;
        while(poly1 && poly2) {
            if (poly1->power < poly2->power) {
                curr -> next = poly2; poly2 = poly2 -> next; curr = curr-> next;
            }
            else if (poly1->power > poly2->power) {
                curr -> next = poly1; poly1 = poly1 -> next; curr = curr-> next;
            }
            else {
                int c_total = poly1->coefficient+poly2->coefficient;
                if (c_total) {
                    curr->next = new PolyNode(c_total, poly1->power, poly1);
                    curr = curr-> next;
                }
                poly1 = poly1 -> next;
                poly2 = poly2 -> next;
            }
        }
        while(poly1) {
            curr -> next = poly1; curr = curr -> next; poly1 = poly1 -> next;
        }
        while(poly2) {
            curr -> next = poly2; curr = curr -> next; poly2 = poly2 -> next;
        }
        curr -> next = nullptr;
        return dummy->next;
    }
};
