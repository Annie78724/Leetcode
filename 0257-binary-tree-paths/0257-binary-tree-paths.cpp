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
    void solve(TreeNode* root,string &s,vector<string>&ans)
    {
        if(!root) return;
        if(!root->left and !root->right)
        {
            string olds=s;
            s+=to_string(root->val);
            ans.push_back(s);
            s=olds;
            return;
        }
        string olds=s;
        s+=to_string(root->val)+"->";
        solve(root->left,s,ans);
        solve(root->right,s,ans); 
        s=olds;
  
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        string s="";
        solve(root,s,ans);
        return ans;
    }
};