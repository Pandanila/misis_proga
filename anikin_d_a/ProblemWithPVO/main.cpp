#include <iostream>
#include <cmath>
#include <fstream>
#include <geom.hpp>
#include <vector>

std::vector<double> collision_of_cores(Rdec2D r_1, Rdec2D v_1_x, Rdec2D v_1_y,
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

    std::vector<double> vec;

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
            vec.push_back(1);
            vec.push_back(t);
            return vec;
        }

        if (r_2.x < r_1.x){
            if (r_2.y < r_1.y){ //недолет
                vec.push_back(2);
                vec.push_back(t);
                return vec;
            }
            if (r_2.y > r_1.y){  //перелет
                vec.push_back(3);
                vec.push_back(t);
                return vec;
            }
        }
    }
    vec.push_back(0);
    vec.push_back(t);
    return vec;
}

int main() {
    Rdec2D r_1 = { 0, 6 };
    Rdec2D v_1 = { 100, 800 };
    Rdec2D r_2 = { 3000, 6 };
    Rdec2D v_2 = {0, 0};
    Rdec2D g = {0, -9.8};
    double s = norm(r_1 - r_2);
    double t_of_sound = s / 300;
    double t = 0;
    double delta_t = 1;   //точность изменения скорости
    double delta_v = 10;  //точность подбор скорости для противоядра
    double delta_s = 0;   //точность координаты при столкновении
    double max_t = 0;

    std::vector<Rdec2D> list_of_v;

    int flag = 0;

    for (double x = -500; x < 500; x += delta_v){
        for (double y = 0; y < 1000; y += delta_v){
            for (double delta_k = 0 ; delta_k < 51; delta_k += 1){
                std::vector<double> vec = collision_of_cores(r_1, {v_1.x, 0}, {0, v_1.y}, r_2, {x, 0}, {0, y}, delta_t, delta_k);

                double k = vec[0];

                if (k == 1) {
                    Rdec2D a = {x, y};
                    list_of_v.push_back(a);
                    flag = 1;
                    delta_s = delta_k;
                    max_t = vec[1];
                    std::cout << a;
                    break;
                }
            }
            if (flag){
                break;
            }
        }
        if (flag){
            break;
        }
    }

    std::ofstream file;
    file.open("coords3.csv");


    for (int i = 0; i < list_of_v.size(); i += 1){
        r_1 = { 0, 6 };
        v_1 = { 100, 800 };
        r_2 = { 3000, 6 };
        v_2 = {0, 0};
        t = 0;
        v_2 = list_of_v[i];
        file << v_2 << "\n";
        file << r_1.x << "\t" << r_1.y << " \t" << r_2.x << "\t" << r_2.y << "\t" << t << "\t" << s << "\t" << delta_s << "\n";
        while (t < max_t) {
            t += delta_t;
            v_1 += g;
            r_1 += v_1;

            if (t >= t_of_sound) {
                v_2 += g;
                r_2 += v_2;
            }
            //std::cout << r_1.x << "\t" << r_1.y << " \t" << r_2.x << "\t" << r_2.y << "\n";
            file << r_1.x << "\t" << r_1.y << " \t" << r_2.x << "\t" << r_2.y << "\t" << t << "\t" << s << "\n";
        }
    }

    if (not flag){
        file.close();
        std::cout << "При таких параметрах сбить ядро невохможно";
    }

    file.close();
}
