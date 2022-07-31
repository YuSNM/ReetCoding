class NumArray {

private:
    int N;
    vector<int> seg;
public:
    NumArray(vector<int>& nums) {
        N = nums.size();
        seg.assign(N*4, 0);
        
        function<void(int, int, int)> buildSegment = [&nums, this, &buildSegment] (int idx, int left, int right) -> void{
            if (left == right) {
                seg[idx] = nums[right];
                return;
            }
            int mid = (left + right) / 2;

            buildSegment(idx*2, left, mid);
            buildSegment(idx*2+1, mid+1, right);
            seg[idx] = seg[idx*2] + seg[idx*2+1];
        };
        
        buildSegment(1, 0, N-1);
    }
    
    
    void update(int index, int val) {
        
        function<void(int, int, int)> rec = [index, val, this, &rec] (int idx, int left, int right) {
            if (left == right) {
                seg[idx] = val;
                return;
            }
            int mid = (left + right) / 2;

            if (index <= mid)
                rec(idx*2, left, mid);
            else
                rec(idx*2+1, mid+1, right);
            
            seg[idx] = seg[idx*2] + seg[idx*2+1];
        };
        
        rec(1, 0, N-1);
    }
    
    int sumRange(int be, int en) {
        function<int(int, int, int)> divCon = [&be, &en, this, &divCon] (int idx, int left, int right){
            if (be <= left && right <= en)
                return seg[idx];
            else if (en < left || right < be)
                return 0;
            
            int mid = (left+right)/2;
            return divCon(idx*2, left, mid) + divCon(idx*2+1, mid+1, right);
        };
        
        return divCon(1, 0, N-1);
    }
    
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */