// Problem statement
// Implement the function Search for the Trie class.

// For a Trie, write the function for searching a word. Return true if the word is found successfully, otherwise return false.
#include <iostream>
#include <string>
using namespace std;

#include <string>
class TrieNode
{
public:
    char data;
    TrieNode **children;
    bool isTerminal;

    TrieNode(char data)
    {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie
{
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode('\0');
    }

    void insertWord(TrieNode *root, string word)
    {
        // Base case
        if (word.size() == 0)
        {
            root->isTerminal = true;
            return;
        }

        // Small Calculation
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Recursive call
        insertWord(child, word.substr(1));
    }

    void insertWord(string word)
    {
        insertWord(root, word);
    }
    bool search(TrieNode *root, string word)
    {
        if (word.size() == 0)
        {
            if (root->isTerminal == true)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        int index = word[0] - 'a';
        if (root->children[index] == NULL)
        {
            return false;
        }
        TrieNode *child = root->children[index];
        // bool ans = search(child, word.substr(1));
        // return ans;
        return search(child, word.substr(1));
    }
    bool search(string word)
    {
        // Write your code here
        return search(root, word);
    }
};

int main()
{
    int choice;
    cin >> choice;
    Trie t;

    while (choice != -1)
    {
        string word;
        bool ans;
        switch (choice)
        {
        case 1: // insert
            cin >> word;
            t.insertWord(word);
            break;
        case 2: // search
            cin >> word;
            cout << (t.search(word) ? "true\n" : "false\n");
            break;
        default:
            return 0;
        }
        cin >> choice;
    }

    return 0;
}