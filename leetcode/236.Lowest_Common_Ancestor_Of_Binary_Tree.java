/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    private String encode_node(TreeNode root, TreeNode p, String curr) {
        if (root == p) {return curr;}
        if (root == null) {return "";}

        String left = encode_node(root.left, p, curr + "1");
        String right = encode_node(root.right, p, curr + "2");

        if (left == "") {return right;}
        return left;
    }
    
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        String p_node = encode_node(root, p, "");
        String q_node = encode_node(root, q, "");
        String common = "";

        int len = Math.min(p_node.length(), q_node.length());
        for (int i = 0; i < len; ++i) {
            if (p_node.charAt(i) != q_node.charAt(i)) {break;}
            common += p_node.charAt(i);
        }
        TreeNode temp = root;
        for (int i = 0; i < common.length(); ++i) {
            if (common.charAt(i) == '1') {temp = temp.left;}
            else {temp = temp.right;}
        }
        return temp;
    }
}
