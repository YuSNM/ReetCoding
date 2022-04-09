
typedef pair<int, int> pii;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        priority_queue<pii, vector<pii>, greater<pii>> pq;         //most frequent elements 저장 , k개를 유지할 예정
        unordered_map<int, int> um;

        for(int i : nums) ++um[i];

        for(auto& i : um) {
            pq.push({i.second, i.first});
            if(pq.size() > k) pq.pop();
        }
        vector<int> ans;

        for(;!pq.empty(); pq.pop()) 
            ans.push_back(pq.top().second);

        return ans;
    }
};