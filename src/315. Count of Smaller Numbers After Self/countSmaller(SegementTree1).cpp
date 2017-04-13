// SegementTree
// Tree version

struct SegmentTreeNode{
    int start, end, cnt;
    SegmentTreeNode *left, *right;
    SegmentTreeNode(int a, int b):start(a), end(b), cnt(0), left(NULL),right(NULL){}
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int sz=nums.size();
        if (sz==0) return {};
        vector<int> count;
        int minV=*min_element(nums.begin(), nums.end());
        for(int&n :nums) n -= minV;
        int maxV=*max_element(nums.begin(), nums.end());

        SegmentTreeNode* root=buildTree(0, maxV);
        // cout << root->start << " " << root->end << endl;
        for(int i=0; i<sz; i++)
            updateAdd(root, nums[i]);

        for(int i=0; i<sz; i++){
            updateDel(root, nums[i]);
            count.push_back(query(root, 0, nums[i]-1));
        }
        deleteTree(root);

        return count;
    }

private:
    SegmentTreeNode* buildTree(int start, int end){
        if(start>end) return NULL;
        if (start==end) {
            return new SegmentTreeNode(start, start);
        }

        int mid = (start+end)/2;
        SegmentTreeNode* root = new SegmentTreeNode(start, end);
        root->left = buildTree(start, mid);
        root->right = buildTree(mid+1, end);
        root->cnt = root->left->cnt+root->right->cnt;

        return root;
    }

    void updateAdd(SegmentTreeNode* root, int val){
        if (root==NULL || root->start > val || root->end <val) return;

        if (root->start==val && root->end==val) {
            root->cnt++;
            return;
        }

        int mid = (root->start+root->end)/2;
        if (mid<val) updateAdd(root->right, val);
        else updateAdd(root->left, val);
        root->cnt = root->left->cnt+root->right->cnt;
    }

    void updateDel(SegmentTreeNode* root, int val){
        if (root==NULL || root->start > val || root->end <val) return;

        if (root->start==val && root->end==val) {
            root->cnt--;
            return;
        }

        int mid=(root->start+root->end)/2;
        if(mid<val) updateDel(root->right, val);
        else updateDel(root->left, val);
        root->cnt = root->left->cnt+root->right->cnt;
    }

    int query(SegmentTreeNode* root, int start, int end){
        if (root==NULL) return 0;
        if (root->start==start && root->end==end) return root->cnt;

        int mid = (root->start+root->end)/2;
        if (mid < start) return query(root->right, start,  end);
        else if (mid > end) return query(root->left, start ,end);
        else return query(root->left, start, mid)+query(root->right, mid+1, end);
    }

    void deleteTree(SegmentTreeNode* root){
        if (root==NULL) return;
        if (root->left) deleteTree(root->left);
        if (root->right) deleteTree(root->right);

        delete root;
    }
};
