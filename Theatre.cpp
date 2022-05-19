#include "Header.h"
#include <Windows.h>
#include <iostream>
#include <fstream>

void Menu() {
	Tickets tickets;
	for (;;)
	{
		cout << "Что хотите сделать? \n";
		cout << "1. Посмотреть спектакли \n";
		cout << "2. Поиск по названию \n";
		cout << "3. Посмотреть купленные билеты \n";
		cout << "4. Посмотреть забранированные билеты \n";
		cout << "5. Выход \n";
		cout << "Выберите действие -> \n";
		int x;
		cin >> x;
		switch (x)
		{
		case 1:
			system("cls");
			//tickets.head();
			tickets.Perfomances();
			cout << "Что хотите сделать? \n";
			cout << "1. Купить билеты \n";
			cout << "2. Забронировать билеты \n";
			cout << "3. В главное меню \n";
			cout << "4. Выход \n";
			cout << "Выберите действие -> \n";
			int y;
			cin >> y;
			switch (y)
			{
			case 1:
				system("cls");
				tickets.Perfomances();
				tickets.buy();
				cout << "1. В главное меню \n";
				cout << "2. Посмотреть купленные билеты \n";
				cout << "3. Выход \n";
				int e;
				cin >> e;
				switch (e)
				{
				case 1:
					system("cls");
					Menu();
					break;
				case 2:
					system("cls");
					tickets.Basket();
					cout << "1. В главное меню \n";
					cout << "2. Выход \n";
					cout << "Выберите действие -> \n";
					int c;
					cin >> c;
					switch (c)
					{
					case 1:
						system("cls");
						Menu();
						break;
					case 2:
						system("cls");
						exit(0);
						break;
					}
					break;
				case 3:
					system("cls");
					exit(0);
					break;
				default: cout << "Попробуйте снова \n";
				}
				break;
			case 2:
				system("cls");
				tickets.Perfomances();
				tickets.ToReserve();
				cout << "1. В главное меню \n";
				cout << "2. Посмотреть купленные билеты \n";
				cout << "3. Выход \n";
				int q;
				cin >> q;
				switch (q)
				{
				case 1:
					system("cls");
					Menu();
					break;
				case 2:
					system("cls");
					tickets.Basket();
					cout << "1. В главное меню \n";
					cout << "2. Выход \n";
					cout << "Выберите действие -> \n";
					int d;
					cin >> d;
					switch (d)
					{
					case 1:
						system("cls");
						Menu();
						break;
					case 2:
						system("cls");
						exit(0);
						break;
					}
					break;
				case 3:
					system("cls");
					exit(0);
					break;
				default: cout << "Попробуйте снова \n";
				}
				break;
			case 3:
				system("cls");
				Menu();
				break;
			case 4:
				system("cls");
				exit(0);
				break;
			default: cout << "Попробуйте снова \n";
			}
			break;
		case 3:
			system("cls");
			tickets.Basket();
			cout << "1. В главное меню \n";
			cout << "2. Выход \n";
			cout << "Выберите действие -> \n";
			int z; 
			cin >> z;
			switch (z)
			{
			case 1:
				system("cls");
				Menu();
				break;
			case 2:
				system("cls");
				exit(0);
				break;
			}
			break;
		case 4:
			system("cls");
			tickets.Reserve();
			cout << "1. В главное меню \n";
			cout << "2. Выход \n";
			cout << "Выберите действие -> \n";
			int s;
			cin >> s;
			switch (s)
			{
			case 1:
				system("cls");
				Menu();
			case 2:
				system("cls");
				exit(0);
				break;
			}
			break;
		case 5:
			system("cls");
			exit(0);
			break;
		default: cout << "Попробуйте снова \n";
		}
		break;
	}
}

void Tickets::Perfomances() {
	setlocale(0, "rus");
	ifstream file("Perfomances.txt");
	if (!file.is_open()) {
		cout << "Спектаклей нет!" << '\n';
		return;
	}
	string line;
	for (int i = 0; !file.eof(); i++) {
		getline(file, line);
		if (line.empty()) {
			continue;
		}
		cout << i + 1 << ' ' << line << endl;
	}
	file.close();
}

void Tickets::Basket() {
	setlocale(0, "rus");
	ifstream file("Basket.txt");
	if (!file.is_open()) {
		cout << "Корзина пуста!" << '\n';
		return;
	}
	string line;
	for (int i = 0; !file.eof(); i++) {
		getline(file, line);
		if (line.empty()) {
			continue;
		}
		cout << i + 1 << ' ' << line << endl;
	}
	file.close();
}

void Tickets::Reserve() {
	setlocale(0, "rus");
	ifstream file("Reserve.txt");
	if (!file.is_open()) {
		cout << "Нет забронированных билетов!" << '\n';
		return;
	}
	string line;
	for (int i = 0; !file.eof(); i++) {
		getline(file, line);
		if (line.empty()) {
			continue;
		}
		cout << i + 1 << ' ' << line << endl;
	}
	file.close();
}

void Tickets::buy() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Tickets buy;
	ofstream file("Basket.txt");
	if (!file.is_open()) {
		cout << "[-] File is not opened!";
		exit(EXIT_FAILURE);
	}
	buy.set_type();
	cout << "Введите тип представления на которое вы хотите купить билеты\n";
	buy.set_name();
	cout << "Введите название представления на которое хотите купить билеты\n";
	buy.set_date();
	cout << "Введите дату представления \n";
	buy.set_seats();
	cout << "Введите кол-во мест \n";
	buy.set_seats();
	file << buy.get_type() << ' ' << buy.get_name() << ' ' << buy.get_date() << ' ' << buy.get_seats() << endl;
	file.close();
}

void Tickets::ToReserve() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Tickets reserve;
	ofstream file("Reserve.txt");
	if (!file.is_open()) {
		cout << "[-] File is not opened!";
		exit(EXIT_FAILURE);
	}
	reserve.set_type();
	cout << "Введите тип представления билеты на которое хотите забронировать билеты\n";
	reserve.set_name();
	cout << "Введите название представления на которое хотите забронировать билеты\n";
	reserve.set_date();
	cout << "Введите дату представления \n";
	reserve.set_seats();
	cout << "Введите кол-во мест \n";
	reserve.set_seats();
	file << reserve.get_type() << ' ' << reserve.get_name() << ' ' << reserve.get_date() << ' ' << reserve.get_seats() << endl;
	file.close();
}

void Tickets::head()
{
	for (int i(0); i < 62; i++) cout << "-";
	cout << endl;
	cout << "| Вид" << "|Название" << "|Дата" << "|Цена(руб)" << "|Длит-ть представления(мин)" << "|Свободных мест|" << endl;
	for (int i(0); i < 62; i++) cout << "-";
	cout << endl;
}

void Tickets::headBasket()
{
	for (int i(0); i < 62; i++) cout << "-";
	cout << endl;
	cout << "| Название " << "| Дата " << "| Партер " << "| Амфитеатр " << "| Бельэтаж " << "| Балкон " << "| Ложа |" << endl;
	for (int i(0); i < 62; i++) cout << "-";
	cout << endl;
}
