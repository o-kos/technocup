    #include <iostream>
    #include <vector>

    using namespace std;

    struct Kv {
        int k;
        int f;
    };

    bool checkFloors(int k, const vector<Kv> &mind)
    {
        for (const auto &kv : mind) {
            if (kv.k / k != kv.f) return false;
        }
        return true;
    }

    int calcFloor(int n, int k)
    {
        return (n - 1) / k + 1;
    }

    int main()
    {
        int n, m;
        cin >> n;
        cin >> m;

        if (n == 1 && m == 0) {
            cout << 1;
            return 0;
        }

        if (n < 1 || n > 100 || m < 1 || m > 100) {
            cout << -1;
            return 0;
        }

        vector<Kv> mind;
        for (int i = 0; i < m; i++) {
            Kv plan;
            cin >> plan.k;
            cin >> plan.f;
            plan.k--;
            plan.f--;
            mind.push_back(plan);
        }

    //    n = 10;
    //    m = 3;
    //    mind.push_back({5, 1});
    //    mind.push_back({1, 0});
    //    mind.push_back({6, 2});

//        n = 8;
//        m = 3;
//        mind.push_back({ 6, 1 });
//        mind.push_back({ 5, 1 });
//        mind.push_back({ 0, 0 });

        int res = -1;
        for (int k = 1; k <= 100; k++) {
            if (checkFloors(k, mind)) {
                if (res != -1 && calcFloor(n, k) != calcFloor(n, res)) {
                    cout << -1;
                    return 0;
                };
                res = k;
            }
        }

        cout << calcFloor(n, res);

        return 0;
    }
