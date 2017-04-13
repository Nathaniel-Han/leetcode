// binary Search Tree version

struct BinaryTreeNode{
	int val;
	int cnt;
	BinaryTreeNode* left;
	BinaryTreeNode* right;
	BinaryTreeNode(int v): val(v), cnt(1), left(NULL), right(NULL) {}
};

class Tree{
private:
	BinaryTreeNode* root;

public:
	Tree(const int v): root(new BinaryTreeNode(v)){}

	~Tree(){
		freeTree(root);
}

void insert(const int value, int& numsLessThan){
	insertHelper(root, value, numsLessThan);
}

private:
	void insertHelper(BinaryTreeNode* node, const int value, int& numsLessThan){
	if (value < node->val){
	    if (node->left==NULL)
		    node->left = new BinaryTreeNode(value);
	    else
		    insertHelper(node->left, value, numsLessThan);
    }
    else if (value > node->val){
	    numsLessThan += node->cnt - (node->right==NULL?0:node->right->cnt);
	    if (node->right==NULL)
		    node->right = new BinaryTreeNode(value);
	    else
		    insertHelper(node->right, value, numsLessThan);
    }
    else {
	    numsLessThan += node->left==NULL?0:node->left->cnt;
    }

    node->cnt++;
    }

	void freeTree(BinaryTreeNode* node){
		if(node!=NULL){
	        freeTree(node->left);
	        freeTree(node->right);
	        delete node;
        }
    }
};


class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        if (nums.empty()) return {};

        vector<int> ret(nums.size());
        Tree tree(nums.back());
        for(int i=nums.size()-2; i>=0; i--){
	        int numsLessThan =0;
	        tree.insert(nums[i], numsLessThan);
	        ret[i]=numsLessThan;
        }
        return ret;
    }
};
