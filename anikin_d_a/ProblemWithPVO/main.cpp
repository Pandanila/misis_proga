#include <iostream>
#include <cmath>
#include <fstream>

#include <iostream>
#include <cmath>

#include <geom.hpp>

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
            if (r_2.y < r_1.y){
                return 2; // недолёт
            }
            if (r_2.y > r_1.y){
                return 3; //перелет
            }
        }
    }
    return 0;
}

int main() {
    Rdec2D core_rad_vector_1 = { 0, 6 };
    Rdec2D core_velocity_1 = { 10, 1000 };
    Rdec2D core_velocity_x_1 = { core_velocity_1.x, 0 };
    Rdec2D core_velocity_y_1 = { 0, core_velocity_1.y };
    Rdec2D core_rad_vector_2 = { 200, 6 };
    Rdec2D core_velocity_2 = { -10, 2000 };
    Rdec2D core_velocity_x_2 = { core_velocity_2.x, 0 };
    Rdec2D core_velocity_y_2 = { 0, core_velocity_2.y };
    Rdec2D g = { 0, -9.8 };
    double s = norm(core_rad_vector_1 - core_rad_vector_2);
    double t_1 = 0;
    double delta_t = 1;
    double delta_v = 10;

    for (double x = -3000; x < 3001; x += delta_v){
        for (double y = 0; y < 3001; y += delta_v){
            int k = collision_of_cores(core_rad_vector_1, core_velocity_x_1, core_velocity_y_1,
                                       core_rad_vector_2, {x, 0}, {0, y},
                                       1, 0);

            if (k == 1) {
                Rdec2D a = {x, 0};
                Rdec2D b = {0, y};
                std::cout << a + b;
            }
        }
    }


}