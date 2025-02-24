struct Node {

    Node* links[26];
    bool end = false;

    bool checkIfCharExists(char ch) {
        return links[ch - 'a'] != NULL;
    }

    Node* getLink(char ch) {
        return links[ch - 'a'];
    }

    void putChar(char ch, Node* ref) {
        links[ch - 'a'] = ref;
    }

    void setEnd() {
        end = true;
    }

    bool isEnd() {
        return end;
    }
};

class Trie {

public:
    Node* root;
    Trie() {
        root = new Node();        
    }
    
    void insert(string word) {
        Node* node = root; 
        for(char ch : word) {
            if(!node->checkIfCharExists(ch)) {
                Node* newNode = new Node();
                node->putChar(ch, newNode);
            }
            node = node->getLink(ch);
        }

        node -> setEnd();
        
    }
    
    bool search(string word) {
        Node* node = root;
        for(char ch : word) {
            if(!node->checkIfCharExists(ch)) {
                return false;
            }
            node = node -> getLink(ch);
        }

        if(node -> isEnd()) {
            return true;
        } else {
            return false;
        }
    }
    
    bool startsWith(string prefix) {
        Node* node = root;
        for(char ch : prefix) {
            if(!node->checkIfCharExists(ch)) {
                return false;
            }
            node = node -> getLink(ch);
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */