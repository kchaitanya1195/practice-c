#include <iostream>
using std::cout;
using std::endl;
using std::string;

class TrieNode {
    public:
        int prefixes;
        int lastEdge;
        bool isWord;
        TrieNode *edges[26];

        TrieNode();
};

class Trie {
    public:
        TrieNode *root;

        Trie(): root(new TrieNode()) {}

        void addWord(const char *word) { addWord(root, word); }
        int countPrefix(const char *word) { return countPrefix(root, word); }

        void printTrie();

    protected:
        void addWord(TrieNode *curr, const char *word);
        int countPrefix(TrieNode *curr, const char *word);
        void printTrie(TrieNode *curr, string prefix = "", int index = 0, bool isTail = false);
};