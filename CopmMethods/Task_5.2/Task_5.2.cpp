// Task_5.2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//  1. Написать программу, позволяющую вычислить приближенно∫︀𝑏𝑎𝜌(𝑥)𝑓(𝑥) d𝑥
//при помощи со-ставной КФ Гаусса с𝑁узлами с числом промежутков деления[𝑎, 𝑏]
//равным𝑚(𝑁и𝑚—параметры задачи, запрашивать у пользователя; вводятся с клавиатуры).
//Выводить на печатьисходные параметры𝑁и𝑚; узлы и коэффициенты исходной КФ Гауссав количестве𝑁штук.
//Полученное значение интеграла (не менее 12 знаков после запятой).
//  2. Реализовать приближенное вычисление∫︀𝑏𝑎𝜌(𝑥)𝑓(𝑥) d𝑥при помощи КФ типа Гаусса (КФ НАСТ)с 2-мя узлами.
//Выводить на печатьвсе промежуточные вычисления: моменты весовой функции, ортого-нальный многочлен, узлы и
//коэффициенты построенной КФ НАСТ.Сделать проверкуна коэффициенты и точность КФ на одночлене𝑥
//  3.Вывести полученное значение интеграла (не менее 12 знаков после запятой). Срав-нитьполученное значение
//со значением по составной КФ Гаусса с𝑁узлами.

#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>

using namespace std;

double f(double x) {
    //return sin(x);
    return x*x*x;
    //return 0.17*x*x*x - 3.5*x*x;
} //функция f

double p(double x) {
    return -x*log(x);
} //функция ро, вес

//double F(double x) {
//    //return -cos(x);
//    //return x * x * x* x / 4;
//    //return 0.17 * x * x * x * x / 4 - 3.5 / 3 * x * x * x;
//}

double x_r(double x, int n) {
    return pow(x, n);
}

double f(double x, int n) {
    return p(x) * x_r(x, n);
}

double q(double a, int m, double h, int n) {
    double sum = 0;
    double y = 0;
    for (int i = 0; i < m; i++) {
        y = a + i * h + h / 2;
        sum += f(y, n);
    }
    return sum;
}

double middle_rectangle(double a, double b, double h, int m, int n) {
    return h * q(a, m, h, n);
} //СКФ средних прямоугольников

double det(double a11, double a12, double a21, double a22, double b1, double b2) {
    return a11 * a22 - a12 * a21;
} //определитель

double det1(double a11, double a12, double a21, double a22, double b1, double b2) {
    return b1 * a22 - a12 * b2;
} //определитель 1, Крамер

double det2(double a11, double a12, double a21, double a22, double b1, double b2) {
    return b2 * a11 - a21 * b1;
} //определитель 2, Крамер

double discr(double a1, double a0) {
    return sqrt(a1 * a1 - 4 * a0);
} //дискриминант омега

int main() {
    setlocale(LC_ALL, "Russian");

    double res = 0;
    double a, b, h, a0, a1, x1, x2, A1, A2, I, J;
    int N = 2;
    int m = 10000;
    double mu0, mu1, mu2, mu3;
    int k = 0;
label0:
    cout << "Введите границы интервала a и b :" << endl;
    cin >> a >> b;
    cout << endl;
    cout << endl;
    h = (b - a) / m;
    //J = F(b) - F(a);
    mu0 = middle_rectangle(a, b, h, m, 0);
    mu1 = middle_rectangle(a, b, h, m, 1);
    mu2 = middle_rectangle(a, b, h, m, 2);
    mu3 = middle_rectangle(a, b, h, m, 3);
    a0 = det1(mu0, mu1, mu1, mu2, -mu2, -mu3) / det(mu0, mu1, mu1, mu2, -mu2, -mu3);
    a1 = det2(mu0, mu1, mu1, mu2, -mu2, -mu3) / det(mu0, mu1, mu1, mu2, -mu2, -mu3);
    x1 = (discr(a1, a0) - a1) / 2;
    x2 = (-discr(a1, a0) - a1) / 2;
    cout << endl <<"узлы " << setprecision(15) << x1<< "\t" <<x2<< endl;
    A1 = det1(1, 1, x1, x2, mu0, mu1) / det(1, 1, x1, x2, mu0, mu1);
    A2 = det2(1, 1, x1, x2, mu0, mu1) / det(1, 1, x1, x2, mu0, mu1);
    cout << endl << "коэффициенты " << setprecision(15) << A1 << "\t" << A2 << endl<<endl;
    I = A1 * f(x1) + A2 * f(x2);
    cout << "Значение момента mu0 " << setprecision(15) << mu0 << endl;
    cout << endl;

    cout << "Значение момента mu1 " << setprecision(15) << mu1 << endl;
    cout << endl;

    cout << "Значение момента mu2 " << setprecision(15) << mu2 << endl;
    cout << endl;

    cout << "Значение момента mu3 " << setprecision(15) << mu3 << endl;
    cout << endl;

    cout << "Значение интеграла в результате работы программы равно: " << setprecision(15) << I << endl;
    cout << endl;

    //cout << "Значение интеграла в результате аналитических вычислений равно: " << setprecision(15) << J << endl;
    //cout << endl;

    //cout << "Значение абсолютной погрешности равно: " << setprecision(15) << abs(J-I) << endl;
    //cout << endl;

    cout << "Если Вы хотите изменить параметры задачи, введите 1, иначе - 2" << endl;
    cin >> k;
    cout << endl;
    cout << endl;
    if (k == 1) {
        goto label0;
    }
    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
