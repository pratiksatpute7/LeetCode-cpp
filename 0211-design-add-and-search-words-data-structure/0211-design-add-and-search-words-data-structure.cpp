struct Node {
    Node* links[26];
    bool end = false;

    bool isEnd() {
        return end;
    }

    void setEnd() {
        end = true;
    }

    Node** getAllLinks() {
        return links;
    }

    bool containsChar(char ch) {
        return links[ch - 'a'] != NULL;
    }

    Node* getLinkNode(char ch) {
        return links[ch - 'a'];
    }

    void addLinks(char ch, Node* newNode) {
        links[ch - 'a'] = newNode;
    }
};

class WordDictionary {
public:
    Node* root;

    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* node = root;
        for(char ch : word) {

            if(!node -> containsChar(ch)) {
                Node* newNode = new Node();
                node -> addLinks(ch, newNode);
            }
            node = node -> getLinkNode(ch);
        }

        node -> setEnd();
        
    }

    bool search(string word) {
        return searchHelper(word, root, 0);
    }
    
    bool searchHelper(string word, Node* node, int index) {
        if (!node) return false;

        if (index == word.size()) {
            return node->isEnd();
        }

        char ch = word[index];
        
        if (ch == '.') {
            Node** links = node->getAllLinks();
            for (int i = 0; i < 26; i++) {
                if (links[i] != NULL) {
                    if (searchHelper(word, links[i], index + 1)) {
                        return true;
                    }
                }
            }
            return false;
        } else {
            if(!node -> containsChar(ch)) {
                return false;
            }
            node = node -> getLinkNode(ch);
            return searchHelper(word, node, index + 1);
        }

        return node -> isEnd();
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */