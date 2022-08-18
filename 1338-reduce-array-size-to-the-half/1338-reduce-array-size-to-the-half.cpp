class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> db;
        priority_queue<int> pq;
        
        for (int i : arr)
            db[i]++;
        for (auto& p : db)
            pq.push(p.second);
        
        int ans = 0;
        
        for(int target = arr.size() / 2, sum = arr.size(); sum > target; ans++, pq.pop()) 
            sum -= pq.top();
        
        return ans;
    }
};