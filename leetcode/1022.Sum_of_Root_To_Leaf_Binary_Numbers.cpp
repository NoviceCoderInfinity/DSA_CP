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
    int running_sum_to_leaf(int curr_sum, TreeNode* root) {
        if (root == nullptr) {return 0;}

        curr_sum = (curr_sum << 1) | (root->val);

        if ((root->left == nullptr) && (root->right == nullptr)) {
            return curr_sum;
        }

        return running_sum_to_leaf(curr_sum, root->left) +
                running_sum_to_leaf(curr_sum, root->right);
    }

    int sumRootToLeaf(TreeNode* root) {
        return running_sum_to_leaf(0, root);
    }
};
