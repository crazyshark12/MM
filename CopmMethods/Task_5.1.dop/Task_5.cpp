//  1.Определить и вывести на печать узлы и коэффициенты КФ Гаусса при 𝑁 = 1, 2, 3, 4, 5, 6, 7, 8//(парами: узел ↔ коэффициент).При нахождении корней многочлена Лежандра использовать
//метод секущих, при этом выбрать точность 𝜖 порядка 10−12
//
//  2. Выборочно осуществить проверку точности на многочлене наивысшей степени, для которого
//соответствующая КФ Гаусса должна быть точна.Например, для 𝑁 = 3, 4, 5 проверять точность
//на многочленах степени 5, 7 и 9 соответственно.
//
//  3. Вычислить интеграл из варианта задания при помощи КФ Гаусса с заданным числом узлов
//(для всех указанных значений параметра 𝑁).При этом, кроме значения интеграла, выводить
//на печать все узлы и коэффициенты КФ, подобной КФ Гаусса, для каждого 𝑁.Предусмотреть
//возможность ввода других значений параметров 𝑎, 𝑏, то есть пересчитывать узлы и коэффи -
//циенты подобной КФ для произвольных 𝑎, 𝑏.
//
//  4. Сделать вывод о верных знаках в значении интеграла.
//  
//  5. Написать программу, позволяющую вычислить приближенно  d𝑥 при помощи КФ
//Мелера с 𝑁1, 𝑁2, 𝑁3 узлами(𝑁1, 𝑁2, 𝑁3 — параметры задачи, запрашивать у пользователя;
//вводятся с клавиатуры).
//Выводить на печать для соответствующих 𝑁1, 𝑁2, 𝑁3
//  1) все узлы и коэффициенты КФ Мелера;
//  2) полученное значение интеграла(не менее 12 знаков после запятой).
//Сравнить полученные приближенные значения между собой.
// 
//  6. Сделать вывод о верных знаках в значении интеграла.
// 
///////////////////////////////////////////////////////////
// 
// Практический блок:Параметры задачи: 
// пределы интегрирования –𝑎, 𝑏(запрашивать у пользователя; вводятся с клави-атуры),
// функции𝜌(𝑥)и𝑓(𝑥)(описать в коде программы).
// 
// 1. Написать программу, позволяющую вычислить приближенно∫︀𝑏𝑎𝜌(𝑥)𝑓(𝑥) d𝑥
// при помощи со-ставной КФ Гаусса с 𝑁 узлами с числом промежутков деления[𝑎, 𝑏]равным 𝑚
// (𝑁 и 𝑚—параметры задачи, запрашивать у пользователя; вводятся с клавиатуры).
// Выводить на печатьисходные параметры 𝑁 и 𝑚; узлы и коэффициенты исходной КФ Гауссав количестве 𝑁 штук.
//  Полученное значение интеграла (не менее 12 знаков после запятой).
// 
// 2. Реализовать приближенное вычисление∫︀𝑏𝑎𝜌(𝑥)𝑓(𝑥) d𝑥при помощи КФ типа Гаусса 
// (КФ НАСТ)с 2-мя узлами.Выводить на печатьвсе промежуточные вычисления: 
// моменты весовой функции, ортого-нальный многочлен, узлы и коэффициенты построенной КФ НАСТ.
// Сделать проверкуна коэффициенты и точность КФ на одночлене𝑥
// 
// 3.Вывести полученное значение интеграла (не менее 12 знаков после запятой).
//  Сравнить полученное значение со значением по составной КФ Гаусса с𝑁узлами.
//
//
//


#include <iostream>
#include <iomanip>
#define pi 3.1415926535897932
#include <cmath>
#include <vector>

