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


//SOLUTION 1: RECURSIVE SOLUTION
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

//SOLUTION 2: ITERATIVE SOLUTION
class Solution {
public:
    vector<int> postorder(Node* root) {
        if (root == nullptr) {return {};}
        vector<int> result;
        stack<Node*> st; st.push(root);
        while(st.size()) {
            Node* temp = st.top(); st.pop();
            result.push_back(temp->val);
            for (auto child: temp->children) {st.push(child);}
        }

        reverse(result.begin(), result.end());
        return result;
    }
};
