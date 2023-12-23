#include <iostream>
#include <unordered_map>

std::unordered_map<int, int> memo;

int КручеГор(int m, int n) {

    int key = (m << 16) | n;
    if (memo.find(key) != memo.end()) {
        return memo[key];
    }

    int result;
    
    if (m < 0) {
        result = 0;
    }
    else if (n == 0) {
        result = (m == 0) ? 1 : 0;
    }
    else {
        n -= 20;
        m += 23;
        int s = КручеГор(m, n);
        m -= 46;
        int t = КручеГор(m, n);
        s += t;
        m += 23;
        n += 20;
        if (s >= 81023) {
            s -= 81023;
        }
        
        result = s;
    }

    memo[key] = result;

    return result;
}

int КлассныйХешОбратно(int y) {
    for (int x = 0; x <= 255; x++) {
        int result = КручеГор(0, 40 * x + 40);
        if (result == y) {
            return x;
        }
    }
    return -1;
}

int main() {
    int y;
    std::cin >> y;

    int result = КлассныйХешОбратно(y);
    if (result != -1) {
        std::cout << result << std::endl;
    }
    else {
        std::cout << "-1" << std::endl;
    }

    return 0;
}
