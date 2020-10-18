#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;

void Viv(int a)
    {
        cout<<a<<" "<<endl;
    }
 

int main()
{
//  1
    unordered_multimap<int, string> map({{1,"tank"},{2,"beast"},{3,"fall"},{-1,"hawl"}});
    
    auto print = [](const pair<int,string>a)
        {
            cout<<a.first<<" "<<a.second<<endl;
        };
map.insert(make_pair(7, "qwer"));
map.insert(make_pair(7, "stop"));
map.insert(make_pair(7, "stack"));
    for_each(map.cbegin(),map.cend(),print);
map.erase(3);
    cout<<"//"<<endl;
    for_each(map.cbegin(),map.cend(),print);
    
    
    
//  2
    
//  3
   auto it =  map.find(-1);
    if (it!=map.end())
    {
    cout<<it -> second<<endl;
    }
    else cout<<"Net takih"<<endl;
    
return 0;
}
