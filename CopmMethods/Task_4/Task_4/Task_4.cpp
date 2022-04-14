// Task_4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
/*

1)Параметры задачи: пределы интегрирования a, b(запрашивать у пользовате-ля, вводить с клавиатуры).
2)Для случая легко интегрируемой функции f(x)(выбрать на свое усмотре-ние)вычислить точно и вывести
на печать значение интеграла от f(x)по ко-нечному [a, b](считаем вес ρ(x)≡1).(Обозначим это значение за J).
3)Вычислить приближённо и вывести на печать значение интеграла от f(x)по [a, b] при помощи 
        •КФ левого прямоугольника;
        •КФ правого прямоугольника;
        •КФ среднего прямоугольника;
        •КФ трапеции;
        •КФ Симпсона (или парабол);
        •КФ3.
4)Посчитать и вывести на печать абсолютную фактическую погрешность для каждой КФ.
5)Проанализировать полученные результаты(устно).

*/
#include <iostream>
#include <cmath>

double max(double a, double b, int m, double(*foo)(double))
{
    double res = abs(foo(a));
    double h = (b - a) / m;
    for (int i = 1; i < m+1; i++)
    {
        res = std::max(abs(foo(a + h * i)), res);
    }
    return res;
}

////////////////////////////////
double f0(double x)
{
    return 7;
}
double df0(double x)
{
    return 0;
}
double ddf0(double x)
{
    return 0;
}
double dddf0(double x)
{
    return 0;
}
double ddddf0(double x)
{
    return 0;
}
double F0(double x)
{
    return 7*x;
}
////////////////////////////////
double f1(double x)
{
    return 3*x + 1;
}
double df1(double x)
{
    return 3;
}
double ddf1(double x)
{
    return 0;
}
double dddf1(double x)
{
    return 0;
}
double ddddf1(double x)
{
    return 0;
}
double F1(double x)
{
    return (3/2.) * x * x + x;
}
/////////////////////////////////
double f3(double x) // x^3 + 2 * x^2 - 10*x +1 
{
    return pow(x,3) + 2*pow(x,2) - 10*x + 1;
}
double df3(double x)
{
    return 3*pow(x, 2) + 4*x - 10;
}
double ddf3(double x)
{
    return 6 * x + 4;
}
double dddf3(double x)
{
    return 6 ;
}
double ddddf3(double x)
{
    return 0;
}
double F3(double x)
{
    return pow(x, 4) / 4 + 2 * pow(x, 3)/3 - 5 * x*x + x;
}
/////////////////////////////////
double f4(double x) // 0.5*x^4 + x^3 + 2 * x^2 - 10*x +1 
{
    return 0.5 *pow(x, 4) + pow(x, 3) + 2 * pow(x, 2) - 10 * x + 1;
}
double df4(double x)
{
    return 2* pow(x, 3) + 3 * pow(x, 2) + 4 * x - 10;
}
double ddf4(double x)
{
    return 6* pow(x, 2) + 6 * x + 4;
}
double dddf4(double x)
{
    return 12 * x + 6;
}
double ddddf4(double x)
{
    return 12;
}
double F4(double x)
{
    return 0.1*pow(x,5) + pow(x, 4) / 4 + 2 * pow(x, 3) / 3 - 5 * x * x + x;
}
////////////////////////////////exponent//
double fe(double x) 
{
    return exp(x);
}
double dfe(double x)
{
    return exp(x);
}
double ddfe(double x)
{
    return exp(x);
}
double dddfe(double x)
{
    return exp(x);
}
double ddddfe(double x)
{
    return exp(x);
}
double Fe(double x)
{
    return exp(x);
}


double leftRectandle(double a, double b, double(*f)(double))
{
    return (f(a) * (b - a));
}
double rightRectandle(double a, double b, double(*f)(double))
{
    return f(b) * (b - a);
}
double avgRectandle(double a, double b, double(*f)(double))
{
    return f((a + b) / 2) * (b - a);
}
double trap(double a, double b, double(*f)(double))
{
    return ((f(b) + f(a)) * (b - a) / 2.);
}
double simpson(double a, double b, double(*f)(double))
{
    return ((b - a) / 6.) * (f(a) + f(b) + 4 * f((a + b) / 2.));
}
double three(double a, double b, double(*f)(double))
{
    double h = (b - a) / 3.;
    return ((b - a) / 8) * (f(a) + 3 * f(a+h)+ 3*f(a+2*h) + f(b));
}

