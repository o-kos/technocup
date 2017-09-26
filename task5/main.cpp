#define DEBUG_DEV

#ifdef DEBUG_DEV
#include <ctime>
#endif

#include <string>
#include <map>
#include <list>
#include <iostream>

using namespace std;

int main()
{
    size_t n, e;
    list<string> flist;
    map<string, int> fmap;

#ifndef DEBUG_DEV
    cin >> n;
    for (size_t i = 0; i < n; i++) {
        string name;
        cin >> name;
        int type;
        cin >> type;
        if (type) e++;
        flist.push_back(name);
        fmap.insert({ name, type });

    }
#else
    n = 5; e = 2;
    flist.push_back(    "01");
    fmap.insert({       "01", 0 });
    flist.push_back("2extra");
    fmap.insert({   "2extra", 0 });
    flist.push_back(     "2");
    fmap.insert({        "2", 1 });
    flist.push_back(     "3");
    fmap.insert({        "3", 1 });
    flist.push_back(    "99");
    fmap.insert({       "99", 0 });
#endif

#ifdef DEBUG_DEV
    clock_t beg = clock();
#endif

//    1 < 3.1           1. move 3 1
//    2 = 2.1
//    3 < 99.0          4. move 99 3
//    4 < 2extra.0      3. move 2extra 4
//    5 < 01.0          2. move 01 5

    list<string> script;
    size_t ce = 0, cn = e + 1;
    for (const auto &name : flist) {
        if
    }

//    unordered_map<int, string> ans;
//    for (auto i : counts) {
//        if (i.second != -1) {
//            auto res = ans.insert({ i.second, i.first });
//            if (!res.second) {
//                if (i.first.length() < res.first->second.length())
//                    res.first->second = i.first;
//            }
//        }
//    }

//    for (int i = 0; i < int(n); ++i) {
//        cout << ans[i] << endl;
//    }

#ifdef DEBUG_DEV
    clock_t end = clock();
    int ms = int(double(end - beg) * 1000 / CLOCKS_PER_SEC);
    cout << "Elapsed: " << ms << " ms" << endl;
#endif

    return 0;
}
