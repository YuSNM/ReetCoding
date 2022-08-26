class Solution {
public:
    bool reorderedPowerOf2(int n) {
        unordered_set<string> db;
        for (int i = 0; i < 30; i++) 
            db.insert(encoding(1<<i));
        
        return db.count(encoding(n)) > 0;
    }
    string encoding(int n) {
        string code(10, '0');
        for (;n;n/=10) 
            code[n%10]++;
        return code;
    }
};