using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");

    double a, b;
    cout << "введите a и b\n";
    cin >> a >> b;

    /*double(*f)(double) = &f1;
    double(*df)(double) = &df1;
    double(*ddf)(double) = &ddf1;
    double(*dddf)(double) = &dddf1;
    double(*ddddf)(double) = &ddddf1;
    double(*F)(double) = &F1;*/

    /*double(*f)(double) = &f3;
    double(*df)(double) = &df3;
    double(*ddf)(double) = &ddf3;
    double(*dddf)(double) = &dddf3;
    double(*ddddf)(double) = &ddddf3;
    double(*F)(double) = &F3;*/

    /*double(*f)(double) = &f4;
    double(*df)(double) = &df4;
    double(*ddf)(double) = &ddf4;
    double(*dddf)(double) = &dddf4;
    double(*ddddf)(double) = &ddddf4;
    double(*F)(double) = &F4;*/

    double(*f)(double) = &fe;
    double(*df)(double) = &dfe;
    double(*ddf)(double) = &ddfe;
    double(*dddf)(double) = &dddfe;
    double(*ddddf)(double) = &ddddfe;
    double(*F)(double) = &Fe;

    double J = F(b) - F(a);
    cout << "значение интеграла: " << J<<endl;

    cout << endl;
    cout << "\t\t\t\tКФ левого прямоугольника\n";
    cout << leftRectandle(a,b, f) << endl;
    cout <<  "абсолютная фактическая погрешность\n";
    cout << abs(leftRectandle(a, b, f) - J) << endl;

    cout << endl;
    cout << "\t\t\t\tКФ правго прямоугольника\n";
    cout << rightRectandle(a, b,f) << endl;
    cout << "абсолютная фактическая погрешность\n";
    cout << abs(rightRectandle(a, b, f) - J) << endl;

    cout << endl;
    cout << "\t\t\t\tКФ среднего прямоугольника\n";
    cout << avgRectandle(a, b, f) << endl;
    cout << "абсолютная фактическая погрешность\n";
    cout << abs(avgRectandle(a, b, f) - J) << endl;

    cout << endl;
    cout << "\t\t\t\tКФ трапеции\n";
    cout << trap(a, b,f) << endl;
    cout << "абсолютная фактическая погрешность\n";
    cout << abs(trap(a, b, f) - J) << endl;

    cout << endl;
    cout << "\t\t\t\tКФ Симпсона\n";
    cout << simpson(a, b, f) << endl;
    cout << "абсолютная фактическая погрешность\n";
    cout << abs(simpson(a, b, f) - J) << endl;

    cout << endl;
    cout << "\t\t\t\tКФ 3/8\n";
    cout << three(a, b, f) << endl;
    cout << "абсолютная фактическая погрешность\n";
    cout << abs(three(a, b, f) - J) << endl;

    ////////////////////////////////////////////////////////////////
    
    /////////////////////////*второе задание*///////////////////////
    
    ////////////////////////////////////////////////////////////////
    cout << "--------------------------------ВТОРОЕ ЗАДАНИЕ--------------------------- \n\n";

    ////////////////////// левый ////////////////////////
    int m = 1000000;
    cin >> m;
    double sum = 0;
    double h = (b - a) / m;
    int d = 0;
    for (int i = 0; i < m  ; i++)
    {
        //cout << leftRectandle(a, b) << endl;
        sum += leftRectandle(a + h*i, a + h * (i+1), f);

        
    }
    cout << endl;
    cout << "\t\t\t\tКФ левого прямоугольника\n";
    cout << sum << endl;
    cout << "абсолютная фактическая погрешность\n";
    cout << abs(sum - J) << endl;
    cout << "теоретическая погрешность\n";
    double M = max(a, b, m, df);
    double C = 1/2.;
    cout << M * C * pow((b - a), d + 2) / pow(m, d + 1)<<endl;

    sum = 0;
 ////////////////////// правый////////////////////////
    for (int i = 0; i < m; i++)
    {
        sum += rightRectandle(a + h * i, a + h * (i + 1),f);

    }
    cout << endl;
    cout << "\t\t\t\tКФ правого прямоугольника\n";
    cout << sum << endl;
    cout << "абсолютная фактическая погрешность\n";
    cout << abs(sum - J) << endl;
    cout << "теоретическая погрешность\n";
    d = 0;
    M = max(a, b, m, df);
    C = 1/2.;
    cout << M * C * pow((b - a), d + 2) / pow(m, d + 1) << endl;
    sum = 0;
 ////////////////////// средний ////////////////////////
    for (int i = 0; i < m; i++)
    {
        sum += avgRectandle(a + h * i, a + h * (i + 1),f);

    }
    cout << endl;
    cout << "\t\t\t\tКФ среднего прямоугольника\n";
    cout << sum << endl;
    cout << "абсолютная фактическая погрешность\n";
    cout << abs(sum - J) << endl;
    cout << "теоретическая погрешность\n";
    d = 1;
    M = max(a, b, m, ddf);
    C = 1 / 24.;
    cout << M * C * pow((b - a), d + 2) / pow(m, d + 1) << endl;
    sum = 0;
