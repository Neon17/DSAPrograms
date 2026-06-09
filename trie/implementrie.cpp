/** 208. Implement Trie (Prefix Tree) (Leetcode Medium)
 * 
 * A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. 
 * There are various applications of this data structure, such as autocomplete and spellchecker.
 * 
 * Implement the Trie class:
 * 
 * Trie() Initializes the trie object.
 * void insert(String word) Inserts the string word into the trie.
 * boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
 * boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.
 * 
 * Example 1:

Input
["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
[[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
Output
[null, null, true, false, true, null, true]

Explanation
Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // return True
trie.search("app");     // return False
trie.startsWith("app"); // return True
trie.insert("app");
trie.search("app");     // return True
 

Constraints:

1 <= word.length, prefix.length <= 2000
word and prefix consist only of lowercase English letters.
At most 3 * 104 calls in total will be made to insert, search, and startsWith.

Topics: Hash Table
String
Design
Trie
 * 
 */


#include<iostream>
using namespace std;

struct Tri{
    char val;
    Tri* next[26];
    bool isWord;
    Tri():val('\0'), isWord(false), next{nullptr}{}
    Tri(char c): val(c), next{nullptr}, isWord(false){}
};

class Trie {
    public:
        Tri* root;
        Trie() {root = new Tri();}

        void insert(string word){
            Tri* curr = root;
            for (int i=0;i<word.size();i++){
                if (curr->next[word[i]-'a']) curr = curr->next[word[i]-'a'];
                else {
                    curr->next[word[i]-'a'] = new Tri(word[i]);
                    curr = curr->next[word[i]-'a'];
                }
            }
            curr->isWord = true;
        }

        bool search(string word){
            Tri* curr = root;
            for (int i=0;i<word.size();i++){
                curr = curr->next[word[i]-'a'];
                if (!curr) return false;
            }
            return curr->isWord;
        }

        bool startsWith(string word){
            // I think it may suggest is there any word that starts with that parameter word
            Tri* curr = root;
            for (int i=0;i<word.size();i++){
                curr = curr->next[word[i]-'a'];
                if (!curr) return false;
            }
            return true;
        }
};

int main(){
    
    Trie t;
    t.insert("apple");
    cout << t.search("app") << endl; // returns false
    cout << t.startsWith("app") << endl; // returns true
    t.insert("app");
    cout << t.search("app") << endl; // returns true
    

    return 0;
}
