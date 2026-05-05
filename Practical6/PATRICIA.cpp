#include <iostream>
#include <string>
#include <vector>
using namespace std;

// PATRICIA Tree Node
struct PatriciaNode {
    string key;           // The key stored at this node
    string edge_label;    // Edge label from parent
    vector<PatriciaNode*> children;
    bool isEndOfWord;
    
    PatriciaNode(string edge = "", string key = "") 
        : edge_label(edge), key(key), isEndOfWord(false) {}
};

class PATRICIA {
private:
    PatriciaNode* root;
    
public:
    PATRICIA() {
        root = new PatriciaNode("", "");
    }

    ~PATRICIA() {
        destroyNode(root);
    }
    
    // Find the longest common prefix
    int getLCP(const string& s1, const string& s2) {
        int i = 0;
        while (i < s1.length() && i < s2.length() && s1[i] == s2[i]) {
            i++;
        }
        return i;
    }
    
    // Insert a word into PATRICIA tree
    void insert(string word) {
        insertHelper(root, word);
        cout << "Inserted: " << word << endl;
    }
    
private:
    void insertHelper(PatriciaNode* node, string word) {
        // Find a child with edge label that has a common prefix with word
        int childIndex = -1;
        int lcp = 0;
        
        for (int i = 0; i < node->children.size(); i++) {
            int temp_lcp = getLCP(word, node->children[i]->edge_label);
            if (temp_lcp > 0) {
                childIndex = i;
                lcp = temp_lcp;
                break;
            }
        }
        
        // No matching child found, create new child
        if (childIndex == -1) {
            PatriciaNode* newNode = new PatriciaNode(word, word);
            newNode->isEndOfWord = true;
            node->children.push_back(newNode);
            return;
        }
        
        PatriciaNode* child = node->children[childIndex];
        string childLabel = child->edge_label;
        
        // Perfect match - word already exists as a prefix
        if (lcp == childLabel.length() && lcp == word.length()) {
            if (!child->isEndOfWord) {
                child->isEndOfWord = true;
            }
            return;
        }
        
        // Prefix of word matches child label, but word is longer
        if (lcp == childLabel.length()) {
            string remaining = word.substr(lcp);
            insertHelper(child, remaining);
            return;
        }
        
        // Partial match - need to split the edge
        string commonPrefix = childLabel.substr(0, lcp);
        string childRemaining = childLabel.substr(lcp);
        string wordRemaining = word.substr(lcp);
        
        // Create intermediate node
        PatriciaNode* intermediateNode = new PatriciaNode(commonPrefix, commonPrefix);
        
        // Update child
        child->edge_label = childRemaining;
        intermediateNode->children.push_back(child);
        
        // Add new node for remaining word
        if (wordRemaining.length() > 0) {
            PatriciaNode* newNode = new PatriciaNode(wordRemaining, wordRemaining);
            newNode->isEndOfWord = true;
            intermediateNode->children.push_back(newNode);
        } else {
            intermediateNode->isEndOfWord = true;
        }
        
        // Replace child with intermediate node
        node->children[childIndex] = intermediateNode;
    }
    
public:
    // Search for a word in PATRICIA tree
    bool search(string word) {
        return searchHelper(root, word);
    }
    
private:
    bool searchHelper(PatriciaNode* node, string word) {
        if (word.empty()) {
            return node->isEndOfWord;
        }
        
        // Find a child with matching edge label prefix
        for (PatriciaNode* child : node->children) {
            int lcp = getLCP(word, child->edge_label);
            
            if (lcp > 0) {
                // Prefix matches
                if (lcp == child->edge_label.length()) {
                    // Entire edge label matched
                    if (lcp == word.length()) {
                        return child->isEndOfWord;
                    }
                    // Continue searching in child
                    string remaining = word.substr(lcp);
                    return searchHelper(child, remaining);
                }
                // Only partial edge label matched, word not in tree
                return false;
            }
        }
        return false;
    }
    
public:
    // Delete a word from PATRICIA tree
    bool deleteWord(string word) {
        bool found = search(word);
        if (found) {
            deleteHelper(root, word);
            cout << "Deleted: " << word << endl;
            return true;
        }
        cout << "Word not found for deletion: " << word << endl;
        return false;
    }
    
private:
    bool deleteHelper(PatriciaNode* node, string word) {
        if (word.empty()) {
            if (node->isEndOfWord) {
                node->isEndOfWord = false;
                return node->children.empty();
            }
            return false;
        }

        // Find matching child
        for (int i = 0; i < (int)node->children.size(); i++) {
            PatriciaNode* child = node->children[i];
            int lcp = getLCP(word, child->edge_label);

            if (lcp > 0 && lcp == (int)child->edge_label.length()) {
                string remaining = word.substr(lcp);
                bool shouldDelete = deleteHelper(child, remaining);

                if (shouldDelete) {
                    delete child;
                    node->children.erase(node->children.begin() + i);
                    // Re-merge: if parent now has exactly one child and is not a word end,
                    // collapse the single child's edge into the parent's edge
                    if (node->children.size() == 1 && !node->isEndOfWord && !node->edge_label.empty()) {
                        PatriciaNode* only = node->children[0];
                        node->edge_label += only->edge_label;
                        node->isEndOfWord = only->isEndOfWord;
                        node->children = only->children;
                        delete only;
                    }
                    return node->children.empty() && !node->isEndOfWord;
                }
                return false;
            }
        }
        return false;
    }

