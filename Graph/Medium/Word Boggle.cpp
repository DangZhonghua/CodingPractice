//https://practice.geeksforgeeks.org/problems/word-boggle/0

// Use graph dfs to traverse the Graph, the path will contain the string, the substring will
// will be checked in dictionary.

#include<vector>
#include<iostream>

using namespace std;



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
    short makeupperchar(short c);
 private:
    Trie_Item   root[26];
};


int BuildcDictionary(char* dict[], int count)
{
    
    return 0;
}



int DFS(vector< vector<char> > boggle, vector< vector<char> > visited, int M, int N)
{
    
}





int SearchBoggle(vector< vector<char> > boggle, int M, int N)
{
    

    return 0;
}




int main()
{
    

    return 0;
}


CTrie::CTrie()
{
    InitItem(root);
}

CTrie::~CTrie()
{

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

int CTrie::Insert(char* word)
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

bool CTrie::Find(char* word)
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