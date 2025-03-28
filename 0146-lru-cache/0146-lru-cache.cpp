class Node {
public:
    int val;
    int key;
    Node* next = nullptr;
    Node* prev = nullptr;

    Node(int key, int val) {
        this->val = val;
        this->key = key;
    }
};

class LRUCache {
private:
    int cap;
    unordered_map<int, Node*> cache;
    Node* left;
    Node* right;

    void insert(Node* node) {
        Node* prev = right -> prev;
        prev -> next = node;
        node -> prev = prev;
        node -> next = right;
        right -> prev = node;
    }

    void remove(Node* node) {
        Node* prev = node -> prev;
        prev -> next = node -> next;
        node -> next -> prev = prev;
    }


public:
    LRUCache(int capacity) {
        cap = capacity;
        cache.clear();
        left = new Node(0, 0);
        right = new Node(0, 0);
        left->next = right;
        right->prev = left;
    }
    
    int get(int key) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            remove(node);
            insert(node);
            return node->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            remove(cache[key]);
        }

        Node* newNode = new Node(key, value);
        cache[key] = newNode;
        insert(newNode);

        if (cache.size() > cap) {
            Node* lru = left->next;
            remove(lru);
            cache.erase(lru->key);
            delete lru;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */