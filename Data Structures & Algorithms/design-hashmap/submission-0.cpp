class MyHashMap {
private:
    static const int SIZE = 1000;
    vector<list<pair<int, int>>> table;

public:
    MyHashMap() {
        table.resize(SIZE);
    }

    int hash(int key) {
        return key % SIZE;
    }
    
    void put(int key, int value) {
        int p = hash(key);
        for (auto &x : table[p]) {
            if (x.first == key) {
                x.second = value;
                return;
            }
        }

        table[p].push_back({key, value});
    }
    
    int get(int key) {
        int p = hash(key);
        for (auto &x : table[p]) {
            if (x.first == key) {
                return x.second;
            }
        }

        return -1;        
    }
    
    void remove(int key) {
        int p = hash(key);
        for (auto it = table[p].begin(); it != table[p].end(); ++it) {
            if (it->first == key) {
                table[p].erase(it);
                return;
            }
        }         
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */