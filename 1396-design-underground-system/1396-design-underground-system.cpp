class UndergroundSystem {
    unordered_map<int, pair<string, int>> CI_db;
    unordered_map<string, unordered_map<string, pair<int, int>>> map;
public:
    UndergroundSystem()  {
    }
    
    void checkIn(int id, string stationName, int t) {
        CI_db[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        
        string& startStation = CI_db[id].first;
        int start_time = CI_db[id].second;
        
        map[startStation][stationName].first += t - start_time;
        map[startStation][stationName].second++;
    }
    
    double getAverageTime(string startStation, string endStation) {
        pair<int, int> sumc = map[startStation][endStation];
        return (double)sumc.first / sumc.second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */