// Task_3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <cmath>

using namespace std;

bool compare(pair<pair<double, double> , double> a, pair<pair<double, double>, double> b)
{
    return (a.second < b.second);

}
double f(double x)
{
    return x * x / (1 + x * x);
}
double l(double F, int i, vector <pair< pair<double, double>, double>> data)
{
    double answer = 1;
    for (auto k = 0; k < data.size(); k++)
    {
        if (F == data[k].first.first && k == i)
            return 1;
        else if (F == data[k].first.first && k != i)
            return 0;
        if (k == i)
            continue;
        else
            answer = answer * (F - data[k].first.first) / (data[i].first.first - data[k].first.first);
    }
    return answer;
}
double L(double F, vector <pair< pair<double, double>, double>> data)
{
    double answer = 0;
    for (auto i = 0; i < data.size(); i++)
    {
        if (F == data[i].first.first)
            return data[i].first.second;
        answer += data[i].first.second * l(F, i, data);
    }
    return answer;
}


double l(double x, int i, vector<pair<double,double>> data)
{
    double answer = 1;
    for (auto k = 0; k < data.size(); k++)
    {
        if (x == data[k].second && k == i)
            return 1;
        else if (x == data[k].second && k != i)
            return 0;
        if (k == i)
            continue;
        else
            answer = answer * (x - data[k].second) / (data[i].second - data[k].second);
    }
    return answer;
}
double L(double x, vector<pair<double, double>> data)
{
    double answer = 0;
    for (auto i = 0; i < data.size(); i++)
    {
        if (x == data[i].second)
            return data[i].first;
        answer += data[i].first * l(x, i, data);
    }
    return answer;
}


vector <pair<double, double>> separate(double a, double b, vector<pair<double, double>> data, double F, double n)
{
    vector <pair<double, double> > ans;

    double h = (b - a) / n;
    double x = a, y = a + h;
    double X = L(x,data)-F, Y;
    while (y <= b)
    {
        Y = L(y,data)-F;

        if (X * Y < 0)
        {
            cout << x << " " << y << endl;
            ans.push_back(make_pair(x, y));
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
    return ans;
}
void bisection(double a, double b, vector<pair<double, double>> data ,  double F,double eps)
{

    double c = (a + b) / 2;

    double A = L(a,data) - F;
    double B = L(b, data) - F;
    double C = L(c, data) - F;

    bool flag = 0;
    int counter = 0;

    if (A * C > 0 && C * B > 0)
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
                C = L(c, data) - F;

            }
            else if (C * B <= 0)
            {

                a = c;
                A = C;
                c = (a + b) / 2;
                C = L(c, data) - F;
            }
        }
    }

    {
        {
            cout << "D:=(b-a)/2 = " << (b - a) / 2 << endl;
            cout << c << " корень" << endl;
            cout << abs(C) << "невязка" << endl;
            cout << counter << " итераций" << endl;
            cout << endl;
        }
    }

    return;
}
int main()
{
    setlocale(LC_ALL, "Russian");
    cout.precision(18);

    bool flag = 1;
    while (flag)
    {
        cout << "введите число значений в таблице\n";
        int m = 19; cout << m + 1 << "\n";

        cout << "введите концы отрезка\n";
        double A, B;
        cin >> A >> B;

        vector< pair<double, double> > tab; //таблица содержащая в первом столбце значения функции, а во втором аргументы
        for (auto i = 0; i < m + 1; i++)
        {
            tab.push_back(make_pair(f(A + i * (B - A) / m), A + i * (B - A) / m));
            cout << f(A + i * (B - A) / m) << " " << A + i * (B - A) / m<<endl;
        }

        cout << "введите точку интерполирования F \n";
        double F; cin >> F;

        cout << "введите степень интерполяционного многочлена \n";
        int n; cin >> n;



        m--;
        vector <pair< pair<double, double>, double>> data;
        double buf = 0;
        data.push_back(make_pair(make_pair(tab[0].first, tab[0].second), abs(tab[0].first - F)));
        for (auto i = 1; i < m + 1; i++)
        {
            data.push_back(make_pair(make_pair(tab[i].first, tab[i].second), abs(tab[i].first - F)));
        }
        sort(data.begin(), data.end(), compare);


       
        for (auto i = 0; i < m-n; i++)
        {
            data.pop_back();
        }
        for (auto i = 0; i < data.size(); i++)
        {
            cout << data[i].first.first << " " << data[i].first.second << endl;
        }
        cout << endl;

        /************************************* первый метод, если функция монотонная***********************************/
        cout << endl << "если функция монотонная" << endl;
        cout << L(F, data);
        cout << endl << "модуль невязки = ";
        cout << setprecision(18);
        cout << abs(f(L(F, data)) - F);
        cout << endl<<endl;
        /************************************* второй метод, если функция НЕ монотонная***********************************/
        cout << endl << "если функция не монотонная" << endl;
        double N = 1000000;
        cout << "введите значения n" << endl;
        cin >> N;

        vector <pair<double, double>> sections;
        sections = separate(A, B,tab, F, N);
        //cout << endl << "всего отрезков: " << sections.size() << endl;

        int k;
        cout << "введите k - степень погрешности 10^-k" << endl;
        cin >> k;
        //cout << k << endl;
        double eps = pow(10, -k);

        cout << "**************** метод бисекции ****************" << endl;
        {
            for (int i = 0; i < sections.size(); i++)
            {

                bisection(sections[i].first, sections[i].second,tab, F, eps);
            }
            cout << endl;
        }

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
