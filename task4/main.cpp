#include <ctime>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <iostream>

using namespace std;

class ShortCutCalculator {
public:
    ShortCutCalculator(const vector<string> &numbers) : m_numbers(numbers), m_counts(numbers[0].size()), m_len(1) {
        m_counts[0] = 10;
        for (size_t i = 1; i < m_counts.size(); ++i)
            m_counts[i] = m_counts[i - 1] * 10;
    }
    string calc(size_t index);
    size_t volume() const { return m_voc.size(); }
//    void printVoc(size_t size) const {
//        for (size_t i = 0; i < size * 50; ++i) {
//            size_
//        }
//    }
private:
    const vector<string> m_numbers;
    unordered_set<string> m_voc;
    vector<size_t> m_counts;
    size_t m_len;
};

string ShortCutCalculator::calc(size_t index)
{
    string number = m_numbers[index];
    size_t count = number.length();
    for (size_t len = m_len; len <= count; ++len) {
        for (size_t start = 0; start <= count - len; ++start) {
            string ans = number.substr(start, len);
            if (m_voc.find(ans) == m_voc.end()) {
                bool isOk = true;
                for (size_t i = 0; i < m_numbers.size(); ++i) {
                    if (i != index) {
                        if (m_numbers[i].find(ans) != string::npos) {
                            isOk = false;
                            m_voc.insert(ans);
                            if (!--m_counts[ans.length() - 1]) {
                                auto res = find_if_not(m_counts.begin(), m_counts.end(), [](size_t i) { return !bool(i); });
                                if (res != m_counts.end()) {
                                    m_len = size_t(res - m_counts.begin()) + 1;
//cout << m_len << " " << m_counts[0] << " " << m_counts[1] << " " << m_counts[2] << " " << m_counts[3] << " " << m_counts[4] << endl;
                                } else {
                                    m_len = 0;
                                }
                            }
                            break;
                        }
                    }
                }
                if (isOk)
                    return ans;
            }
        }
    }

    return m_numbers[index];
}

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

//    cin >> n;
//    for (size_t i = 0; i < n; i++) {
//        string number;
//        cin >> number;
//        numbers.push_back(number);
//    }

//    n = 3;
//    numbers.push_back("123456789");
//    numbers.push_back("100000000");
//    numbers.push_back("100123456");

//    n = 4;
//    numbers.push_back("934567891");
//    numbers.push_back("123456789");
//    numbers.push_back("193456789");
//    numbers.push_back("134567819");

    n = 25000;
    srand(70);
    unordered_set<int> set;
    for (size_t i = 0; i < n; ++i) {
        unsigned long long value;
        while (true) {
            value = 1 + llrand() % 999999998;
            auto p = set.insert(int(value));
            if (p.second) break;
        }
        char number[10];
        sprintf(number, "%.9d", int(value));
        numbers.push_back(string(number));
    }

    ShortCutCalculator c(numbers);
    clock_t beg = clock();
    for (size_t i = 0; i < n; ++i)
//        cout << c.calc(i) << endl;
        c.calc(i);
    clock_t end = clock();
    int ms = int(double(end - beg) * 1000 / CLOCKS_PER_SEC);
    cout << "Elapsed: " << ms << "ms, voc size is " << c.volume() << endl;

//    c.printVoc(2);

    return 0;
}
