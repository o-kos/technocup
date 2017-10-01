#include<string>
#include<iostream>

using namespace std;

bool isVowel(char c)
{
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int main()
{
    string word;
//    cin >> word;
    getline(cin, word);
//    word = "jxegxxx";
//    word = "orfyaenanabckumulsboloyhljhacdgcmnooxvxrtuhcslxgslfpnfnyejbxqisxjyoyvcvuddboxkqgbogkfz";
//    orf yaenanabc kumuls boloyh l j hacd g c m nooxv x r tuhc s l x g s l f p n f n yejb x qisx j yoyv c vudd boxk q g bogk f z
//    orf yaenanabc kumuls boloyh lj hacd gc mnooxv xr tuhc sl xg sl fp nf nyejb xqisx jyoyv cvudd boxk qg bogk fz


    if (word.length() < 3) {
        cout << word;
        return 0;
    }

    string res = "";
    int sg = 0, eq = 0;
    char last = ' ';
    for (auto c : word) {
        if (isVowel(c)) {
            sg = 0;
            eq = 0;
            last = ' ';
        } else {
            if (c == last) {
                eq++;
            } else {
                if (!sg) last = c;
                sg++;
                if (eq + sg > 2) {
                    res += ' ';
                    last = ' ';
                    sg = 0;
                }
                eq = 0;
            }
        }
        res += c;
    }

//    res += word[0];
//    for (size_t i = 1; i < word.length() - 1; ++i) {
//        res += word[i];
//        if (!isVowel(word[i - 1]) && !isVowel(word[i]) && !isVowel(word[i + 1])) {
//            if (!(word[i - 1] == word[i] && word[i] == word[i + 1])) {
//                res += ' ';
//                word[i] = 'a';
//            }
//        }
//    }
//    res += word[word.length() - 1];

    cout << res;

    return 0;
}
