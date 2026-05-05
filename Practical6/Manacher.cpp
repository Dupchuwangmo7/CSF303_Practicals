#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class ManachersAlgorithm {
private:
    string s;
    string processed;  // String with '#' between characters
    vector<int> palindromeRadius;
    
public:
    // Preprocess the string to handle even-length palindromes
    void preprocessString(string input) {
        s = input;
        processed = "#";
        for (char ch : input) {
            processed += ch;
            processed += '#';
        }
    }
    
    // Find the longest palindromic substring using Manacher's algorithm
    void findLongestPalindrome() {
        int n = processed.length();
        palindromeRadius.assign(n, 0);
        
        int center = 0;    // Center of the rightmost palindrome found so far
        int right = 0;     // Right boundary of the palindrome centered at 'center'
        
        for (int i = 1; i < n - 1; i++) {
            int mirror = 2 * center - i;  // Mirror of i with respect to center
            
            // If i is within the right boundary, we can use previously computed values
            if (i < right) {
                palindromeRadius[i] = min(right - i, palindromeRadius[mirror]);
            }
            
            // Try to expand palindrome centered at i
            while (i + palindromeRadius[i] + 1 < n && 
                   i - palindromeRadius[i] - 1 >= 0 && 
                   processed[i + palindromeRadius[i] + 1] == processed[i - palindromeRadius[i] - 1]) {
                palindromeRadius[i]++;
            }
            
            // If palindrome centered at i extends past right, update center and right
            if (i + palindromeRadius[i] > right) {
                center = i;
                right = i + palindromeRadius[i];
            }
        }
    }
    
    // Get the longest palindromic substring
    string getLongestPalindrome() {
        int maxLen = 0;
        int centerIdx = 0;
        
        for (int i = 1; i < palindromeRadius.size() - 1; i++) {
            if (palindromeRadius[i] > maxLen) {
                maxLen = palindromeRadius[i];
                centerIdx = i;
            }
        }
        
        // Extract substring from original string
        int start = (centerIdx - maxLen) / 2;
        return s.substr(start, maxLen);
    }
    
    // Display all palindromes in the string
    void displayAllPalindromes() {
        cout << "\nAll palindromic substrings:" << endl;
        vector<string> palindromes;
        
        for (int i = 1; i < palindromeRadius.size() - 1; i++) {
            if (palindromeRadius[i] > 0) {
                int start = (i - palindromeRadius[i]) / 2;
                int len = palindromeRadius[i];
                string palindrome = s.substr(start, len);
                
                // Avoid duplicates
                if (find(palindromes.begin(), palindromes.end(), palindrome) == palindromes.end()) {
                    palindromes.push_back(palindrome);
                }
            }
        }
        
        sort(palindromes.begin(), palindromes.end());
        
        if (palindromes.empty()) {
            cout << "  No palindromes found!" << endl;
        } else {
            for (const string& pal : palindromes) {
                cout << "  - \"" << pal << "\" (length: " << pal.length() << ")" << endl;
            }
        }
    }
    
    // Show detailed analysis
    void showAnalysis() {
        cout << "\n--- ANALYSIS ---" << endl;
        cout << "Original string: \"" << s << "\"" << endl;
        cout << "Processed string: \"" << processed << "\"" << endl;
        cout << "String length: " << s.length() << endl;
        cout << "Processed length: " << processed.length() << endl;
        
        cout << "\nPalindrome radius array: ";
        for (int r : palindromeRadius) {
            cout << r << " ";
        }
        cout << endl;
        
        string longest = getLongestPalindrome();
        cout << "\nLongest palindromic substring: \"" << longest << "\"" << endl;
        cout << "Length: " << longest.length() << endl;
    }
};

int main() {
    cout << "========== MANACHER'S ALGORITHM IMPLEMENTATION ==========" << endl;
    
    vector<pair<string, string>> testCases = {
        {"racecar", "Test Case 1: Pure Palindrome"},
        {"babad", "Test Case 2: Multiple Palindromes"},
        {"forgeeksskeegfor", "Test Case 3: Nested Palindromes"},
        {"abaxyz", "Test Case 4: Short Palindrome in String"},
        {"aaaa", "Test Case 5: All Same Characters"},
        {"abacabad", "Test Case 6: Complex Pattern"},
        {"redforgeeksskeegfor", "Test Case 7: Long String"}
    };
    
    for (auto& tc : testCases) {
        cout << "\n" << tc.second << endl;
        cout << "==========================================" << endl;
        
        ManachersAlgorithm manacher;
        manacher.preprocessString(tc.first);
        manacher.findLongestPalindrome();
        
        manacher.showAnalysis();
        manacher.displayAllPalindromes();
    }
    
    // Interactive mode
    cout << "\n\n========== INTERACTIVE MODE ==========" << endl;
    string userInput;
    cout << "Enter a string to find longest palindrome (or 'quit' to exit): ";
    while (getline(cin, userInput) && userInput != "quit") {
        if (!userInput.empty()) {
            ManachersAlgorithm manacher;
            manacher.preprocessString(userInput);
            manacher.findLongestPalindrome();
            manacher.showAnalysis();
            manacher.displayAllPalindromes();
        }
        cout << "\nEnter another string (or 'quit' to exit): ";
    }
    
    return 0;
}
