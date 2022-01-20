#include <bits/stdc++.h>
using namespace std;
struct test
{
    bool operator()(const int &a1, const int &a2) const
    {
        return a1 < a2;
    }
};
int main()
{
    /* sort */
    int a[5]{2, 4, 6, 2, 1};
    sort(a, a + 5, test());
    for (auto i : a)
    {
        cout << i;
    }

    /* binary_search */
    binary_search(a, a + 5, 7);
    cout << binary_search(a, a + 5, 6, test());
    int *p = lower_bound(a, a + 5, 7);
    int *p = lower_bound(a, a + 5, 7, test());
    int *p = upper_bound(a,a+5,7);
    int *p = upper_bound(a,a+5,7,test());

    /* multiset */
    multiset<int> st;
    auto i; // multiset<int>:: iterator i;
    st.insert(6);
    i = st.find(6); 
    if(i==st.end()) // not find 
    i=st.lower_bound(6);
    st.erase(i); // iterator i;
    multiset<int,greater<int> > st;
    multiset<int,test> st;

    /* set 不能有重复元素*/
    set<int> st;
    st.insert(6);
    pair<set<int>::iterator, bool> result =st.insert(6);
    if(!result.second)  //false
        cout << *result.first << "already exists." << endl;
    else 
        cout << *result.first << "inserted." << endl;
    /* pair<T1,T2> a     equal

    struct {
        T1 first;
        T2 second;
    }a; */

    /* multimap */
    multimap<T1,T2> mp; //缺省的规则 a.first < b.first
    mp.insert(make_pair(6,"6");
    auto p =mp.lower_bound(6);

    /* map不能有重复关键字、可以用【关键字】、返回值为second、可能插入失败 */
    mp.insert(make_pair(6,"6"));
    cout << mp[6] << endl;
    mp[6]="7";
    auto p = mp.find(7);
    for(auto i=mp.begin();i!=mp.end();i++)
    {
        cout << i->first;
    }
    pair<iterator,bool> p=mp.insert(make_pair(st.name,st.score));
    if(p.second)
    {
        cout << "inserted";
    }
    

}