////////////////////// трапеция ////////////////////////
    for (int i = 0; i < m; i++)
    {
        sum += trap(a + h * i, a + h * (i + 1), f);

    }
    cout << endl;
    cout << "\t\t\t\tКФ трапеции\n";
    cout << sum << endl;
    cout << "абсолютная фактическая погрешность\n";
    cout << abs(sum - J) << endl;
    cout << "теоретическая погрешность\n";
    d = 1;
    M = max(a, b, m, ddf);
    C = 1 / 14.;
    cout << M * C * pow((b - a), d + 2) / pow(m, d + 1) << endl;
    sum = 0;
////////////////////// симпсон ////////////////////////
    for (int i = 0; i < m ; i++)
    {
        sum += simpson(a + h * i, a + h * (i + 1),f);

    }
    cout << endl;
    cout << "\t\t\t\tКФ симпсона\n";
    cout << sum << endl;
    cout << "абсолютная фактическая погрешность\n";
    cout << abs(sum - J) << endl;
    cout << "теоретическая погрешность\n";
    d = 3;
    M = max(a, b, m, ddddf);
    C = 1/12880.;
    cout << M * C * pow((b - a), d + 2) / pow(m, d + 1) << endl;
    sum = 0;

 //////////////////////// 3/8 ////////////////////////
 //   for (int i = 0; i < m ; i++)
 //   {
 //       sum += three(a + h * i, a + h * (i + 1),f);

 //   }
 //   cout << endl;
 //   cout << "\t\t\t\tКФ 3/8\n";
 //   cout << sum << endl;
 //   cout << "абсолютная фактическая погрешность\n";
 //   cout << abs(sum - J) << endl;
 //   sum = 0;



    ////////////////////////////////////////////////////////////////

    /////////////////////////*третье задание*///////////////////////

    ////////////////////////////////////////////////////////////////
    cout << "--------------------------------ТРЕТЬЕ ЗАДАНИЕ--------------------------- \n\n";

    ////////////////////// левый ////////////////////////
    sum = 0;
    double sum_new = 0;
    int l;
    cin >> l;
    h = (b - a) / m;
    double h_new = (b - a) / (m * l);
    
    d = 0;
    for (int i = 0; i < m ; i++)
    {
        sum += leftRectandle(a + h * i, a + h * (i + 1), f);
    }
    for (int i = 0; i < m*l ; i++)
    {
        sum_new += leftRectandle(a + h_new * i, a + h_new * (i + 1), f);

    }
    cout << endl;
    cout << "\t\t\t\tКФ левого прямоугольника\n";
    cout << sum_new << endl;
    cout << "абсолютная фактическая погрешность\n";
    cout << abs(sum_new - J) << endl;
    cout << "уточненное значение\n";
    cout << (pow(l, d + 1) * sum_new - sum) / (pow(l, d + 1) - 1) << endl;
    cout << "абсолютная фактическая погрешность уточненного значения\n";
    cout << abs(J - (pow(l, d + 1) * sum_new - sum) / (pow(l, d + 1) - 1));
    

    sum = 0;
    sum_new = 0;
    ////////////////////// правый////////////////////////
    for (int i = 0; i < m ; i++)
    {
        sum += rightRectandle(a + h * i, a + h * (i + 1), f);
    }
    for (int i = 0; i < m * l ; i++)
    {
        sum_new += rightRectandle(a + h_new * i, a + h_new * (i + 1), f);

    }
    cout << endl;
    cout << "\t\t\t\tКФ правого прямоугольника\n";
    cout << sum_new << endl;
    cout << "абсолютная фактическая погрешность\n";
    cout << abs(sum_new - J) << endl;
    cout << "уточненное значение\n";
    d = 0;
    cout << (pow(l, d + 1) * sum_new - sum) / (pow(l, d + 1) - 1) << endl;
    cout << "абсолютная фактическая погрешность уточненного значения\n";
    cout << abs(J - (pow(l, d + 1) * sum_new - sum) / (pow(l, d + 1) - 1));

    sum = 0;
    sum_new = 0;
    ////////////////////// средний ////////////////////////
    for (int i = 0; i < m ; i++)
    {
        sum += avgRectandle(a + h * i, a + h * (i + 1), f);
    }
    for (int i = 0; i < m * l ; i++)
    {
        sum_new += avgRectandle(a + h_new * i, a + h_new * (i + 1), f);

    }
    cout << endl;
    cout << "\t\t\t\tКФ среднего прямоугольника\n";
    cout << sum_new << endl;
    cout << "абсолютная фактическая погрешность\n";
    cout << abs(sum_new - J) << endl;
    cout << "уточненное значение\n";
    d = 1;
    cout << (pow(l, d + 1) * sum_new - sum) / (pow(l, d + 1) - 1) << endl;
    cout << "абсолютная фактическая погрешность уточненного значения\n";
    cout << abs(J - (pow(l, d + 1) * sum_new - sum) / (pow(l, d + 1) - 1));

    sum = 0;
    sum_new = 0;
    ////////////////////// трапеция ////////////////////////
    for (int i = 0; i < m ; i++)
    {
        sum += trap(a + h * i, a + h * (i + 1), f);
    }
    for (int i = 0; i < m * l ; i++)
    {
        sum_new += trap(a + h_new * i, a + h_new * (i + 1), f);

    }
    cout << endl;
    cout << "\t\t\t\tКФ трапеции\n";
    cout << sum_new << endl;
    cout << "абсолютная фактическая погрешность\n";
    cout << abs(sum_new - J) << endl;
    cout << "уточненное значение\n";
    d = 1;
    cout << (pow(l, d + 1) * sum_new - sum) / (pow(l, d + 1) - 1) << endl;
    cout << "абсолютная фактическая погрешность уточненного значения\n";
    cout << abs(J - (pow(l, d + 1) * sum_new - sum) / (pow(l, d + 1) - 1));

    sum = 0;
    sum_new = 0;
    ////////////////////// симпсон ////////////////////////
    for (int i = 0; i < m ; i++)
    {
        sum += simpson(a + h * i, a + h * (i + 1), f);
    }
    for (int i = 0; i < m * l ; i++)
    {
        sum_new += simpson(a + h_new * i, a + h_new * (i + 1), f);

    }
    cout << endl;
    cout << "\t\t\t\tКФ симпсона\n";
    cout << sum_new << endl;
    cout << "абсолютная фактическая погрешность\n";
    cout << abs(sum_new - J) << endl;
    cout << "уточненное значение\n";
    d = 3;
    cout << (pow(l, d + 1) * sum_new - sum) / (pow(l, d + 1) - 1)<<endl;
    cout << "абсолютная фактическая погрешность уточненного значения\n";
    cout << abs(J - (pow(l, d + 1) * sum_new - sum) / (pow(l, d + 1) - 1));

    sum = 0;
    sum_new = 0;


    //cout << endl << J;
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
