class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int i : stones) pq.push(i);
        for(;pq.size() > 1;) {
            int temp1 = pq.top(); pq.pop();
            int temp2 = pq.top(); pq.pop();
            pq.push(temp1 - temp2);
        }
        return pq.top();
    }
};