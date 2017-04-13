// SegmentTree
// array version
// Note: in the query procedure, query range[qs, qe] never change.

class Solution{
public:
    vector<int> countSmaller(vector<int>& nums){
        int sz=nums.size();
        if (sz==0) return {};
        vector<int> count;
        vector<int> tmp(nums);
        unordered_map<int, int> helper;
        sort(tmp.begin(), tmp.end());
        for(int i=0; i<sz; i++){
            helper[tmp[i]]=i;
        }

        vector<int> st;
        int x=(int)ceil(log2(nums.size()));
        int max_size = 2*pow(2, x)-1;
        st.resize(max_size, 0);

        for(int i=0;i<sz; i++)
            update(st, 0, sz-1, helper[nums[i]], 0, 1);

        // for(int i=0;i<st.size(); i++)
        //     printf("i=%i, val=%i\n", i, st[i]);

        for(int i=0; i<sz;i++){
            update(st, 0, sz-1, helper[nums[i]], 0, -1);
            count.push_back(query(st, 0, helper[nums[i]]-1, 0, sz-1,0));
        }

        return count;
    }

    void update(vector<int>& st, int start, int end, int val, int index, int flag){
        if (val<start || val>end) return;

        if (start==val && end==val){
            st[index] += flag;
            return;
        }

        int mid = start+(end-start)/2;
        update(st, start, mid, val, 2*index+1, flag);
        update(st, mid+1, end, val, 2*index+2, flag);

        st[index]=st[2*index+1]+st[2*index+2];
    }

    int query(vector<int>& st, int qs, int qe, int ss, int se, int index){
        if (index>=st.size()) return 0;
        if (se<qs && qe<ss) return 0;
        if (qs <= ss && qe >= se)
            return st[index];

        if (ss==qs && se==qe) return st[index];

        int mid = ss+(se-ss)/2;
        if (mid<qs) return query(st, qs, qe, mid+1, se, 2*index+2);
        else if (mid>qe) return query(st, qs, qe, ss, mid,2*index+1);
        else return query(st, qs, qe, ss, mid,2*index+1)+query(st,qs, qe, mid+1, se, 2*index+2);
    }

};
