#include "Trie.hpp"


CTrie::CTrie()
{
    InitItem(root);
}

CTrie::~CTrie()
{
    Clear();
}

void CTrie::InitItem(Trie_Item* p)
{
    for(int i = 0; i<sizeof(root)/sizeof(root[0]);++i)
    {
        p[i].c       = 0;
        p[i].pChild  = 0;
    }
}

short CTrie::makeupperchar(short c)
{
    short l = c;
    if(c<='z' && c>='a')
    {
        l -= 32;
    }
    return l;
}

int CTrie::Insert(const char* word)
{
    int index = 0;
    Trie_Item* cur = root;
    while(word[index] != '\0' && 0 != cur)
    {
        short l = makeupperchar(word[index]);
        if(0 == cur[l-'A'].pChild &&  '\0' != word[index+1] )
        {
            cur[l-'A'].pChild = new Trie_Item[sizeof(root)/sizeof(root[0])];
            InitItem(cur[l-'A'].pChild);
        }
        
        if(word[index+1] == '\0')
        {
            cur[l-'A'].c = '$';
            break;
        }
        cur = cur[l-'A'].pChild;
        ++index;
    }
    return 0;
}

bool CTrie::Find(const char* word)
{
    bool bFind  = true;
    int index   = 0;
    Trie_Item* cur = root;
    
    while(word[index] != '\0')
    {  
        short l = makeupperchar(word[index]);
        if(word[index+1] == '\0' )
        {
            if( cur[l-'A'].c != '$')
            {
              bFind = false;
            }
            break;     
        }
        cur = cur[l-'A'].pChild;
        if(0 == cur)
        {
            bFind = false;
            break;
        }
        ++index;
    }

    return bFind;
}

void CTrie::PrefixWords(const char *prefix, vector<string> &vWords)
{
    int         index   = 0;
    Trie_Item*  cur     = root;
    
    while(prefix[index] != '\0' && 0 != cur)
    {  
        short l = makeupperchar(prefix[index]);
        if(prefix[index+1] == '\0' )
        {
            if( cur[l-'A'].c == '$')
            {
              vWords.push_back(prefix);
            }
        }
        cur = cur[l-'A'].pChild;
        ++index;
    }
    if(cur)
    {
        dfsTrietree(cur, vWords, prefix);
    }
}

void CTrie::dfsTrietree(PTrie_Item cur, vector<string> &vWords, const string& strPrefix)
{
    if(0 == cur)
    {
        return;
    }

    for(int i = 0; i<26; ++i)
    {
         string strWord = strPrefix;
          strWord.push_back(i+97);
        if(cur[i].c == '$')
        { 
            vWords.push_back(strWord);
            dfsTrietree(cur[i].pChild, vWords, strWord);     
        }
        else
        {
             dfsTrietree(cur[i].pChild, vWords, strWord);
        }
    }

}

void CTrie::Clear()
{
    ClearNode(root);
    InitItem(root);  
}

void  CTrie::ClearNode(PTrie_Item node)
{
    for(int i = 0; i<26; ++i)
    {
        if(node[i].pChild)
        {
            ClearNode(node[i].pChild);
            node[i].pChild = 0;
        }
    }
    if(node != root)
    {
        delete[] node;
    }
}