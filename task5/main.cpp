#define _DEBUG_DEV

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

static list<string> script;

void print(const string &name, const string &index)
{
    script.push_back("move " + name + " " + index);
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

    map<string, int> tests;
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
        tests.insert({ name, type });

        char *p;
        int val = int(strtol(name.c_str(), &p, 10));
        if (*p == 0 && to_string(val) == name && val <= n) good.push_back(name);
    }

    set<string> ans[2];
    for (int i = 1; i <= n; ++i) ans[i <= e].insert(to_string(i));

    const int limits[2][2] = {{ e + 1, n }, { 1, e }};
    for (const auto &name : good) {
        int type = tests[name];
        int val = stoi(name);
        if (val >= limits[type][0] && val <= limits[type][1]) {
            tests.erase(tests.find(name));
            ans[type].erase(ans[type].find(name));
        } else {
            bad[type].push_back(name);
            auto it = ans[0].find(name);
            if (it != ans[0].end()) ans[0].erase(it);
            it = ans[1].find(name);
            if (it != ans[1].end()) ans[1].erase(it);
        }
    }


    while (!bad[0].empty() || !bad[1].empty()) {
        int type = ans[0].size() < ans[1].size();
        if (bad[type].empty()) type = int(!type);
        string name = bad[type].front();
        tests.erase(tests.find(name));
        bad[type].pop_front();
        if (ans[type].empty()) {
            string newname = to_string(n + 1);
            print(name, newname);
            tests.insert({ newname, type });
        } else {
            auto it = ans[type].begin();
            string index = *it;
            ans[type].erase(it);
            print(name, index);
        }
        ans[!type].insert(name);
    }

    for (const auto &kv : tests) {
        auto it = ans[kv.second].begin();
        string index = *it;
        ans[kv.second].erase(it);
        print(kv.first, index);
    }

    cout << script.size() << endl;
    for (const auto &line : script) cout << line << endl;


#ifdef DEBUG_DEV
    clock_t end = clock();
    int ms = int(double(end - beg) * 1000 / CLOCKS_PER_SEC);
    cout << "Elapsed: " << ms << " ms" << endl;
#endif

    return 0;
}
