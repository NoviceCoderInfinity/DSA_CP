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
    long long total_sum = 0;
    long long max_prod = 0;

    long long dfs(TreeNode* root) {
        if (root == nullptr) return 0;

        long long current_subtree_sum = root->val + dfs(root->left) + dfs(root->right);
        long long current_product = (total_sum - current_subtree_sum) * current_subtree_sum;
        
        if (current_product > max_prod) {
            max_prod = current_product;
        }

        return current_subtree_sum;
    }

    long long get_total_sum(TreeNode* root) {
        if (root == nullptr) return 0;
        return root->val + get_total_sum(root->left) + get_total_sum(root->right);
    }

    int maxProduct(TreeNode* root) {
        total_sum = get_total_sum(root);
        
        max_prod = 0;
        dfs(root);

        return (int)(max_prod % 1000000007);
    }
};