class Solution {
public:
    bool reorderedPowerOf2(int n) {
        unordered_map<string, bool> db;
        for (int i = 0; i < 30; i++) 
            db[encoding(1<<i)]=1;
        
        return db.count(encoding(n)) > 0;
    }
    string encoding(int n) {
        string code(10, '0');
        for (;n;n/=10) 
            code[n%10]++;
        return code;
    }
};
