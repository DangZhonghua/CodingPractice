#include <map>
#include <iostream>
using namespace std;



int main()
{
    multimap<int, char> mmap;
    mmap.insert({{1,'a'},{1,'b'}});
    for(auto it = mmap.begin(); it != mmap.end(); ++it)
    {
        cout<<it->first<<":"<<it->second<<endl;
    }

    return 0;
}