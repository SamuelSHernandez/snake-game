#include <iostream>
#include <list>
#include <utility>
using namespace std;

int main() {
    list<pair<int, string> > tempList;
    list<pair<int, string> > oldList;
    list<pair<int, string> > newList;
    pair<int, string> max = make_pair(0, "");
    tempList.push_back(make_pair(14, "Luke"));
    tempList.push_back(make_pair(4, "Kasi"));
    tempList.push_back(make_pair(3, "Alex"));
    tempList.push_back(make_pair(2, "Drew"));
    tempList.push_back(make_pair(1, "Luke"));

    // list<pair<int, string> >::iterator i;
    // for (i = tempList.begin(); i != tempList.end(); ++i) {
    //     cout << "looking at: " << i->second << endl;
    //     if (i->first >= tempList.front().first) {
    //         cout << "got here: " << i->second << endl;
    //         newList.push_front(*i);
    //         i = tempList.erase(i);
    //         --i;
    //     }
    // }

    
    // int size = oldList.size();
    // list<pair<int, string> >::iterator j;
    // for (int i = 0; i < size; ++i) {
    //     for (j = oldList.begin(); j != oldList.end(); ++j) {
    //         if(j->first >= max->first) {
    //             max = &*j;
    //         }
    //         newList.push_front(max);
    //         oldList.remove(max);
    //     }
    // }

    tempList.sort();

    cout << "List: " << endl;
    for (auto each : tempList) {
        cout << each.first << '\t' << each.second << endl;
    }
    return 0;
}