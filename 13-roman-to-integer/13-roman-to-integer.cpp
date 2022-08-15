class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> db;
        db['I'] = 1, db['V'] = 5, db['X'] = 10, db['L'] = 50;
        db['C'] = 100, db['D'] = 500, db['M'] = 1000;
        
        int sum = 0, last = 0;
        for (auto c : s) {
            sum += db[c];
            if (last * 5 == db[c] || last * 10 == db[c])
                sum -= 2 * last;
            last = db[c];
        }
        return sum;
    }
};