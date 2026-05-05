#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// Trie Node Structure
struct TrieNode {
    unordered_map<char, TrieNode*> children;
    bool isEndOfWord;
    
    TrieNode() : isEndOfWord(false) {}
};

class Trie {
private:
    TrieNode* root;
    
public:
    Trie() {
        root = new TrieNode();
    }

    ~Trie() {
        destroyNode(root);
    }
    
    // Insert a word into the trie
    void insert(string word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (node->children.find(ch) == node->children.end()) {
                node->children[ch] = new TrieNode();
            }
            node = node->children[ch];
        }
        node->isEndOfWord = true;
        cout << "Inserted: " << word << endl;
    }
    
    // Search for a complete word in the trie
    bool search(string word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (node->children.find(ch) == node->children.end()) {
                return false;
            }
            node = node->children[ch];
        }
        return node->isEndOfWord;
    }
    
    // Check if there is any word in the trie that starts with the given prefix
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (char ch : prefix) {
            if (node->children.find(ch) == node->children.end()) {
                return false;
            }
            node = node->children[ch];
        }
        return true;
    }
    
    // Helper function to delete - returns true if node should be deleted
    bool deleteHelper(TrieNode* node, string word, int index) {
        if (index == word.length()) {
            if (!node->isEndOfWord) {
                return false;  // Word doesn't exist
            }
            node->isEndOfWord = false;
            return node->children.empty();  // Return true if node has no children
        }
        
        char ch = word[index];
        if (node->children.find(ch) == node->children.end()) {
            return false;  // Word doesn't exist
        }
        
        TrieNode* childNode = node->children[ch];
        bool shouldDeleteChild = deleteHelper(childNode, word, index + 1);
        
        if (shouldDeleteChild) {
            delete childNode;
            node->children.erase(ch);
            return node->children.empty() && !node->isEndOfWord;
        }
        return false;
    }
    
    // Delete a word from the trie
    bool deleteWord(string word) {
        if (search(word)) {
            deleteHelper(root, word, 0);
            cout << "Deleted: " << word << endl;
            return true;
        }
        cout << "Word not found for deletion: " << word << endl;
        return false;
    }
    
    // Display all words in the trie
    void displayAll() {
        cout << "\nAll words in Trie:" << endl;
        vector<string> words;
        string current = "";
        displayHelper(root, current, words);
        
        if (words.empty()) {
            cout << "Trie is empty!" << endl;
        } else {
            for (const string& word : words) {
                cout << "  - " << word << endl;
            }
        }
    }
    
private:
    void destroyNode(TrieNode* node) {
        for (auto& pair : node->children) {
            destroyNode(pair.second);
        }
        delete node;
    }

    void displayHelper(TrieNode* node, string current, vector<string>& words) {
        if (node->isEndOfWord) {
            words.push_back(current);
        }
        for (auto& pair : node->children) {
            displayHelper(pair.second, current + pair.first, words);
        }
    }
};

int main() {
    cout << "========== TRIE IMPLEMENTATION ==========" << endl;
    
    Trie trie;
    
    cout << "\n--- INSERT OPERATIONS ---" << endl;
    trie.insert("apple");
    trie.insert("app");
    trie.insert("apricot");
    trie.insert("banana");
    trie.insert("band");
    trie.insert("bandana");
    trie.insert("can");
    trie.insert("cat");
    
    trie.displayAll();
    
    cout << "\n--- SEARCH OPERATIONS ---" << endl;
    vector<string> searchWords = {"apple", "app", "apply", "banana", "bat", "cat", "car"};
    for (const string& word : searchWords) {
        bool found = trie.search(word);
        cout << "Search '" << word << "': " << (found ? "FOUND" : "NOT FOUND") << endl;
    }
    
    cout << "\n--- PREFIX SEARCH ---" << endl;
    vector<string> prefixes = {"app", "ban", "ca", "dog"};
    for (const string& prefix : prefixes) {
        bool found = trie.startsWith(prefix);
        cout << "Prefix '" << prefix << "': " << (found ? "EXISTS" : "NOT FOUND") << endl;
    }
    
    cout << "\n--- DELETE OPERATIONS ---" << endl;
    trie.deleteWord("app");
    trie.deleteWord("bandana");
    trie.deleteWord("xyz");  // Non-existent word
    
    trie.displayAll();
    
    cout << "\n--- SEARCH AFTER DELETION ---" << endl;
    vector<string> postDeleteSearch = {"app", "apple", "banana", "bandana"};
    for (const string& word : postDeleteSearch) {
        bool found = trie.search(word);
        cout << "Search '" << word << "': " << (found ? "FOUND" : "NOT FOUND") << endl;
    }
    
    return 0;
}
