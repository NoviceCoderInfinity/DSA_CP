/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    string encode_node(TreeNode* root, TreeNode* p, string curr) {
        if (root == p) {return curr;}
        if (root == nullptr) {return "";}
        string left = encode_node(root -> left, p, curr + "1");
        string right = encode_node(root -> right, p, curr + "2");
        if (left == "") {return right;}
        return left;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        string p_node = encode_node(root, p, "");
        string q_node = encode_node(root, q, "");
        string common = "";
        int len = min(p_node.size(), q_node.size());
        for (int i = 0; i < len; ++i) {
            if (p_node[i] != q_node[i]) {break;}
            common += p_node[i];
        }
        TreeNode* temp = root;
        for (char c: common) {
            if (c == '1') {temp = temp -> left;}
            else {temp = temp -> right;}
        }
        return temp;
    }
};
