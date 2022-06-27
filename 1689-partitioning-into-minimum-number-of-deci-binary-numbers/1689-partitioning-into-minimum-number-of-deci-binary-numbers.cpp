class Solution {
public:
    int minPartitions(string n) {
        char _max = 0;
        for (auto c : n) 
            if (c > _max && (_max = c) == '9')
                    return 9;
        return _max - '0';
    }
};