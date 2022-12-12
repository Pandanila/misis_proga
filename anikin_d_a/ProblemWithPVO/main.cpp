#include <iostream>
#include <cmath>
#include <fstream>
#include <geom.hpp>
#include <vector>

int collision_of_cores(Rdec2D r_1, Rdec2D v_1_x, Rdec2D v_1_y,
                       Rdec2D r_2, Rdec2D v_2_x, Rdec2D v_2_y,
                       double delta_t, double delta_s){            /*delta_s - допустимая погрещность в
                                                                    координатах при столкновении*/
    //описываем скалярные величины
    double s = norm(r_1 - r_2);      //расстояние между ядрами
    double t_of_sound = s / 300;         //время, за которое звук дойдет от ядра до противоядра
    double t = 0;                        //счетчик времени
    //описываем векторные величины
    Rdec2D g = {0, -9.8};          //вектор ускорения свободного падения
    Rdec2D v_1 = v_1_x + v_1_y;          // вектор скорости ядра
    Rdec2D v_2 = v_2_x + v_2_y;          // вектор скорости противоядра

    // смотрим, столкнутся или нет
    while (r_1.y >= 0){
        t += delta_t;
        v_1_y += g;
        v_1 = v_1_y + v_1_x;             //считаем вектор скорости ядра в каждый момент времени
        r_1 += v_1;                      //считаем расположение ядра в каждый момент времени

        if (t >= t_of_sound){            //если пришло время, запускаем противоядро
            v_2_y += g;
            v_2 = v_2_y + v_2_x;
            r_2 += v_2;
        }

        if (std::abs(norm(r_1 - r_2)) <= delta_s){
            return 1;
        }

        if (r_2.x < r_1.x){
            if (r_2.y < r_1.y){ //недолет
                return 2;
            }
            if (r_2.y > r_1.y){  //перелет
                return 3;
            }
        }
    }
    return 0;
}

Rdec2D coords_of_core(Rdec2D r, Rdec2D v, Rdec2D g){
    std::vector<double> coords;
    Rdec2D v_x = {v.x, 0};
    Rdec2D v_y = {0, v.y};
    v = v_x + v_y + g;
    r += v;
    coords.push_back(r.x);
    coords.push_back(r.y);
    return r;
}

int main() {
    Rdec2D r_1 = { 0, 6 };
    Rdec2D v_1 = { 10, 1000 };
    Rdec2D r_2 = { 200, 6 };
    Rdec2D v_2 = {0, 0};
    Rdec2D g = {0, -9.8};
    double s = norm(r_1 - r_2);
    double t_of_sound = s / 300;
    double t = 0;
    double delta_t = 1;   //точность изменения скорости
    double delta_v = 10;  //точность подбор скорости для противоядра
    double delta_s = 0;   //точность координаты при столкновении

    std::vector<Rdec2D> list_of_v;

    for (double x = -3000; x < 3001; x += delta_v){
        for (double y = 0; y < 3001; y += delta_v){
            int k = collision_of_cores(r_1, {v_1.x, 0}, {0, v_1.y}, r_2, {x, 0}, {0, y}, delta_t, delta_s);

            if (k == 1) {
                Rdec2D a = {x, 0};
                Rdec2D b = {0, y};
                list_of_v.push_back(a + b);
            }
        }
    }

    std::ofstream file;
    file.open("coords.csv");


    for (int i = 0; i < list_of_v.size(); i += 1){
        r_1 = { 0, 6 };
        v_1 = { 10, 1000 };
        r_2 = { 200, 6 };
        v_2 = {0, 0};
        t = 0;
        v_2 = list_of_v[i];
        file << v_2 << "\n";
        file << r_1.x << "\t" << r_1.y << " \t" << r_2.x << "\t" << r_2.y << "\t" << t << "\t" << s << "\n";
        while (std::abs(norm(r_1 - r_2)) > delta_s) {
            t += delta_t;
            r_1 = coords_of_core(r_1, v_1, g);

            if (t >= t_of_sound) {
                r_2 = coords_of_core(r_2, v_2, g);
            }
            std::cout << r_1.x << "\t" << r_1.y << " \t" << r_2.x << "\t" << r_2.y << "\n";
            file << r_1.x << "\t" << r_1.y << " \t" << r_2.x << "\t" << r_2.y << "\t" << t << "\t" << s << "\n";
        }
    }

    file.close();
}
