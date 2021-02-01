#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;
using namespace placeholders;

typedef unordered_multimap<int, string>::iterator mp;

auto print = [](const pair<int,string>a)
    {
        cout<<a.first<<" "<<a.second<<endl;
    };
auto pPrint = [](int n)
{
    cout<<n<<" ";
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
    cout<<"Zadanie №1:"<<endl;
unordered_multimap<int, string>map({{2,"tank"},{-2,"beast"},{7,"fall"},{8,"hawl"},{-3,"peace"}});
    for_each(map.cbegin(),map.cend(),print);
    cout<<"-------------------"<<endl;
map.erase(7);
    for_each(map.cbegin(),map.cend(),print);
    cout<<"-------------------"<<endl;
map.erase(2);
    for_each(map.cbegin(),map.cend(),print);
    cout<<"-------------------"<<endl;
map.insert(make_pair(7, "qwer"));
    for_each(map.cbegin(),map.cend(),print);
    cout<<"-------------------"<<endl;
map.insert(make_pair(7, "stop"));
    for_each(map.cbegin(),map.cend(),print);
    cout<<"-------------------"<<endl;
        
    
    unordered_map <int, string>map2;
    
    mp i = map.begin();
        for (; i != map.end(); i++) map2.insert(std::pair<int, std::string>(i->first, i->second));
            for_each(map2.cbegin(), map2.cend(), print);
    
    
//  2
    cout<<"Zadanie №2:"<<endl;
    short int rez = map2.size();

        cout<<"Vsego elementov: "<< rez << endl;
    
    vector<int> MyVec;
        transform(map.cbegin(),map.cend(),back_inserter(MyVec), doVec);
            for_each(MyVec.cbegin(), MyVec.cend(),pPrint );
                cout<<endl;
    
//  3
    cout<<"Zadanie №3:"<<endl;
    auto it =  map.find(8);
    if (it!=map.end())
        {
            cout<<"Eto: "<<it -> second<<endl;
        }
    else cout<<"Net takih"<<endl;
    
    replace_if(MyVec.begin(), MyVec.end(), bind(less<int>(),_1, 0),2);
        for_each(MyVec.cbegin(), MyVec.cend(), pPrint);
            cout<<endl;
    
    sort(MyVec.begin(),MyVec.end(), [](int a, int b){return a > b;});
        for_each(MyVec.cbegin(), MyVec.cend(), pPrint);
            cout<<endl;
   
    set<int> MySet;
        MySet.insert(MyVec.begin(),MyVec.end());
            for_each(MySet.cbegin(), MySet.cend(), pPrint);
    cout<<endl;
return 0;
}
