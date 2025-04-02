class Trie {
public:
    Trie() : root(make_unique<TrieNode>()) {

    } 
    
    void insert(string word) {
        TrieNode* node = root.get();
        for (char c : word) {
            int index = c - 'a'; // Map character to index (0-25)
            if (!node->children[index]) {
                node->children[index] = make_unique<TrieNode>();
            }
            node = node->children[index].get();
        }
        node->isEnd = true; // Mark the end of the word
    }
    
    bool search(string word) {
        const TrieNode* node = root.get();
        for (char c : word) {
            int index = c - 'a';
            if (!node->children[index]) {
                return false; // Word not found
            }
            node = node->children[index].get();
        }
        return node->isEnd; // Return true if it's the end of a valid word
    }
    
    bool startsWith(string prefix) {
        const TrieNode* node = root.get();
        for (char c : prefix) {
            int index = c - 'a';
            if (!node->children[index]) {
                return false; // Prefix not found
            }
            node = node->children[index].get();
        }
        return true; // Prefix exists
    }
private:
    struct TrieNode {
        bool isEnd = false;
        array<unique_ptr<TrieNode>, 26> children = {}; // Use std::array for fixed-size storage
    };

    unique_ptr<TrieNode> root; // Root node managed by unique_ptr
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */