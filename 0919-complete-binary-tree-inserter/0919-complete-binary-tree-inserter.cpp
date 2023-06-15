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
class CBTInserter {
public:
    queue<TreeNode*> q;
    TreeNode* mark;
    TreeNode* main;
    CBTInserter(TreeNode* root) {
        mark = root;
        main = root;
        q.push(root);
        bool chk = true;
        while(!q.empty()){
            int n = q.size();
            mark = q.front();
            for(int i=0; i<n; i++){
                auto temp = q.front();
                
                
                
                if(temp->left){
                    q.push(temp->left);
                }
                else{
                    mark = temp;
                    chk = false;
                    break;
                }
                if(temp->right){
                    q.push(temp->right);
                }
                else{
                    mark = temp;
                    chk = false;
                    break;
                }
                q.pop();
            }
            if(!chk){
                break;
            }
        }
    }
    
    int insert(int val) {
        TreeNode* add = new TreeNode(val);
        if(!mark->left){
            mark->left = add;
            q.push(add);
        }
        else if(!mark->right){
            mark->right = add;
            q.push(add);
            q.pop();
        }
        else{
            mark = q.front();
            if(!mark->left){
                mark->left = add;
                q.push(add);
            }
            else if(!mark->right){
                mark->right = add;
                q.push(add);
                q.pop();
            }
        }
        return mark->val;
    }
    
    TreeNode* get_root() {
        return main;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */