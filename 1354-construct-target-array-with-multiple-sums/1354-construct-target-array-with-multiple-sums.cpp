class Solution {
public:
    bool isPossible(vector<int>& target) {
        if (target.size() == 1)
            return target[0] == 1;
        priority_queue<int> pq(target.begin(), target.end());
        long long num, sum = accumulate(target.begin(), target.end(), (long long)0);
        
        while ((num = pq.top()) * 2 > sum) {
            if ((sum -= num) <= 1)
                return sum;
            pq.push(num % sum);
            sum += num % sum;
            pq.pop();
        }
        
        return sum == target.size();
    }
};