class LRUCache {
public:
    LRUCache(int capacity) : capacity(capacity) {}

    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1; // Key not found
        }
        // Move the accessed node to the front of the list
        touch(key);
        return cache[key]->value;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            // Key already exists, update the value and move to front
            cache[key]->value = value;
            touch(key);
            return;
        }
        // If the cache is full, remove the least recently used item
        if (cache.size() == capacity) {
            int lruKey = order.back();
            order.pop_back();
            cache.erase(lruKey);
        }
        // Insert the new key-value pair
        order.push_front(key);
        cache[key] = new Node(key, value);
    }

private:
    struct Node {
        int key;
        int value;
        Node(int k, int v) : key(k), value(v) {}
    };

    int capacity;
    std::list<int> order; // To keep track of the order of keys
    std::unordered_map<int, Node*> cache; // Key to Node mapping

    void touch(int key) {
        order.remove(key);
        order.push_front(key);
    }
};