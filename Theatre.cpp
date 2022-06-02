#include "Header.h"
#include <Windows.h>

void Menu() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Ticket T;
	TicketsControl TC;
	for (;;)
	{
		int x = 0;
		do
		{
			system("cls");
			cout << "Что хотите сделать? \n";
			cout << "1. Посмотреть билеты \n";
			cout << "2. Поиск \n";
			cout << "3. Выход \n";
			cout << "Выберите действие -> ";
			cin >> x;
			switch (x)
			{
			case 1:
			{
				system("cls");
				TC.printTickets();
				cout << '\n';
				cout << "Что хотите сделать? \n";
				cout << "1. Продать билеты \n";
				cout << "2. В главное меню \n";
				cout << "3. Выход \n";
				cout << "Выберите действие -> ";
				int y;
				cin >> y;
				switch (y)
				{
				case 1:
				{
					system("cls");
					TC.printTickets();
					cout << '\n';
					T.sell();
					cout << "1. В главное меню \n";
					cout << "2. Выход \n";
					cout << "Выберите действие -> ";
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
						exit(0);
						break;
					default: cout << "Попробуйте снова \n";
					}
					break;
				case 2:
					system("cls");
					Menu();
					break;
				case 3:
					system("cls");
					exit(0);
					break;
				default: cout << "Попробуйте снова \n";
				}
				break;
				}
			}
			case 2:
			{
				system("cls");
				string STicket;
				cout << "Введите название/тип представления/дату(в виде xx/xx/xx)/цену для поиска: \n";
				cin >> STicket;
				int count = 0;
				string* FTickets = TC.Search(STicket, count);
				if (FTickets) {
					for (int i = 0; i < count; i++) {
						cout << FTickets[i] << endl;
					}
					delete[] FTickets;
				}
				else {
					cout << "Не найдено билетов по заданному критерию" << endl;
				}
				cout << "1. Продать билет\n";
				cout << "2. В главное меню \n";
				cout << "3. Выход \n";
				cout << "Выберите действие -> ";
				int z;
				cin >> z;
				switch (z)
				{
				case 1:
					system("cls");
					TC.printTickets();
					cout << '\n';
					T.sell();
					break;
				case 2:
					system("cls");
					Menu();
					break;
				case 3:
					system("cls");
					exit(0);
					break;
				}
			}
			case 3:
			{
				system("cls");
				exit(0);
				break;
			}
			break;
			}
		}while (x < 1 || x > 3);
	} 
}
void Head() {
	cout << "Статус|Название|Тип|Дата|Цена (руб)|Продолжительность (мин)|Ряд|Место|" << endl;
	cout << endl;
}

void TicketsControl::printTickets() {
	setlocale(0, "rus");
	ifstream file("Tickets.txt");
	if (!file.is_open()) {
		cout << "Спектаклей нет!" << '\n';
		return;
	}
	string line;
	Head();
	for (int i = 0; !file.eof(); i++) {
		getline(file, line);
		if (line.empty()) {
			continue;
		}
		cout << i << ' ' << line << endl;
	}
	file.close();
}


string* TicketsControl::Search(const string& STicket, int& count) {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	ifstream file("Tickets.txt");
	if (!file.is_open()) {
		cout << "[-] File is not opened!";
		exit(EXIT_FAILURE);
	}
	string ticket;
	string* FTickets = nullptr;
	string* tmp = nullptr;
	int k = 0;
	while (!file.eof()) {
		getline(file, ticket);
		if (ticket.find(STicket) != -1) {
			k++;
			tmp = new string[k];
			for (int i = 0; i < k - 1; i++) {
				tmp[i] = FTickets[i];
			}
			tmp[k - 1] = ticket;
			delete[] FTickets;
			FTickets = tmp;
		}
	}
	file.close();
	count = k;
	return FTickets;
}

void Ticket::sell() {
	Ticket t;
	vector<string> tickets;
	cout << "Выберите билет, который хотите продать: \n";
	int x = 0;
	cin >> x;
	ifstream file("Tickets.txt");
	if (!file.is_open()) {
		cout << "[-] File is not opened!";
		exit(EXIT_FAILURE);
	}
	string line;
	while (!file.eof()) {
		getline(file, line);
		tickets.push_back(line);
	}
	vector<string> ticket;
	boost::split(ticket, tickets[x], boost::is_any_of("|"));
	if(ticket[0] == "Sold"){
		cout << "Билет уже продан!\n";
	}
	else if (ticket[0] == "Free") {
		ticket[0] = "Sold";
		file.close();
		ofstream File("Tickets.txt");
		t.set_status(ticket[0]);
		t.set_name(ticket[1]);
		t.set_type(ticket[2]);
		t.set_date(ticket[3]);
		t.set_cost(ticket[4]);
		t.set_duration(ticket[5]);
		t.set_row(ticket[6]);
		t.set_seat(ticket[7]);
		File << t.get_status() << '|' << t.get_name() << '|' << t.get_type() << '|' << t.get_date() << '|' << t.get_cost() << '|' << t.get_duration() << '|'
			<< t.get_row() << '|' << t.get_seat() << '|' << endl;
		File.close();
		ifstream Nfile("Tickets.txt");
		string sold_ticket;
		getline(Nfile, tickets[x]);
		sold_ticket = tickets[x];
		Nfile.close();
		ofstream FILE("Tickets.txt");
		for (int i = 0; i < tickets.size(); i++) {
			FILE << tickets[i] << endl;
		}
		cout << "Проданный билет: " << sold_ticket << endl;
		FILE.close();
	}
}

