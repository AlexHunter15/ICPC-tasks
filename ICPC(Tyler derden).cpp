#include <iostream>

int main() {
    int p, q, a;
    std::cin >> p >> q >> a;

    int C = a / (1 + q + p * q);

    int S = q * C;
    int G = p * S;

    std::cout << G << " " << S << " " << C;

    return 0;
}
