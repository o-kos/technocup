#define DEBUG_DEV

#ifdef DEBUG_DEV
#include <ctime>
#endif

#include <map>
#include <set>
#include <list>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

void print(const string &name, const string &index)
{
    cout << "move " << name << " " << index << endl;
}

int main(int argc, char **argv)
{
    istream *inp = &cin;
    ifstream inf;
#ifdef DEBUG_DEV
    if (argc > 1) {
        inf.open(argv[1]);
        if (inf.good()) inp = &inf;
    }
#endif

#ifdef DEBUG_DEV
    clock_t beg = clock();
#endif

    map<string, int> testa;
    set<string> tests[2];
    list<string> good;
    list<string> bad[2];

    int n, e = 0;
    *inp >> n;
    for (int i = 0; i < n; i++) {
        string name;
        *inp >> name;
        int type;
        *inp >> type;
        if (type) e++;
        tests[type].insert(name);
        testa.insert({ name, type });

        char *p;
        int val = strtol(name.c_str(), &p, 10);
        if (*p == 0 && to_string(val) == name && val < n) good.push_back(name);
    }

    set<string> ans[2];
    for (int i = 1; i <= n; ++i) ans[i <= e].insert(to_string(i));

<<<<<<< Updated upstream
    int free[2] = { e, n - e };
    const int limits[2][2] = {{ e + 1, n }, { 1, e }};
    for (const auto &name : good) {
        int type = testa[name];
        int val = stoi(name);
        if (val >= limits[type][0] && val <= limits[type][1]) {
            testa.erase(testa.find(name));
            tests[type].erase(tests[type].find(name));
            free[type]--;
            ans[type].erase(ans[type].find(name));
        } else {
            bad[type].push_back(name);
        }
=======
    list<string> script;
    size_t ce = 0, cn = e + 1;
    for (size_t i = 0; i < n; ++i) {

>>>>>>> Stashed changes
    }

    while (!bad[0].empty() || !bad[1].empty()) {
        int type = ans[0].size() > ans[1].size();
        if (bad[type].empty()) type = int(!type);
        string name = bad[type].front();
        bad[type].pop_front();
        if (ans[type].empty()) {
            testa.erase(testa.find(name));
            tests[type].erase(tests[type].find(name));
            testa.insert({ to_string(1), type });
//            tests[type].insert()
cerr << "error1";
        } else {
            auto it = ans[type].begin();
            string index = *it;
            ans[type].erase(it);
            print(name, index);
        }

        testa.erase(testa.find(name));
        tests[type].erase(tests[type].find(name));
        free[type]--;
    }

    for (const auto &kv : testa) {
        if (ans[kv.second].empty()) {
cerr << "error2";
        }
        auto it = ans[kv.second].begin();
        string index = *it;
        ans[kv.second].erase(it);
        print(kv.first, index);
    }

    //    1 < 3.1           1. move 3 1
    //    2 = 2.1
    //    3 < 99.0          4. move 99 3
    //    4 < 2extra.0      3. move 2extra 4
    //    5 < 01.0          2. move 01 5


#ifdef DEBUG_DEV
    clock_t end = clock();
    int ms = int(double(end - beg) * 1000 / CLOCKS_PER_SEC);
    cout << "Elapsed: " << ms << " ms" << endl;
#endif

    return 0;
}
