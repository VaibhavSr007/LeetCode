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
class BSTIterator {
public:
    vector<int> v;
    int i;
    void in(TreeNode* root, vector<int>& v){
        if(!root){
            return ;
        }
        in(root->left,v);
        v.push_back(root->val);
        in(root->right,v);
    }
    
    BSTIterator(TreeNode* root) {
        in(root,v);
        cout<<endl;
        i=-1;
    }
    
    int next() {
        i++;
        return v[i];
    }
    
    bool hasNext() {
        cout<<i<<":"<<v.size()<<" ";
        if(i+1<v.size()){
            return true;
        }
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */