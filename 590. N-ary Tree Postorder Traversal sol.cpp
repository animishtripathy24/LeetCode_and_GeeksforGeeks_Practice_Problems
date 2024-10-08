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
private:
    void postOrder(Node* root,vector<int>&ans)
    {
        if( root == NULL)
        {
            return;
        }
        for(auto &it : root->children)
        {
            postOrder(it,ans);
        }
        ans.push_back(root->val);
    }
public:
    vector<int> postorder(Node* root) {
        if(root == NULL)
        {
            return {};
        }
        vector<int>ans;
        postOrder(root,ans);
        return ans;  
    }
};
