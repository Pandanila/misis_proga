#include <iostream>
#include <cmath>
#include <geom.hpp>
#include <fstream>


int catching(Rdec2D r_m, Rdec2D r_c, Rdec2D v_m, Rdec2D v_c){
    std::ofstream file;
    file.open("cat_mouse.csv");

    double t = 0;
    double delta_t = 1;
    while (r_c.x > -3){
        v_c = (r_m - r_c) / norm(r_m - r_c) * norm(v_c);
        r_c += v_c;
        r_m += v_m;

        file << r_c.x << "\t" << r_c.y << "\t" << r_m.x << "\t" << r_m.y << "\n";

        if (norm(r_c - r_m) <= 0.5){
            if (-2 <= r_m.x && r_m.x <= 2 && -2 <= r_m.y && r_m.y <= 2) {
                return 1;
            }
        }
    }
    file.close();
    return 0;
}


int main() {
    double y_m = 0;
    double x_c = 0;
    std::cin >> y_m >> x_c;

    Rdec2D r_m = {0, y_m};
    Rdec2D r_c = {x_c, 0};
    Rdec2D v_m = {0, 1};

    int flag = 0;

    for (double x = -1; x > -101; x -= 1){
        for (double y = -1; y > -101; y -= 1){
            Rdec2D v_c = {x, y};
            if (catching(r_m, r_c, v_m, v_c)){
                std::cout << v_c;
                flag = 1;
                break;
            }
        }
        if (flag){
            break;
        }
    }
}