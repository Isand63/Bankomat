#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <stdlib.h>

using namespace std;

class person
{
private:
    int money = 0;
    int man;
public:
    void including(int set)
    {
        man = set;
    }
    int CheckPin() const
    {
        cout << man;
        return man;
    }
    void check(int pin)
    {
        int EnteringData = pin;
        if (EnteringData == man)
        {
            cout << "Верный пин-код\n";
        }
        else
        {
            cout << "неверный пин-код\n";
            exit(EXIT_SUCCESS);
        }  
    }
    int GetBalance() const
    {
        cout << money;
        return money;
    }
    void BalanceOut(int balout)
    {
        money -= balout;
    }
    void SetBalance(int setbal)
    {
        money += setbal;
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");
    int YN, BS;
    int login, signin;
    int InsertMoney;
    person data;
    bool run = true , run2 = true, run3 = true;
    while (run)
    {
        run = false;
        cout << "Зарегистрированы ли вы в нашем банке ? 1-да/2-нет ";
        cout << endl;
        cin >> YN;
            switch (YN)
            {
            case 1:
                cout << "Введите пин-код: ";
                cin >> login;
                data.check(login);
                break;

            case 2:
                cout << "Зарегистрируйтесь\n";
                cout << "Придумайте пин-код: ";
                cin >> signin;
                data.including(signin);
                run = true;
                break;

            default:
                cout << "неправильная команда\n";

                run = true;
            }
    }
    while (run2)
    {
        run2 = false;
        cout << "Добро пожаловать\n" << "Выберите функцию\n1-Отобразить баланс\n2-Пополнение счёта\n3-Снятие со счёта\n4-Регистрация нового пользователя\n5-Отображение Пин-кода\n6-Выйти из приложения\n";
        cout << endl;
        cin >> YN;
        switch (YN)
        {
        case 1:
            cout << "Ваш Баланс: ";
            data.GetBalance();
            cout << endl;
            run2 = true;
            break;

        case 2:
            cout << "Крупными купюрами-1 или маленькими-2 ?\n";
            cin >> BS;
            switch (BS)
            {
            case 1:
                cout << "Внесите купюры 1000, 2000, 5000\n";
                cin >> InsertMoney;
                if (InsertMoney == 1000 or 2000 or 5000)
                {
                    data.SetBalance(InsertMoney);
                }
                else
                {
                    cout << "Неправильный ввод\n";
                }
                break;
            case 2:
                cout << "Внесите купюры 50, 100, 200, 500\n";
                cin >> InsertMoney;
                if (InsertMoney == 50 or 100 or 200 or 500)
                {
                    data.SetBalance(InsertMoney);
                }
                else
                {
                    cout << "Неправильный ввод\n";
                }
                break;
            default:
                cout << "Неверный ввод\n";
                break;
            }
            run2 = true;
            break;

        case 3:
            cout << "Крупными купюрами-1 или маленькими-2 ?\n";
            cin >> BS;
            switch (BS)
            {
            case 1:
                cout << "выдача 1000, 2000, 5000\n";
                cin >> InsertMoney;
                if (InsertMoney == 1000 or 2000 or 5000)
                {
                    data.BalanceOut(InsertMoney);
                }
                else
                {
                    cout << "Неправильный ввод\n";
                }
                break;
            case 2:
                cout << "выдача 50, 100, 200, 500\n";
                cin >> InsertMoney;
                if (InsertMoney == 50 or 100 or 200 or 500)
                {
                    data.BalanceOut(InsertMoney);
                }
                else
                {
                    cout << "Неправильный ввод\n";
                }
                break;
            default:
                cout << "Неверный ввод\n";
                break;
            }
            run2 = true;
            break;

        case 4:
            cout << "введите pin нового пользователя: ";
            cin >> login;
            cout << endl;
            data.including(login);
            data.SetBalance(0);
            run2 = true;
            break;

        case 5:
            data.CheckPin();
            cout << endl;
            run2 = true;
            break;

        case 6:
            exit(EXIT_SUCCESS);
            break;

        default:
            cout << "неправильная команда\n";
            run2 = true;
        }
    }
    return 0;
}