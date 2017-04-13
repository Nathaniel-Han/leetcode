//binary indexed tree version

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int sz=nums.size();
        if (sz==0) return {};
        vector<int> count;
        // int minV=*min_element(nums.begin(), nums.end());
        // for(int& n: nums) n = n-minV+1;
        // int maxV=*max_element(nums.begin(), nums.end());
        vector<int> tmp(nums);
        unordered_map<int, int> helper;
        sort(tmp.begin(), tmp.end());
        for(int i=0;i<sz; i++) helper[tmp[i]]=i+1;

        vector<int> tree(sz+2, 0);

        for(int i=sz-1; i>=0; i--){
            count.insert(count.begin(), get(helper[nums[i]]-1, tree));
            update(helper[nums[i]], tree);
        }
        return count;
    }

private:
    int get(int i, vector<int>& tree){
        int num = 0;
        while(i>0){
            num += tree[i];
            i -= i&(-i);
        }
        return num;
    }

    void update(int i, vector<int>& tree){
        while(i<tree.size()){
            tree[i]++;
            i += i&(-i);
        }
    }
};
