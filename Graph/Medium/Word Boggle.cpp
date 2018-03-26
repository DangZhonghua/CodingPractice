//https://practice.geeksforgeeks.org/problems/word-boggle/0

// Use graph dfs to traverse the Graph, the path will contain the string, the substring will
// will be checked in dictionary.

#include<vector>
#include <map>
#include <unordered_set>
#include<iostream>
#include<string>
#include <memory.h>

using namespace std;

#define MAX 10
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
	bool CheckPrefix(const char* prefix);
	void Clear();
private:
	void dfsTrietree(PTrie_Item cur, vector<string> &vWords, const string& strPrefix);
	void InitItem(Trie_Item *p);
	short makeupperchar(short c);
	void ClearNode(PTrie_Item node);

private:
	Trie_Item root[26];
};

int BuildcDictionary(char* dict[], int count, CTrie& trieObject)
{
	for (int i = 0; i < count; ++i)
	{
		trieObject.Insert(dict[i]);
	}

	return 0;
}

int BuildcDictionary(vector<string>& dicts, CTrie& trieObject)
{
	for (int i = 0; i < dicts.size(); ++i)
	{
		trieObject.Insert(dicts[i].c_str());
	}

	return 0;
}

bool Isaccessible(char visited[MAX][MAX], int M, int N, int r, int c)
{
	if (r >= 0 && r < M && c >= 0 && c < N && !visited[r][c])
	{
		return true;
	}
	return false;
}
int DFSVisit(char boggle[MAX][MAX], char visited[MAX][MAX], char* strword, int wordindex,
	int M, int N, int u, int v, CTrie& dict, unordered_set<string>& words)
{
	visited[u][v] = true;
	strword[wordindex++] = boggle[u][v];
	strword[wordindex + 1] = '\0';
	int len = wordindex - 1;
	while (len >= 0)
	{
		if (dict.Find(strword + len))
		{
			if (words.end() == words.find(strword + len))
				words.insert(strword + len);
		}
		--len;
	}

	static int vnbr[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };
	static int hnbr[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };

	for (int i = 0; i < 8; ++i)
	{
		int r = u + vnbr[i];
		int c = v + hnbr[i];
		if (r >= 0 && r < M && c >= 0 && c < N && !visited[r][c])
		{
			DFSVisit(boggle, visited, strword, wordindex, M, N, u + vnbr[i], v + hnbr[i], dict, words);
		}
	}
	--wordindex;
	visited[u][v] = false;

	return 0;
}

int DFS(char boggle[MAX][MAX], char visited[MAX][MAX], int M, int N,
	CTrie& dict, unordered_set< string>& words)
{
	char preword[2] = { 0 };
	char word[MAX*MAX] = { 0 };
	for (int r = 0; r < M; ++r)
	{
		for (int c = 0; c < N; ++c)
		{
			if (!visited[r][c])
			{
				word[0] = '\0';
				preword[0] = boggle[r][c];
				if (dict.CheckPrefix(preword))
					DFSVisit(boggle, visited, word, 0, M, N, r, c, dict, words);
			}
		}
	}

	return 0;
}





int SearchBoggle(char boggle[MAX][MAX], vector<string>& strDict, int M, int N)
{
	char visit[MAX][MAX];

	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			visit[i][j] = 0;
		}
	}

	CTrie dict;
	unordered_set<string> words;

	BuildcDictionary(strDict, dict);

	DFS(boggle, visit, M, N, dict, words);
	for (auto it = words.begin(); it != words.end(); ++it)
	{
		cout << it->c_str() << " ";
	}
	cout << endl;
	return 0;
}




int main()
{
	int t = 0;
	int nWordDict = 0;
	char boggle[MAX][MAX];
	char strword[1000];
	vector<string> strDict;

	cin >> t;

	while (t > 0)
	{
		--t;
		cin >> nWordDict;
		int i = 0;
		while (i < nWordDict)
		{
			scanf("%s", strword);
			strDict.push_back(strword);
			++i;
		}
		int R = 0;
		int C = 0;
		cin >> R >> C;
		for (int r = 0; r < R; ++r)
		{
			for (int c = 0; c < C; ++c)
			{
				cin >> boggle[r][c];
			}
		}

		SearchBoggle(boggle, strDict, R, C);
		strDict.clear();
	}

	return 0;
}



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
	memset(p, 0, sizeof(Trie_Item) * 26);
}

short CTrie::makeupperchar(short c)
{
	short l = c;
	if (c <= 'z' && c >= 'a')
	{
		l -= 32;
	}
	return l;
}

int CTrie::Insert(const char* word)
{
	int index = 0;
	Trie_Item* cur = root;
	while (word[index] != '\0' && 0 != cur)
	{
		short l = makeupperchar(word[index]);
		if (0 == cur[l - 'A'].pChild &&  '\0' != word[index + 1])
		{
			cur[l - 'A'].pChild = new Trie_Item[sizeof(root) / sizeof(root[0])];
			InitItem(cur[l - 'A'].pChild);
		}

		if (word[index + 1] == '\0')
		{
			cur[l - 'A'].c = '$';
			break;
		}
		cur = cur[l - 'A'].pChild;
		++index;
	}
	return 0;
}

bool CTrie::Find(const char* word)
{
	bool bFind = true;
	int index = 0;
	Trie_Item* cur = root;

	while (word[index] != '\0')
	{
		short l = makeupperchar(word[index]);
		if (word[index + 1] == '\0')
		{
			if (cur[l - 'A'].c != '$')
			{
				bFind = false;
			}
			break;
		}
		cur = cur[l - 'A'].pChild;
		if (0 == cur)
		{
			bFind = false;
			break;
		}
		++index;
	}

	return bFind;
}

bool CTrie::CheckPrefix(const char* prefix)

{
	bool bFind = true;
	int index = 0;
	Trie_Item* cur = root;

	while (prefix[index] != '\0')
	{
		short l = makeupperchar(prefix[index]);
		if (prefix[index + 1] == '\0')
		{
			break;
		}
		cur = cur[l - 'A'].pChild;
		if (0 == cur)
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
	int         index = 0;
	Trie_Item*  cur = root;

	while (prefix[index] != '\0' && 0 != cur)
	{
		short l = makeupperchar(prefix[index]);
		if (prefix[index + 1] == '\0')
		{
			if (cur[l - 'A'].c == '$')
			{
				vWords.push_back(prefix);
			}
		}
		cur = cur[l - 'A'].pChild;
		++index;
	}
	if (cur)
	{
		dfsTrietree(cur, vWords, prefix);
	}
}

void CTrie::dfsTrietree(PTrie_Item cur, vector<string> &vWords, const string& strPrefix)
{
	if (0 == cur)
	{
		return;
	}

	for (int i = 0; i < 26; ++i)
	{
		string strWord = strPrefix;
		strWord.push_back(i + 97);
		if (cur[i].c == '$')
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
	for (int i = 0; i < 26; ++i)
	{
		if (node[i].pChild)
		{
			ClearNode(node[i].pChild);
			node[i].pChild = 0;
		}
	}
	if (node != root)
	{
		delete[] node;
	}
}