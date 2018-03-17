
//This class handle word consist of alpha table.

typedef struct _st_Trie_Item_
{
    char c;
    struct _st_Trie_Item_* pChild;
} Trie_Item, *PTrie_Item;


class CTrie
{
public:
    CTrie();
    ~CTrie();
public:
    int Insert(char* word);
    bool Find(char* word);
private:
    void InitItem(Trie_Item* p);    
 private:
    Trie_Item   root[26];
};