// Problem statement
// Given 'n' number of words,
// you need to find if there exist any two words which can be joined to make a palindrome or any word,
// which itself is a palindrome or not .
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <string>
class TrieNode
{
public:
    char data;
    TrieNode **children;
    bool isTerminal;
    int childCount;
    bool restPalindrome;

    TrieNode(char data)
    {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
        restPalindrome = false;
        childCount = 0;
    }
};

class Trie
{
    TrieNode *root;

public:
    int count;

    Trie()
    {
        this->count = 0;
        root = new TrieNode('\0');
    }
    string getReversed(string word)
    {
        int size = word.size();
        for (int i = 0; i < size / 2; i++)
        {
            swap(word[i], word[size - i - 1]);
        }
        return word;
    }
    bool checkPalindrome(string word)
    {
        string revWord = getReversed(word);
        if (word == revWord)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void add(TrieNode *root, string word, int i)
    {
        // Base case
        // if (word.size() == 0) {
        //     if (!root->isTerminal) {
        //         root->isTerminal = true;
        //         return true;
        //     } else {
        //         return false;
        //     }
        // }
        if (word.size() == 0)
        {
            root->isTerminal = true;
            return;
        }
        if (checkPalindrome(word.substr(i + 1)))
        {
            root->restPalindrome = true;
        }
        // Small calculation
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
            root->childCount++;
        }

        // Recursive call
        return add(child, word.substr(1), i);
    }

    void add(string word)
    {
        // if (add(root, word, -1)) {
        // this->count++;
        // }
        add(root, word, -1);
    }

    bool search(TrieNode *root, string word, int i)
    {
        if (root->isTerminal == true && checkPalindrome(word.substr(i + 1)))
        {
            return true;
        }
        if (word.size() == 0)
        {
            if (root->isTerminal == true)
            {
                return true;
            }
            else if (root->restPalindrome == true)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            return false;
        }
        return search(child, word.substr(1), i);
    }
    /*..................... Palindrome Pair................... */

    // void insert
    bool isPalindromePair(vector<string> words)
    {
        // Write your code here
        string word;
        for (int i = 0; i < words.size(); i++)
        {
            word = words[i];
            string reverseWord = getReversed(word);
            add(reverseWord);
        }

        for (int i = 0; i < words.size(); i++)
        {
            string word1 = words[i];
            if (search(root, word1, -1))
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    Trie t;
    int n;
    cin >> n;
    vector<string> words(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> words[i];
    }

    cout << (t.isPalindromePair(words) ? "true" : "false");
}