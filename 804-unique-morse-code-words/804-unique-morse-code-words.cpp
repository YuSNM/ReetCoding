class Solution {
    
private:
    const vector<string> morse = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_map<string, bool> db;
        for (string& word : words) {
            string temp = "";
            for (auto c : word)
                temp += morse[c-'a'];
            db[temp] = 1;
        }
        return db.size();
    }
    
};