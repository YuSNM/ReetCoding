class Solution {
public:
    int minPartitions(string n) {
        bool box[10] = {0, };
        for (auto c : n) {
            box[c-'0'] = 1;
            if (box[9])
                return 9;
        }
        for (int i = 8; i >= 0; i--)
            if (box[i])
                return i;
        return 0;
    }
};