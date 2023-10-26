#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    unordered_set<string> at;
    for (int i = 0; i < n; i++) {
        string fn, ln;
        cin >> fn >> ln;
        at.insert(fn + " " + ln);
    }

    int q;
    cin >> q;

    unordered_set<string> aw;
    vector<string> results;

    for (int i = 0; i < q; i++) {
        string name, surname;
        cin >> name >> surname;
        string full = name + " " + surname;
        string rev = surname + " " + name;

        if (at.count(full) || at.count(rev)) {
            if (aw.count(full) || aw.count(rev)) {
                results.push_back("Laughter");
            }
            else {
                results.push_back("Applause");
                aw.insert(full);
                aw.insert(rev);
            }
        }
        else {
            results.push_back("Noise");
        }
    }
    for (const string& res : results) {
        cout << res << endl;
    }

    return 0;
}