using namespace std;
double f(double x);
vector <pair<double, double>> separate(int n, double a, double b,int m)
{
    vector <pair<double, double> > data;
    double N = m; //число промежутков
    double h = (b - a) / N;
    double x = a, y = a + h;
    double X = legendre(n,x), Y;

    while (y <= b)
    {
        Y = legendre(n,y);

        if (X * Y < 0)
        {
            //cout << x << " " << y << endl;
            data.push_back(make_pair(x, y));
        }
        if (X == 0)
        {
            data.push_back(make_pair(x, y));
        }
        if (Y == 0)
        {
            data.push_back(make_pair(x, y));
        }
        X = Y;
        x = y;
        y += h;
    }
    return data;
}
double Hord(double eps, double start1, double start2, int N)
{
    int counter = 0;
    double x1 = start1;
    double x2 = start2;
    double x3 = (x2 + x1) / 2;
    while (abs(x2 - x1) > eps)
    {
        counter++;
        x3 = x2 - legendre(N,x2) * (x2 - x1) / (f(x2) - f(x1));
        x1 = x2;
        x2 = x3;    
    }
    return x3;
}
double bisection(double a, double b,int n, double eps)
{
    if (n == 1)
        return 0;
    double c = (a + b) / 2;

    double A = legendre(n,a);
    double B = legendre(n,b);
    double C = legendre(n,c);

    bool flag = 0;
    int counter = 0;

    if (A * C > 0 && C * B > 0)
    {
        if (C == 0)
        {
            cout << c << " точный корень" << endl;
            cout << counter << " итераций" << endl;
            return c;
        }
        else
        {
            cout << "корней нет, либо он четной кратности";
            cout << counter << " итераций" << endl;
            return 0;

        }
    }
    else
    {
        while ((b - a) > 2 * eps)
        {
            counter++;
            if (C == 0)
            {
                cout << c << " точный корень" << endl;
                flag = 1;
                return c;
            }

            if (A * C <= 0)
            {
                b = c;
                B = C;
                c = (a + b) / 2;
                C = legendre(n,c);

            }
            else if (C * B <= 0)
            {

                a = c;
                A = C;
                c = (a + b) / 2;
                C = legendre(n,c);
            }
        }
    }

    if (!flag)
    {
        {
           /* cout << "D:=(b-a)/2 = " << (b - a) / 2 << endl;
            cout << c << " корень" << endl;
            cout << abs(C) << " невязка" << endl;
            cout << counter << " итераций" << endl;
            cout << endl;*/
            return c;
        }
    }

    return 0;
}
double f(double x)
{
    return x * log(x + 1);
}
double fm(double x)
{
    return pow(cos(x),2);
}
double p(double x)
{
    return 1 / pow(1 - pow(x, 2), 0.5);
}
double fN(int N, double x)
{
    return pow(x, N * 2 - 1) + 3 * x;
}
int main()
{
    setlocale(LC_ALL, "Russian");


    double eps = pow(10, -12);
    double a = 0;
    double b = 1;

    int n = 20;
    int m = 100;


    double integral = 0;

        cout << "введите число узлов =";
        cin >> n;
        cout << endl;
        cout << "введите количество промежутков =";
        cin >> m;
        cout << setprecision(10);
        if (n != 0)
        {
            vector <pair<double, double>> segments;
            segments = separate(n, -1, 1,m);
            cout << endl << segments.size() << endl;
            double h = (b - a) / m;
            vector<double> tk;
            vector<double> Ck;
            for (int i = 0; i < n; i++)
            {

                tk.push_back(Hord(eps, segments[i].first, segments[i].second));
                Ck.push_back(2 * (1 - pow(tk[i], 2)) / (pow(n, 2) * pow(legendre(n - 1, tk[i]), 2)));
                std::cout << tk[i] << '\t'  << Ck[i] << '\n';
            }

            for (int j = 0; j < m; j++)
            {
                for (int i = 0; i < n; i++)
                {
                    double xk = tk[i] * h / 2 + (a + j * h + a + (j + 1) * h) / 2;
                    double Ak = Ck[i] * h / 2;
                    integral += f(xk) * Ak;
                }
            }
            std::cout << "integral = " << integral << std::endl;
            std::cout << std::endl;
            integral = 0;
        }
        integral = 0;
}