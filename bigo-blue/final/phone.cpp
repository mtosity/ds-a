// Nguon: https://www.geeksforgeeks.org/trie-insert-and-search/
// Em lười cài lại quá :P
// C++ implementation of search and insert
// operations on Trie
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int ALPHABET_SIZE = 10;

// trie node
struct TrieNode
{
    struct TrieNode *children[ALPHABET_SIZE];

    // isEndOfWord is true if the node represents
    // end of a word
    bool isEndOfWord;
};

// Returns new trie node (initialized to NULLs)
struct TrieNode *getNode(void)
{
    struct TrieNode *pNode = new TrieNode;

    pNode->isEndOfWord = false;

    for (int i = 0; i < ALPHABET_SIZE; i++)
        pNode->children[i] = NULL;

    return pNode;
}

// If not present, inserts key into trie
// If the key is prefix of trie node, just
// marks leaf node
void insert(struct TrieNode *root, string key)
{
    struct TrieNode *pCrawl = root;

    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - '0';
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();

        pCrawl = pCrawl->children[index];
    }

    // mark last node as leaf
    pCrawl->isEndOfWord = true;
}

// Returns true if key presents in trie, else
// false
bool search(struct TrieNode *root, string key)
{
    struct TrieNode *pCrawl = root;

    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - '0';
        if (pCrawl->isEndOfWord)
        {
            return true;
        }
        if (!pCrawl->children[index])
            return false;

        pCrawl = pCrawl->children[index];
    }

    return true;
}

int main()
{
    int test = 0;
    cin >> test;
    while (test > 0)
    {
        int n;
        cin >> n;
        bool isno = false;

        struct TrieNode *root = getNode();
        vector<string> keys;
        for (int i = 0; i < n; i++)
        {
            string key;
            cin >> key;
            keys.push_back(key);
        }

        for (int i = 0; i < n; i++)
        {
            string key = keys[i];
            if (search(root, key))
            {
                cout << "NO" << endl;
                isno = true;
                break;
            }
            else
            {
                insert(root, key);
            }
        }

        if (!isno)
        {
            cout << "YES" << endl;
        }
        test--;
    }

    return 0;
}
