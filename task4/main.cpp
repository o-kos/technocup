#include <ctime>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <iostream>

using namespace std;


unsigned long long llrand() {
    unsigned long long r = 0;

    for (int i = 0; i < 5; ++i) {
        r = (r << 15) | (rand() & 0x7FFF);
    }

    return r & 0xFFFFFFFFFFFFFFFFULL;
}

int main()
{
    size_t n;
    vector<string> numbers;

    cin >> n;
    for (size_t i = 0; i < n; i++) {
        string number;
        cin >> number;
        numbers.push_back(number);
    }

//    n = 3;
//    numbers.push_back("123456789");
//    numbers.push_back("100000000");
//    numbers.push_back("100123456");

//    n = 4;
//    numbers.push_back("134567819");
//    numbers.push_back("934567891");
//    numbers.push_back("123456789");
//    numbers.push_back("193456789");

//    n = 70000;
//    srand(70);
//    unordered_set<int> set;
//    for (size_t i = 0; i < n; ++i) {
//        unsigned long long value;
//        while (true) {
//            value = 1 + llrand() % 999999998;
//            auto p = set.insert(int(value));
//            if (p.second) break;
//        }
//        char number[10];
//        sprintf(number, "%.9d", int(value));
//        numbers.push_back(string(number));
//    }

    clock_t beg = clock();

    unordered_map<string, int> counts;
    size_t count = numbers[0].length();
    for (size_t i = 0; i < n; ++i) {
        string number = numbers[i];
        for (size_t len = 1; len <= count; ++len) {
            for (size_t start = 0; start <= count - len; ++start) {
                string ans = number.substr(start, len);
                auto res = counts.insert({ ans, i });
                if (!res.second) {
                    if (res.first->second != int(i)) res.first->second = -1;
                }
            }
        }
    }

    unordered_map<int, string> ans;
    for (auto i : counts) {
        if (i.second != -1) {
            auto res = ans.insert({ i.second, i.first });
            if (!res.second) {
                if (i.first.length() < res.first->second.length())
                    res.first->second = i.first;
            }
        }
    }

    clock_t end = clock();

    for (int i = 0; i < int(n); ++i) {
        cout << ans[i] << endl;
    }

    int ms = int(double(end - beg) * 1000 / CLOCKS_PER_SEC);
//    cout << "Elapsed: " << ms << " ms" << endl;

    return 0;
}
