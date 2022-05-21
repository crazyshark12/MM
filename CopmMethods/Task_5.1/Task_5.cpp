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
vector <pair<double, double>> separate(int n, double a, double b)
{
    vector <pair<double, double> > data;
    double N = 10000; //число промежутков
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
            //cout << x << " wow " << endl;
        }
        if (Y == 0)
        {
            //cout << y << " wow " << endl;
        }
        X = Y;
        x = y;
        y += h;
    }
    return data;
}
double bisection(double a, double b,int n, double eps)
{

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
    double a = -1;
    double b = 1;

    int n = 20;


    double integral = 0;
    /*
    std::cout << "узел " << '\t' << "коэффициент " << '\n';
    for (int i = 0; i < segments.size(); i++)
    {
        double xk = bisection(segments[i].first, segments[i].second, n, eps);
        double Ak = 2 * (1 - pow(xk, 2)) / (pow(n, 2) * pow(legendre(n - 1, xk), 2));
        std::cout << xk <<'\t' << Ak<<'\n';
        integral += f(xk) * Ak;
    }
    std::cout << "integral = " << integral << std::endl;
    std::cout << std::endl;
    integral = 0;
*/

    while (n != 0)
    {
        cout << "введите число узлов =" ;
        cin >> n;
        cout << endl;
        if (n != 0)
        {
            cout << "введите a,b =";
            cin >> a >> b;

            vector <pair<double, double>> segments;
            segments = separate(n, -1, 1);
            cout << endl << segments.size() << endl;
            for (int i = 0; i < segments.size(); i++)
            {
                double xk = (bisection(segments[i].first, segments[i].second, n, eps));
                double xk_new = (b - a) * 0.5 * (bisection(segments[i].first, segments[i].second, n, eps)) + (b + a) * 0.5;
                double Ak = (b - a) * (1 - pow(xk, 2)) / (pow(n, 2) * pow(legendre(n - 1, xk), 2));
                std::cout << xk_new << '\t' << Ak << '\n';
                integral += f(xk_new) * Ak;
            }
            if (n != 0)
                std::cout << "integral = " << integral << std::endl;
            std::cout << std::endl;
            integral = 0;
        }
        integral = 0;
    }
    n = 1;
    // проверка на многочленах
    std::cout << "проверка на многочленах " << std::endl;
    while (n != 0)
    {
        cout << "введите число узлов =";
        cin >> n;
        cout << endl;
        if (n != 0)
        {
            cout << "введите a,b =";
            cin >> a >> b;
            vector <pair<double, double>> segments;
            segments = separate(n, -1, 1);
            cout << endl << segments.size() << endl;
            for (int i = 0; i < segments.size(); i++)
            {
                double xk = (bisection(segments[i].first, segments[i].second, n, eps));
                double xk_new = (b - a) * 0.5 * (bisection(segments[i].first, segments[i].second, n, eps)) + (b + a) * 0.5;
                double Ak = (b - a) * (1 - pow(xk, 2)) / (pow(n, 2) * pow(legendre(n - 1, xk), 2));
                std::cout << xk_new << '\t' << Ak << '\n';
                integral += fN(n, xk_new) * Ak;
            }
            if (n != 0)
                std::cout << "integral = " << integral << std::endl;
            std::cout << std::endl;
            integral = 0;
        }
        integral = 0;
    }

    

    /*------------------- MELLER -------------------------*/
    std::cout << setprecision(12);
    std::cout << "enter N1 N2 N3 = ";
    double N1, N2, N3;
    std::cin >> N1 >> N2 >> N3;
    std::cout << endl;
    
    std::cout << "узел" << '\t' << '\t' << "коэф " << endl;
    std::cout << endl;
    for (int i = 0; i < N1; i++)
    {
        std::cout << cos((2 * i - 1) * pi / (2 * N1)) << '\t' << pi/N1 << endl;
        integral += fm(cos((2*i -1)*pi/(2*N1)));
    }
    integral *= pi / N1;

    std::cout <<endl<< "integral with N1 points = "<<integral<<std::endl;
    std::cout << endl;

    std::cout << "узел" << '\t' << '\t' << "коэф " << endl;
    std::cout << endl;
    integral = 0;
    for (int i = 0; i < N2; i++)
    {
        std::cout << cos((2 * i - 1) * pi / (2 * N2)) << '\t' << pi / N2 << endl;
        integral += fm(cos((2 * i - 1) * pi / (2 * N2)));
    }
    integral *= pi / N2;
    std::cout << "integral with N2 points = " << integral << std::endl;
    std::cout << endl;

    std::cout << "узел" << '\t'<<'\t' << "коэф " << endl;
    std::cout << endl;
    integral = 0;
    for (int i = 0; i < N3; i++)
    {
        std::cout << cos((2 * i - 1) * pi / (2 * N3)) << '\t' << pi / N3 << endl;
        integral += fm(cos((2 * i - 1) * pi / (2 * N3)));
    }
    integral *= pi / N3;
    std::cout << "integral with N3 points = " << integral << std::endl;
    return 0;
}