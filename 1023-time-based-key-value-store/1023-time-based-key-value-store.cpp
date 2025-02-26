class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> mp; 
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        string result;

        if (mp.find(key) == mp.end()) {
            return "";
        }

        vector<pair<int, string>>& array = mp[key];

        int start = 0;
        int end = array.size() -  1;

        while(start <= end) {
            int mid = start + (end - start) / 2;

            if(array[mid].first <= timestamp) {
                start = mid + 1;
                result = array[mid].second;
            } else {
                end = mid - 1;
            }
        }
        return result;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
*/