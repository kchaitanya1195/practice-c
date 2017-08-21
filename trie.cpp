#include "trie.h"

TrieNode::TrieNode():prefixes(0), lastEdge(-1), isWord(false) {
    for (int i = 0; i < 26; i++) 
        edges[i] = NULL;
}

void Trie::addWord(TrieNode *curr, const char *word) {
    curr->prefixes++;
    if(strlen(word) <= 0){
        curr->isWord = true;
        return;
    }

    int k = word[0] - 'a';
    //cout<<(char)(k +'a')<<endl;
    word++;
    if (!curr->edges[k]) {
        curr->edges[k] = new TrieNode();
        curr->lastEdge = ((k > curr->lastEdge)? k : curr->lastEdge);
    }

    addWord(curr->edges[k], word);
}
int Trie::countPrefix(TrieNode *curr, const char *word) {
    if (strlen(word) <= 0) {
        return curr->prefixes;
    }

    if (!curr) {
        return 0;
    }

    int k = word[0] - 'a';
    word++;

    return countPrefix(curr->edges[k], word);
}

void Trie::printTrie() {
    for (int i = 0; i < root->lastEdge; i++) {
        printTrie(root->edges[i], "", i, false);
    }
    if (root->lastEdge > 0)
        printTrie(root->edges[root->lastEdge], "", root->lastEdge, true);
}
void Trie::printTrie(TrieNode *curr, string prefix, int index, bool isTail) {
    if (curr)
        cout<<prefix<<(isTail?"└──":"├──")<<index<<": "<<(char)(index + 'a')<<endl;
    else {
        return;
    }
    //cout<<index<<": ";
    //cout<<curr->lastEdge<<endl;

    for (int i = 0; i < curr->lastEdge; i++) {
        printTrie(curr->edges[i], prefix + (isTail?"   ":"│  "), i, false);
    }
    if (curr->lastEdge > 0)
        printTrie(curr->edges[curr->lastEdge], prefix + (isTail?"   ":"│  "), curr->lastEdge, true);
}