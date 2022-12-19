#include <iostream>

int main() {
    int y, y1, y2, y3, y4;
    std::cin >> y;
    y = y + 1;
    while (y > 0) {
        y1 = y / 1000;
        y2 = y / 100 % 10;
        y3 = y % 100 / 10;
        y4 = y % 10;
        if (y1 != y2 && y1 != y3 && y1 != y4 && y2 != y3 && y2 != y4 && y3 != y4) {
            std::cout << y;
            break;
        }
        y += 1;
    }
    return 0;
}
