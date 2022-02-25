//[bonfire, cardio, case, character, bonsai]

#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;
 

struct TrieNode
{
    
    map<char, TrieNode*> child;
 
    
    int freq = 0;
};
 

void insert(TrieNode* &root, string word)
{
  
    TrieNode* curr = root;
    for (char c: word)
    {
        
        if (curr->child.find(c) == curr->child.end()) {
            curr->child[c] = new TrieNode();
        }
 
        
        curr->child[c]->freq++;
 
        
        curr = curr->child[c];
    }
}
 

void printShortestPrefix(TrieNode *root, string word_so_far)
{
    if (root == nullptr) {
        return;
    }
 
    
    if (root->freq == 1)
    {
        cout << word_so_far << endl;
        return;
    }
 
    
    for (auto &child: root->child) {
        printShortestPrefix(child.second, word_so_far + child.first);
    }
}
 

void findShortestPrefix(vector<string> &words)
{
    
    TrieNode* root = new TrieNode();
    for (string s: words) {
        insert(root, s);
    }
 
    
    printShortestPrefix(root, "");
}
 
int main()
{

    vector<string> database = { "AND", "BONFIRE", "BOOL", "CASE", "CATCH", "CHAR", "BONSAI" };
    
    vector<string> words = { "AND", "BONFIRE", "BONSAI","AKSHAT"};
    findShortestPrefix(words);
 
    return 0;
}