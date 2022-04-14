// Task_3.2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include <iostream>
#include <vector>
#include <utility>
#include <iomanip>
#include <cmath>
#include <cstdlib>

using namespace std;

double f(double x)
{
    return exp(x*3);
}
int main()
{
    setlocale(LC_ALL, "Russian");
    cout.precision(6);

    bool flag = 1;
    while (flag)
    {
        cout << "введите число значений в таблице\n";
        int m = 20; cout << m + 1 << "\n";

        cout << "введите левый конец отрезка\n";
        double A;
        cin >> A;

        cout << "введите шаг h\n";
        double h;
        cin >> h;


        vector< pair<double, double> > tab; //таблица содержащая в первом столбце значения функции, а во втором аргументы
        for (auto i = 0; i < m + 1; i++)
        {
            tab.push_back(make_pair(A + i * h, f(A + i * h)));
            cout << A + i * h << " " << f(A + i * h) << endl;
        }

        /*заполнение первой производной*/
        vector <double> df;
        df.push_back(( (-3) * tab[0].second + 4 * tab[1].second - tab[2].second) / (2 * h));
        for (auto i = 1; i < m; i++)
        {
            df.push_back((tab[i+1].second - tab[i-1].second)/(2*h));
        }
        df.push_back(-1*( (-3) * tab[m].second + 4 * tab[m - 1].second - tab[m - 2].second) / (2 * h));


        /*заполнение второй производной*/
        vector <double> ddf;
        ddf.push_back(0);
        for (auto i = 1; i < m; i++)
        {
            ddf.push_back((tab[i + 1].second - 2*tab[i].second + tab[i - 1].second) / (h * h));
        }
        ddf.push_back(0);

        cout << endl << " таблица производных " << endl;
        cout << setprecision(10);
        for (auto i = 0; i < m + 1; i++)
            cout  << tab[i].first << "\t" << tab[i].second << "\t" << df[i] << "\t" << abs(df[i]- 3 * tab[i].second) << "\t" << (abs(df[i] - 3 * tab[i].second))/ df[i] << "\t" << ddf[i] << "\t" << abs(ddf[i] - 9 * tab[i].second) << "\t" << (abs(ddf[i] - 9 * tab[i].second)) / ddf[i] << endl;


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
