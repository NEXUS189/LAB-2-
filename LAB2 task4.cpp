#include <iostream>
#include <string>
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	char codes;
	bool breakfast, day;
	int nights, guests, price = 0, maxguests = 0;
	cout << "Введите код номера";
	cin >> codes;
	cout << "Введите количество гостей:";
	cin >> guests;
	cout << "Введите количество ночей:";
	cin >> nights;
	cout << "Вы нуждаетесь в завтраке ( 1 если да, 0 - если нет:";
	cin >> breakfast;
	cout << "Бронируете ночи по выходному периоду (1 если да, 0 если нет) :";
	cin >> day;

	switch (codes) {
	case 'S':
	case 's':
		maxguests = 1;
		price = 40;
		break;
	case 'D':
	case 'd':
		maxguests = 2;
		price = 65;
		break;
	case 'F':
	case 'f':
		maxguests = 4;
		price = 95;
		break;
	default :
		cout << "Проверьте корректность своих данных ";

	}
	double dayprice = 1.15 * price;
	double bcost = nights * 7 * guests;
	double discountprice5 = 0.92 * price;
	if (guests > maxguests || guests < 1 || nights < 1 || nights > 30) {
		cout << "Бронирование отклонено";
	}
	else if (codes == 'F' || codes == 'f' && nights >= 7 && breakfast) {
		bcost = 0;
		cout << "Стоимость проживания :" << (dayprice * nights) * 0.92;
	}
	else if (day) {
		cout <<"Стоимость проживания: " << dayprice * nights;
	}
	else if (day && breakfast) {
		cout << "Стоимость проживания:" << dayprice * nights + bcost;
	}
	else if (day && breakfast && nights >= 5) {
		cout << "Стоимость проживания : " <<(1.15 - 1.08) * price * nights + 7 * nights * guests;
	}else if (day && nights >= 5) {

		cout << "Стоимость проживания: " << discountprice5 * nights;
	}
	else if (nights >= 5 && breakfast) {
		cout << "Стоимость проживания :" << discountprice5 * nights + bcost;
	}
	else if (nights >= 5) {
		cout << "Стоимость проживания :" << discountprice5 * nights;
	}
	else if (breakfast) {
		cout << "Стоимость проживания :" << price * nights + bcost;
	}
	else {
		cout << "Стоимость проживания: " << price * nights;
	}
	return 0;
}