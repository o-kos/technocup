#include <iostream>

using namespace std;

int main()
{
    unsigned long n, k;
    cin >> n;
    cin >> k;

    if (k == 0) {
        cout << n;
        return 0;
    }

    unsigned long long pow = 1;
    for (unsigned long long i = 0; i < k; i++) pow *= 10;

    unsigned long long res = n;
    for (; res < pow * n; res += n) {
        if (res % pow == 0) break;
    }


//    unsigned long long pow = 1;
//    for (unsigned long long i = 0; i < k; i++) pow *= 10;

//    unsigned long long res = pow;
//    for (; res % n != 0; res += pow);

    cout << res;

    return 0;
}
