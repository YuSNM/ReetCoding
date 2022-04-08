//Time: 44 ms (56.99%), Space: 19.9 MB (63.09%) - LeetHub

class KthLargest {
    priority_queue<int, vector<int>, greater<>> pq;
    int k;

public:
    KthLargest(int k, vector<int> &nums) : k(k) {
        for(int i : nums) pq.push(i);
    }
    
    int add(int val) {
        pq.push(val);
        while(pq.size() > k) pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
