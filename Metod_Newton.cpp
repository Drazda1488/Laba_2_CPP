#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Функция, которую нужно решить
double f(double x) {
    return 0.25 * pow(x, 3) + x - 1.2502; // Определяем функцию f(x) = 0.25x³ + x - 1.2502
}

// Производная функции f(x)
double df(double x) {
    return 0.75 * pow(x, 2) + 1; // Производная f'(x) = 0.75x² + 1
}

int main() {
    double x0 = 1.0; // Начальное приближение корня
    double x1 = x0; // Значение x на следующей итерации
    double tolerance = 1e-6; // Точность

    cout << fixed << setprecision(5); // Устанавливаем формат вывода с 5 знаками после запятой

    // Цикл итераций метода Ньютона
    do {
        double pr_xo = df(x0); // Вычисляем значение производной в точке x0
        //Проверка на деление на ноль или очень малое значение производной
        if (abs(pr_xo) < 1e-10) {
            cout << "Производная близка к нулю. Метод Ньютона не сходится." << endl;
            return 1; // Завершаем программу с ошибкой
        }
        x1 = x0 - f(x0) / pr_xo; // Формула метода Ньютона: x_(n+1) = x_n - f(x_n) / f'(x_n)
        x0 = x1; // Обновляем значение x0 для следующей итерации
    } while (abs(x1 - x0) > tolerance); // Продолжаем итерации, пока погрешность больше допустимой

    cout << "Корень уравнения: " << x1 << endl; // Выводим найденный корень
    return 0;
}
