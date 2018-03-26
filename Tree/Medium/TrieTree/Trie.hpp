#include<iostream>
#include <string>
#include <vector>
using namespace std;

typedef struct _st_Trie_Item_
{
    char c;
    struct _st_Trie_Item_ *pChild;
} Trie_Item, *PTrie_Item;

class CTrie
{
  public:
    CTrie();
    ~CTrie();

  public:
    int Insert(const char *word);
    bool Find(const char *word);
    void PrefixWords(const char *prefix, vector<string> &vWords);
    void Clear();
  private:
    void dfsTrietree(PTrie_Item cur, vector<string> &vWords, const string& strPrefix);
    void InitItem(Trie_Item *p);
    short makeupperchar(short c);
    void ClearNode(PTrie_Item node);

  private:
    Trie_Item root[26];
};
