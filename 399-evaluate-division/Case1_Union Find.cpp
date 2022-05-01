//Time: 0 ms (100.00%), Space: 8.1 MB (89.56%) - LeetHub

class Solution {
    
private:
    struct node {
        node* parent;
        double value = 0.0;
        
        node(double a) : value(a) {
            parent = this;
        }
    };
    
    unordered_map<string, node*> map;
    
    node* Findp(node* x) {
        if (x->parent == x)
            return x;
        return x->parent = Findp(x->parent);
    }
    
    void Union(node* a, node* b, double n, unordered_map<string, node*>& map) {
        
        node *pa = Findp(a), *pb = Findp(b);
        double r = b->value * n / a->value;
        
        for (auto& i : map)
            if (Findp(i.second) == pa)
                i.second->value *= r;
        pa->parent = pb;  
    }
    
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        vector<double> ans;
        
        for (int i = 0; i < values.size(); i++) {
            
            string& a = equations[i][0];
            string& b = equations[i][1];
            
            
            //a와 b의 중복 제거
            if (!map.count(a) && !map.count(b)) {
                map[a] = new node(values[i]);
                map[b] = new node(1.0);
                map[a]->parent = map[b];
            }
            else if (!map.count(a)) {
                map[a] = new node(values[i] * map[b]->value);
                map[a]->parent = map[b];
            }
            else if (!map.count(b)) {
                map[b] = new node(map[a]->value / values[i]);
                map[b]->parent = map[a];
            }
            else {
                Union(map[a], map[b], values[i], map);
            }
            
        }
        
        for (auto q : queries) {
            if (!map.count(q[0]) || !map.count(q[1]) || Findp(map[q[0]]) != Findp(map[q[1]]))
                ans.push_back(-1);
            else
                ans.push_back(map[q[0]]->value / map[q[1]]->value);
        }
        
        return ans;
    }
};
