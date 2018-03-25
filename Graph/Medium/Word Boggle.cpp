//https://practice.geeksforgeeks.org/problems/word-boggle/0

// Use graph dfs to traverse the Graph, the path will contain the string, the substring will
// will be checked in dictionary.

#include<vector>
#include<iostream>
#include<string>

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


int BuildcDictionary(char* dict[], int count,CTrie& trieObject)
{
    for(int i = 0; i< count; ++i)
    {
        trieObject.Insert(dict[i]);
    }

    return 0;
}

bool Isaccessible(vector<vector<char>>& visited, int M, int N, int r, int c)
{
    if(visited[r][c])
    {
        return false;
    }
    if(r>=0  && r<M && c>=0 && c<N)
    {
        return true;
    }
    return false;
}
int DFSVisit(vector< vector<char> >& boggle, vector<vector<char>>& visited, string& strword,
            int M, int N, int u, int v,CTrie& dict, vector<string>& words)
{
    visited[u][v] = true;
    strword.push_back(boggle[u][v]);
    char* szword = (char*)strword.c_str();
    int len  = strword.length();
    len -= 1;
    while (len >=0 )
    {
        if(dict.Find(szword+len))
        {
            words.push_back(szword+len);
        }
        --len;
    }

    static int vnbr[8] = {-1,-1, -1, 0,1,1,1, 0};
    static int hnbr[8] = {-1, 0,  1, 1,1,0,-1,-1};
    
    for(int i = 0; i< 8; ++i)
    {
     if(Isaccessible(visited,M,N,u+vnbr[i],v+hnbr[i]))
     {
         DFSVisit(boggle,visited,strword,M,N,u+vnbr[i],v+hnbr[i],dict,words);
     }
    }


    return 0;
}

int DFS(vector< vector<char> >& boggle, vector< vector<char> >& visited, int M, int N,
 CTrie& dict, vector<string>& words)
{
    
    for(int r = 0; r<M;++r)
    {
        for(int c = 0; c<N; ++c)
        {
            if(!visited[r][c])
            {
                string strword = "";
                DFSVisit(boggle,visited,strword,M,N,r,c,dict,words);                
            }
        }
    }
 
 return 0;
}





int SearchBoggle(vector< vector<char> >& boggle, int M, int N)
{
    vector< vector<char> > visit;
    for(int i = 0; i<M; ++i)
    {
        vector<char> row;
        for(int j = 0; j<N; ++j)
        {
            row.push_back(0);
        }
        visit.push_back(row);
    }

    

   // DFS(boggle,visit,M,N);

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