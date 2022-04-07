//Time: 0 ms (100.00%), Space: 7.4 MB (97.59%) - LeetHub

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
