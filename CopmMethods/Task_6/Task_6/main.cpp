//
//Найти решение Задачи Коши для уравнения y´(x) = f(x, y) с начальным условием y(x 0) = y 0
//следующими методами :
//  1)  Найти точное решение.Вывести на печать таблицу значений точного решения в
//равноотстоящих с шагом h точках   x k = x 0 + k∙h, где k = ‒2, ‒1, 0, …, N;  здесь N и
//h −параметры задачи.
//  2)  Методом разложения в ряд Тейлора(можно ограничиться пятью ненулевыми
//слагаемыми) найти и вывести на печать значения приближённого решения в
//точках   x k = x 0 + k∙h, где k = ‒2, ‒1, 0, …, N.
//  3)  Во всех точках  x k = x 0 + k∙h, где k = ‒2, ‒1, 0, …, N вывести на печать значения
//абсолютной погрешности метода разложения в ряд Тейлора.
//  4)  Используя начало таблицы, построенное в п.2) (значения в точках x k   для k = ‒2,
//‒1, 0, 1, 2), вывести на печать значения приближённого решения, полученного
//экстраполяционным методом Адамса   4 - го порядка в точках   x k = x 0 + k∙h, где
//k = 3, 4, …, N.
//  5)  Методом Рунге - Кутты 4 - го порядка найти и вывести на печать значения
//приближённого решения в точках   x k = x 0 + k∙h, где k = 1, 2, …, N.
//  6)  Найти и вывести на печать значения приближенных решений исходной задачи,
//полученных методом Эйлера и его модификциями в точках x k = x 0 + k∙h, где
//k = 1, 2, …, N.
//  7)  Для всех методов решения Задачи Коши определить абсолютную погрешность
//для последнего значения  y N  ≈ y(x N).


#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>

using namespace std;
double y(double x, int n) 
{
    switch(n)
    {
    case 0:
        return exp(-x) * (x + 1);
    case 1:
        return -x * exp(-x);
    case 2:
        return (x - 1) * exp(-x);
    case 3:
        return (2 - x) * exp(-x);
    case 4:
        return (x - 3) * exp(-x);
    case 5:
        return (4 - x) * exp(-x);
    }
}
double f(double x, double y)
{
    return - y + exp(-x);
}
double factorial(double n)
{
    return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}

