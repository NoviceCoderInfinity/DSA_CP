/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr) {return (subRoot == nullptr);}
        if (isSame(root, subRoot)) {return true;}
        return (isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot));
    }

    bool isSame(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr && subRoot == nullptr) {return true;}
        if ((root == nullptr || subRoot == nullptr) ||
            (root -> val != subRoot -> val)) {return false;}
        return isSame(root->left, subRoot->left) && isSame(root->right, subRoot->right);
    }
};