    void destroyNode(PatriciaNode* node) {
        for (PatriciaNode* child : node->children) {
            destroyNode(child);
        }
        delete node;
    }

public:
    // Display all words
    void displayAll() {
        cout << "\nAll words in PATRICIA Tree:" << endl;
        vector<string> words;
        displayHelper(root, "", words);
        
        if (words.empty()) {
            cout << "PATRICIA tree is empty!" << endl;
        } else {
            for (const string& word : words) {
                cout << "  - " << word << endl;
            }
        }
    }
    
private:
    void displayHelper(PatriciaNode* node, string current, vector<string>& words) {
        if (node->isEndOfWord && !current.empty()) {
            words.push_back(current);
        }
        for (PatriciaNode* child : node->children) {
            displayHelper(child, current + child->edge_label, words);
        }
    }
};

int main() {
    cout << "========== PATRICIA TREE IMPLEMENTATION ==========" << endl;
    
    PATRICIA patricia;
    
    cout << "\n--- INSERT OPERATIONS ---" << endl;
    patricia.insert("bear");
    patricia.insert("bell");
    patricia.insert("bid");
    patricia.insert("bull");
    patricia.insert("stock");
    patricia.insert("stop");
    patricia.insert("test");
    patricia.insert("testing");
    
    patricia.displayAll();
    
    cout << "\n--- SEARCH OPERATIONS ---" << endl;
    vector<string> searchWords = {"bear", "bell", "bed", "bull", "stock", "stop", "test", "testing", "te"};
    for (const string& word : searchWords) {
        bool found = patricia.search(word);
        cout << "Search '" << word << "': " << (found ? "FOUND" : "NOT FOUND") << endl;
    }
    
    cout << "\n--- DELETE OPERATIONS ---" << endl;
    patricia.deleteWord("bell");
    patricia.deleteWord("testing");
    patricia.deleteWord("xyz");  // Non-existent word
    
    patricia.displayAll();
    
    cout << "\n--- SEARCH AFTER DELETION ---" << endl;
    vector<string> postDeleteSearch = {"bell", "bear", "testing", "test", "stock"};
    for (const string& word : postDeleteSearch) {
        bool found = patricia.search(word);
        cout << "Search '" << word << "': " << (found ? "FOUND" : "NOT FOUND") << endl;
    }
    
    return 0;
}
