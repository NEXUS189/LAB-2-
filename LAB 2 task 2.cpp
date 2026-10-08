#include <iostream>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    int night;
    double cost = 250;
    bool day, client;

    cout << "Введите количество ночей: ";
    cin >> night;
    cout << "Выходной тариф (1 - да, 0 - нет): ";
    cin >> day;
    cout << "Постоянный клиент (1 - да, 0 - нет): ";
    cin >> client;

    if (night < 1 || night > 30 || cost <= 0) {
        cout << "Количество ночей должно быть от 1 до 30, а цена - положительной!" << endl;
        return 0;
    }

    double total = night * cost;
    if (day) {
        total *= 1.20;
    }

    double discount = 0.0;
    if (night >= 7) {
        discount = 0.10;
    }
    else if (client) {
        discount = 0.05;
    }

    total *= (1.0 - discount);

    cout << "Итоговая стоимость: " << total << endl;

    return 0;
}
