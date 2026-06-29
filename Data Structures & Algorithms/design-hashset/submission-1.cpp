class MyHashSet {
private:
    static const int SIZE = 1000;
    vector<vector<int>> table;

public:
    MyHashSet() {
        table.resize(SIZE);
    }

    int hash(int key) {
        return key % SIZE;
    }
    
    void add(int key) {
        int h = hash(key);
        for (int x : table[h]) {
            if (x == key) {
                return;
            }        
        }

        table[h].push_back(key);
    }
    
    void remove(int key) {
        int h = hash(key);
        auto &bucket = table[h];
        for (auto it = bucket.begin();  it != bucket.end(); ++it) {
            if (*it == key) {
                bucket.erase(it);
                return;
            }
        }
    }
    
    bool contains(int key) {
        int h = hash(key);
        for (int x : table[h]) {
            if (x == key) {
                return true;
            }
        }

        return false;    
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */