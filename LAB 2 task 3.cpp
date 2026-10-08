#include <iostream>
#include <string>
using namespace std;
int main() {
	setlocale(LC_ALL, "Russian");
	char numbers;
	int guests, nights, maxguests = 0, cost = 0;
	cout << "Введите код номера:";
	cin >> numbers;
	cout << "Введите количество гостей:";
	cin >> guests;
	cout << "Введите количество ночей:";
	cin >> nights;
	switch (numbers) {
	case 'S':
	case 's':
		cost = 40;
		maxguests = 1;
		break;
	case 'D':
	case 'd':
		cost = 65;
		maxguests = 2;
		break;
	case 'F':
	case'f':
		cost = 95;
		maxguests = 4;
		break;
	default:
		cout << "Бронированеи отклонено. Проверьте корректность своих данных";
		return 1;
	}
		if (guests > maxguests || guests < 1 || nights <1 ) {
			cout << "Бронированеи отклонено. Проверьте корректность своих данных.";
		} 
		else {
			cout << "Стоимость проживания :" << (nights * cost);
			}
		return 0;

}