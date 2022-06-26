class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        
        int sum = accumulate(cardPoints.begin(), cardPoints.begin() + k, 0);
        int _max = sum;
        
        for (int i = k - 1, j = cardPoints.size() - 1; i >= 0;) 
            if (_max < (sum = sum - cardPoints[i--] + cardPoints[j--]))
                _max = sum;
        return _max;
    }
};