#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

typedef unordered_multimap<int, string>::iterator mp;

auto print = [](const pair<int,string>a)
    {
        cout<<a.first<<" "<<a.second<<endl;
    };
auto printV = [](int n)
{
    cout<<n<<" ";
};

auto check = [](const pair<int,string>a)
{
    return a.first > 0;
};

auto doVec = [](const pair<int,string>a)
{
    return a.first;
};

void Viv(int a)
    {
        cout<<a<<" "<<endl;
    }

int main()
{
//  1
unordered_multimap<int, string>map({{2,"tank"},{-2,"beast"},{7,"fall"},{8,"hawl"},{-3,"peace"}});
map.erase(7);
map.erase(2);

map.insert(make_pair(7, "qwer"));
map.insert(make_pair(7, "stop"));
    for_each(map.cbegin(),map.cend(),print);
        cout<<"//"<<endl;
    
    std::map <int, string>map2;
    
    mp i = map.begin();
        for (; i != map.end(); i++) map2.insert(std::pair<int, std::string>(i->first, i->second));
            for_each(map2.cbegin(), map2.cend(), print);
    
    
//  2
    int rez = map2.size();

        cout<<"Vsego elementov: "<< rez << endl;
    
    vector<int> MyVec;
    transform(map2.cbegin(),map2.cend(),back_inserter(MyVec), doVec);
        for_each(MyVec.cbegin(), MyVec.cend(),printV );
            cout<<endl;
    
//  3
   auto it =  map.find(8);
    if (it!=map.end())
        {
            cout<<"Eto: "<<it -> second<<endl;
        }
    else cout<<"Net takih"<<endl;
    
    replace_if(MyVec.begin(), MyVec.end(), bind(less<int>(),placeholders::_1, 0),2);
        for_each(MyVec.cbegin(), MyVec.cend(), printV);
            cout<<endl;
    sort(MyVec.begin(),MyVec.end(), [](int a, int b){return a > b;});
        for_each(MyVec.cbegin(), MyVec.cend(), printV);
            cout<<endl;
   
    set<int> MySet;
        MySet.insert(MyVec.begin(),MyVec.end());
            for_each(MySet.cbegin(), MySet.cend(), printV);
    cout<<endl;
return 0;
}
