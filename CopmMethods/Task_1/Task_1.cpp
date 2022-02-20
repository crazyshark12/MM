﻿// Task_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;


double f(double x)
{
    return 8 * cos(x) - x - 6;
}
double df(double x)
{
    return -8 * sin(x) - 1;
}
double ddf(double x)
{
    return -8 * cos(x);
}
vector <pair<double, double>> separate(double a, double b, double n)
{
    vector <pair<double, double> > data;

    double h = (b - a) / n;
    double x = a, y = a + h;
    double X = f(x), Y;
    while (y <= b)
    {
        Y = f(y);

        if (X * Y < 0)
        {
            cout << x << " " << y << endl;
            data.push_back(make_pair(x, y));
        }
        if (X == 0)
        {
            cout << x << " wow " << endl;
        }
        if (Y == 0)
        {
            cout << y << " wow " << endl;
        }
        X = Y;
        x = y;
        y += h;
    }
    return data;
}
void bisection(double a, double b, double eps)
{
    cout << endl;

    double c = (a + b) / 2;

    double A = f(a);
    double B = f(b);
    double C = f(c);

    bool flag = 0;
    int counter = 0;

    if (A * C > 0 & C * B > 0)
    {
        if (C == 0)
        {
            cout << c << " точный корень" << endl;
            cout << counter << " итераций" << endl;
            return;
        }
        else
        {
            cout << "корней нет, либо он четной кратности";
            cout << counter << " итераций" << endl;
            return;

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
                return;
            }

            if (A * C <= 0)
            {
                b = c;
                B = C;
                c = (a + b) / 2;
                C = f(c);

            }
            else if (C * B <= 0)
            {

                a = c;
                A = C;
                c = (a + b) / 2;
                C = f(c);
            }
        }
    }
    if (!flag)
    {
        cout << "X:=(a+b)/2 = " << (a + b) / 2 << endl;
        cout << "D:=(b-a)/2 = " << (b - a) / 2 << endl;
        cout << c << " корень" << endl;
        cout << C << " невязка" << endl;
        cout << counter << " итераций" << endl;
    }

    return;
}
void Newton(double a, double b, double eps, double start)
{
    cout << endl;
    /*******************************************************************************
    тут я хотел сделать грамотную проверку на знакопостоянство, но что-то застрял
    float left = (a/(pi)) - (int)(a/(pi));
    float right = (b/(pi)) - (int)(b/(pi));
    if(left<=asin(-1/8)<=right || left<=pi - asin(-1/8)<=right || left<=pi/2<=right || left<=-pi/2<=right)

     f(x) =  8*cos(x) -x -6
     f'(x)= -8*sin(x) -1
     f''(x) = -8 cos(x)

     f'(x) != 0  =>  x !=arcsin(-1/8) and  x!= pi - arcsin(-1/8)
     f''(x) != 0  =>  x != pi/2 + pi * k

     *******************************************************************************/
    double x = start;
    double buf = x + 1;
    int counter = 0;
    while (!(df(a) * df(b) > 0 && ddf(a) * ddf(b) > 0 && ddf(start) * f(start) > 0))
    {
        start = start + (b - a) / 10;
        if (start > b)
        {
            cout << " условие теоремы не выполняется" << endl;
            return;
        }
    }

    while (abs(buf - x) > eps)
    {
        buf = x;
        x = x - f(x) / df(x);
        counter++;
    }
    cout << x << " корень" << endl;
    cout << f(x) << " невязка" << endl;
    cout << counter << " итераций" << endl;
    return;

}
void NewtonMod(double a, double b, double eps, double start)
{
    cout << endl;
    /*******************************************************************************
    тут я хотел сделать грамотную проверку на знакопостоянство, но что-то застрял
    float left = (a/(pi)) - (int)(a/(pi));
    float right = (b/(pi)) - (int)(b/(pi));
    if(left<=asin(-1/8)<=right || left<=pi - asin(-1/8)<=right || left<=pi/2<=right || left<=-pi/2<=right)

     f(x) =  8*cos(x) -x -6
     f'(x)= -8*sin(x) -1
     f''(x) = -8 cos(x)

     f'(x) != 0  =>  x !=arcsin(-1/8) and  x!= pi - arcsin(-1/8)
     f''(x) != 0  =>  x != pi/2 + pi * k

     *******************************************************************************/
    double x = start;
    double buf = x + 1;
    int counter = 0;
    while (!(df(a) * df(b) > 0 && ddf(a) * ddf(b) > 0 && ddf(start) * f(start) > 0))
    {
        start = start + (b - a) / 10;
        if (start > b)
        {
            cout << " условие теоремы не выполняется" << endl;
            return;
        }
    }
    double dfx = df(start);
    while (abs(buf - x) > eps)
    {
        buf = x;
        x = x - f(x) / dfx;
        counter++;
    }
    cout << x << " корень" << endl;
    cout << f(x) << " невязка" << endl;
    cout << counter << " итераций" << endl;
    return;

}
void Hord(double a, double b, double eps, double start1, double start2)
{
    cout << endl;

    int counter = 0;
    double x1 = start1;
    double x2 = start2;
    double x3;
    while (abs(x2 - x1) > eps)
    {
        counter++;
        x3 = x2 - f(x2) * (x2 - x1) / (f(x2) - f(x1));
        x1 = x2;
        x2 = x3;
    }
    cout << x3 << " корень" << endl;
    cout << f(x3) << " невязка" << endl;
    cout << counter << " итераций" << endl;
    return;
}
int main()
{
    setlocale(LC_ALL, "");
    double a, b;
    cout << "введите значения a и b" << endl;
    cin >> a >> b;

    double n = 1000000;
    cout << "введите значения n" << endl;
    cin >> n;

    vector <pair<double, double>> sections;
    sections = separate(a, b, n);

    int k;
    cout << "введите k - степень погрешности 10^-k" << endl;
    cin >> k;
    double eps = pow(10, -k);

    cout << "метод бисекции" << endl;
    for (int i = 0; i < sections.size(); i++)
    {
        bisection(sections[i].first, sections[i].second, eps);
    }
    cout << endl;
    cout << "****************метод Ньютона****************" << endl;
    for (int i = 0; i < sections.size(); i++)
    {
        Newton(sections[i].first, sections[i].second, eps, sections[i].first);
    }
    cout << endl;
    cout << "****************модифицированный метод Ньютона****" << endl;
    for (int i = 0; i < sections.size(); i++)
    {
        NewtonMod(sections[i].first, sections[i].second, eps, sections[i].first);
    }

    cout << endl;
    cout << "**************** метод Секущих***********" << endl;
    for (int i = 0; i < sections.size(); i++)
    {
        Hord(sections[i].first, sections[i].second, eps, sections[i].first, sections[i].second);
    }

    return 0;
}
