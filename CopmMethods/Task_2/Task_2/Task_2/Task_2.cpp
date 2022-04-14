// Task_2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
/***************************************************************************
* 
ПАРАМЕТРЫ ЗАДАЧИ (запрашивать у пользователя; вводятся с клавиатуры) :
1)число значений в таблице(в наших обозначениях это m + 1); 
2)концы отрезка[a, b], из которого выбираются узлы интерполяции; 
3)x‒точка интерполирования, значение в которой хотим найти; 
4)n‒степень интерполяционного многочлена, который будет построен для того, чтобы найти значение в точке x.

*****************************************************************************/
#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <cmath>

using namespace std;



bool compare(pair<double, double> a, pair<double, double> b)
{
    return (a.second < b.second);
     
}
double f(double x)
{
    return  x*x / (1 + x*x);
}
double l(double x, int i, vector<double> data)
{
    double answer = 1;
    for (auto k = 0; k < data.size(); k++)
    {
            if (x == data[k] && k == i)
                return 1;
            else if (x == data[k] && k != i)
                return 0;
            if (k == i)
                continue;
            else
            answer = answer * (x - data[k]) / (data[i]-data[k]);
    }
    return answer;
}
double L(double x, vector<double> data)
{
    double answer = 0;
    for (auto i = 0; i < data.size(); i++)
    {
        if (x == data[i])
            return f(data[i]);
        answer += f(data[i]) * l(x, i, data);
    }
    return answer;
}
int main()
{
    setlocale(LC_ALL, "Russian");
    cout.precision(4);
    //srand(80);
    //ifstream str;
    //str.open("data.txt");

    bool flag = 1;
    while (flag)
    {
        cout << "введите число значений в таблице\n";
        int m = 21; cout << m << "\n";

        cout << "введите концы отрезка\n";
        double A, B;
        cin >> A >> B;


        for (auto i = 0; i < m + 1; i++)
        {
            cout << A + i * (B - A) / m << " " << f( A + i * (B - A) / m)<<endl; 
        }

        cout << "введите точку интерполирования \n";
        double x; cin >> x;

        cout << "введите степень интерполяционного многочлена \n";
        int n; cin >> n;

        if (n > m) //проверка на корректность задачи
        {
            cout << "Error n > m \n";
            break;
        }

 
        m--;
        vector <pair<double, double>> data;
        double buf = 0;
        data.push_back(make_pair(A, abs(A - x)));
        for (auto i = 1; i < m+1; i++)
        {
            buf =A+  i * (B - A) / m;
            data.push_back(make_pair(buf, abs(buf - x)));
        }
        sort(data.begin(), data.end(), compare);

        for (auto i = 0; i < n+1; i++)
        {
            cout << data[i].first << " ";
        }
        cout << endl;
        vector <double> new_data;
        for (auto i = 0; i < n+1; i++)
        {
            new_data.push_back(data[i].first);
            
        }
        /************************************************************************/
        cout << endl << "Метод Лагранжа" << endl;
        cout << setprecision(18);
        cout << L(x, new_data);
        cout << endl << "погрешность = ";
        cout << setprecision(18);
        cout << abs(f(x) - L(x, new_data));
        cout << endl;

        /************************************************************************/

        double** massive = new double* [n+1];
        for (auto i = 0; i < n+1; i++)
        {
            massive[i] = new double[n + 2];
        }


        for (auto i = 0; i < n+1; i++) //заполнение массива с данными узлами и их значениями
        {
            massive[i][0] = new_data[i];
            massive[i][1] = f(new_data[i]);
        }
        for (auto j = 2; j < n + 2; j++)
        {
            for (auto i = 0; i < n - j + 1; i++)
            {
                massive[i][j] = (massive[i + 1][j - 1] - massive[i][j - 1]) / (massive[i + j - 1][0] - massive[i][0]);
            }
        }
        cout << endl << endl;

        /******* вывод таблицы разностей */
        cout << "ТАБЛИЦА РАЗНОСТЕЙ" << endl;
        for (auto i = 0; i < n; i++)
        {
            for (auto j = 0; j < n + 1 - i; j++)
            {
                cout << massive[i][j] << " ";
            }
            cout << endl;
        }

        double ans = 0.;
        double buff = 1.;
        int j = 0;
        for (auto i = 1; i < n + 1; i++) //прыгает по слагаемым 
        {
            if (i == 1)
                buff = 1;
            else
            {
                buff *= (x - massive[j][0]); j++;
            }
            ans = ans + massive[0][i] * buff;
        }
        cout << endl << "Метод Ньютона " << endl << ans << endl;
        cout << "погрешность = " << abs(f(x) - ans);
        cout << endl;
        cout << "if you want to continue enter 1? else enter 0" << endl;
        cin >> flag;
        cout << endl;
        
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
