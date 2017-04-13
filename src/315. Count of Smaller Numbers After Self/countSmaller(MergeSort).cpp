class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int sz = nums.size();
        vector<int> count(sz, 0);
        vector<int> indices(sz);
        iota(indices.begin(), indices.end(), 0);

        mergesort(nums, indices, count, 0, sz-1);
        return count;
    }

    void mergesort(vector<int>& nums, vector<int>& indices, vector<int>& count, int start, int end){
        if (end<=start) return;

        int mid=(start+end)/2;
        mergesort(nums, indices, count, start, mid);
        mergesort(nums, indices, count, mid+1, end);

        merge(nums, indices, count, start, end);
    }

    void merge(vector<int>& nums, vector<int>& indices, vector<int>& count, int start, int end){
        int mid=(start+end)/2;
        int left_index=start;
        int right_index=mid+1;
        int rightcount=0;
        vector<int> new_indices(end-start+1);

        int sort_index=0;
        while(left_index<=mid && right_index<=end){
            if (nums[indices[right_index]] <nums[indices[left_index]]){
                new_indices[sort_index++]=indices[right_index++];
                rightcount++;
            } else {
                new_indices[sort_index++]=indices[left_index];
                count[indices[left_index++]] += rightcount;
            }
        }
        while (left_index<=mid) {
            new_indices[sort_index++]=indices[left_index];
            count[indices[left_index++]] += rightcount;
        }

        while (right_index<=end)
            new_indices[sort_index++]=indices[right_index++];

        for(int i=start; i<=end; i++){
            indices[i]=new_indices[i-start];
        }
    }
};
