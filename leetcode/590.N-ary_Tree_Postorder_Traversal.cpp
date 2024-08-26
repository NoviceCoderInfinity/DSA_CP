/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    vector<int> post_order_traversal;
public:
    void add_elements(Node* root) {
        if (root == nullptr) {return ;}
        for (auto children : root -> children) {add_elements(children);}
        post_order_traversal.push_back(root -> val);
        return;

    }
    vector<int> postorder(Node* root) {
        add_elements(root);
        return post_order_traversal;
    }
};