double Teylor(double x0, double x)
{
    double sum = 0;
    for (int i = 0; i < 5; i++)
    {
        sum += y(x0, i)/factorial(i) * pow((x - x0), i);
    }
    return sum;
}
int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Задание 6" << endl;
    cout << "дифференциальной уравнение:   y' = - y + exp{-x} " << endl;
    cout << "Задача Коши:                  y(0) = 1" << endl;
    cout << "Точное решение:               y = exp{-x}*(x+1)" << endl;
    double x0 = 0;
    double h = 0.1;
    double N = 10;
    vector<double> yk;
    vector<double> Tyk; // значения по Тейлору
    vector<double> xk;
    vector<double> RKyk; // значения по Рунге-Кутту
    vector<double> Ayk; // значения по Адамсу
    vector<double> Eyk; // значения по Эйлеру
    vector<double> etta; // n = h*f(x,y)
    vector<vector<double>> ras; //таблица разностей

    cout << setprecision(12);
    cout <<endl<< "Аргумент" << "\t" << " точное значение" << endl;
    for (int i = -2; i < N + 1; i++)
    {
        yk.push_back(y(x0 + h * i, 0));
        xk.push_back(x0 + h * i);

        cout << xk[i+2] << "\t\t" << yk[i + 2] << endl;
    }
    // 
    // МЕТОД ТЙЛОРА
    //
    cout << endl << "Метод Тейлора" << endl;
    cout << endl << "Аргумент" << "\t" << "значение по методу Тейлора" << "\t\t"<<"абсолютная погрешность " << endl;
    cout << setprecision(12);
    for (int i = -2; i < N + 1; i++)
    {
        Tyk.push_back(Teylor(x0, xk[i+2]));
        cout << setw(8) << left << xk[i+2] << "\t\t";
        cout << setw(8) << left << Tyk[i+2] << "\t\t\t";
        cout << setw(8) << left << abs(Tyk[i + 2] - yk[i+2]) << endl;
    }

    // 
    // МЕТОД РУНГЕ-КУТТА
    //
    cout << endl << "Метод Рунге-Кутта" << endl;
    cout << endl << "Аргумент" << "\t" << "значение по методу Рунге-Кутта" << "\t" << "абсолютная погрешность" << endl;
    cout << setprecision(12);
    
    double k[4];
    RKyk.push_back(yk[2]);
    for (int i = 1; i < N+2; i++)
    {
        k[0] = h * f(xk[i+1], RKyk[i - 1]);
        k[1] = h * f(xk[i+1] + h/2, RKyk[i - 1] + k[0]/2);
        k[2] = h * f(xk[i+1] + h / 2, RKyk[i - 1] + k[1] / 2);
        k[3] = h * f(xk[i+1] + h, RKyk[i - 1] + k[2]);
        //cout << "k[0] = " <<  k[0] << endl << "k[1] = " << k[1] << endl << "k[2] = " << k[2] << endl << "k[3] = " << k[3]<<endl;
        RKyk.push_back(RKyk[i - 1] + 1/6. * (k[0] + 2*k[1] +2* k[2] + k[3]));
        cout << xk[i+1] << "\t\t" << RKyk[i-1] << "\t\t\t" << abs(yk[i + 1] - RKyk[i-1]) << endl;
    }

    // 
    // МЕТОД АДАМСА
    //
    cout << endl << "Метод Адамса" << endl;
    cout << endl << "Аргумент" << "\t" << "Значение по методу Адамса" << "\t" << "абсолютная погрешность" << endl;
    vector<double> Y;
    Y.resize(N + 3);
    vector<vector<double>> res;
    res.resize(N + 3);
    for (int i = 0; i < N + 3; i++) {
        res[i].resize(6); //задание вектора, размер
    }
    for (int i = 0; i < 5; i++) {
        res[i][0] = x0 + (i - 2) * h;
    } //заполнили иксы
    for (int i = -2; i < 3; i++) {
        int f = i + 2;
        Y[f] = Teylor(x0, x0 + i * h);
    } //заполнили игреки через Тейлора. первые пять
    for (int i = -2; i < 3; i++) {
        int j = i + 2;
        res[j][1] = h * f(res[j][0], Y[j]);
    } //заполнили этта
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4 - i; j++) {
            res[j][i + 2] = res[j + 1][i + 1] - res[j][i + 1];
        }
    } //разности для первых
    for (int i = 4; i < N + 2; i++) {
        Y[i + 1] = Y[i] + res[i][1] + 0.5 * res[i - 1][2] + 5 * res[i - 2][3] / 12 + 3 * res[i - 3][4] / 8 + 251 * res[i - 4][5] / 720;
        res[i + 1][0] = x0 + h * (i - 1);
        res[i + 1][1] = h * f(res[i + 1][0], Y[i + 1]);
        for (int j = 0; j < 4; j++) {
            res[i - j][j + 2] = res[i + 1 - j][j + 1] - res[i - j][j + 1];
        }
    } //цикл с заполнением
    for (int l = 5; l < N + 3; l++) {
        double x = x0 + (l - 2) * h;
        cout  << x <<"\t\t" << Y[l]<<"\t\t\t" << abs(y(x, 0) - Y[l]) << endl;
    }

    // 
    // МЕТОД ЭЙЛЕРА
    //
    cout << endl << "Метод Эйлера" << endl;
    cout << endl << "Аргумент" << "\t" << "Значение по методу Эйлера" << "\t" << "абсолютная погрешность" << endl;

    Eyk.push_back(yk[2]);
    for (int i = 1; i < N+1; i++)
    {
        Eyk.push_back(Eyk[i-1] + h * f(xk[i + 1], Eyk[i - 1]));
    }
    for (int i=0; i < Eyk.size(); i++)
    cout << xk[i+2] << "\t\t" << Eyk[i] << "\t\t\t" << abs(Eyk[i] - yk[i+2]) << endl;


    // 
    // МЕТОД ЭЙЛЕРА 1
    //
    cout << endl << "Метод Эйлера 1" << endl;
    cout << endl << "Аргумент" << "\t" << "Значение по методу Эйлера 1" << "\t" << "абсолютная погрешность" << endl;

    for (int i = 1; i < N+1 ; i++)
    {
        Eyk[i] = (Eyk[i - 1] + h * f(xk[i + 1] + h / 2, Eyk[i - 1] + h / 2 * f(xk[i + 1], Eyk[i - 1])));
    }
    for (int i = 0; i < Eyk.size(); i++)
        cout << xk[i + 2] << "\t\t" << Eyk[i] << "\t\t\t" << abs(Eyk[i] - yk[i + 2]) << endl;

    // 
    // МЕТОД ЭЙЛЕРА 2
    //
    cout << endl << "Метод Эйлера 2" << endl;
    cout << endl << "Аргумент" << "\t" << "Значение по методу Эйлера 2" << "\t" << "абсолютная погрешность" << endl;

    for (int i = 1; i < N+1; i++)
    {
        Eyk[i] = (Eyk[i - 1] + h/2 * ( f(xk[i + 1],Eyk[i - 1]) + f(xk[i + 2], Eyk[i - 1] + h *f (xk[i + 1],Eyk[i - 1])) ));
    }
    for (int i = 0; i < Eyk.size(); i++)
        cout << xk[i + 2] << "\t\t" << Eyk[i] << "\t\t\t" << abs(Eyk[i] - yk[i + 2]) << endl;
}