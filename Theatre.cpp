#include "Header.h"
#include <Windows.h>

void Menu() {
	Ticket tickets;
	for (;;)
	{
		int x;
		do
		{
			system("cls");
			cout << "Что хотите сделать? \n";
			cout << "1. Посмотреть спектакли \n";
			cout << "2. Поиск по названию \n";
			cout << "3. Посмотреть купленные билеты \n";
			cout << "4. Посмотреть забранированные билеты \n";
			cout << "5. Выход \n";
			cout << "Выберите действие -> ";
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
				cout << "Выберите действие -> ";
				int y;
				cin >> y;
				switch (y)
				{
				case 1:
					system("cls");
					tickets.Perfomances();
					cout << '\n';
					tickets.buy();
					cout << "1. В главное меню \n";
					cout << "2. Посмотреть купленные билеты \n";
					cout << "3. Выход \n";
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
						//tickets.Basket();
						cout << "1. В главное меню \n";
						cout << "2. Выход \n";
						cout << "Выберите действие -> ";
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
					cout << "1. В главное меню \n";
					cout << "2. Посмотреть купленные билеты \n";
					cout << "3. Выход \n";
					cout << "Выберите действие -> ";
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
						//tickets.Basket();
						cout << "1. В главное меню \n";
						cout << "2. Выход \n";
						cout << "Выберите действие -> ";
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
				//tickets.Basket();
				cout << "1. В главное меню \n";
				cout << "2. Выход \n";
				cout << "Выберите действие -> ";
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
				//tickets.Reserve();
				cout << "1. В главное меню \n";
				cout << "2. Выход \n";
				cout << "Выберите действие -> ";
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
			}
			break;
		}while (x < 1 || x > 5);
	} 
}

void Ticket::Perfomances() {
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
		cout << i << ' ' << line << endl;
	}
	file.close();
}

/*void Ticket::buy() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Ticket buy;
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
	file << buy.get_type() << ' ' << buy.get_name() << ' ' << buy.get_date() << ' '
		<< buy.get_seats() << endl;
	file.close();
}*/

string* TicketsControl::Search(const string& STicket, int count) {
	ifstream file("Perfomances.txt");
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
			k+=1;
			tmp = new string[k];
			for (int i = 0; i < k - 1; i++) {
				tmp[i] = FTickets[i];
			}
			tmp[k - 1] = ticket;
			delete FTickets;
			FTickets = tmp;
		}
	}
	file.close();
	count = k;
	return FTickets;
}

void Ticket::buy() {
	Ticket t;
	vector<string> strs;
	cout << "Выберите билет, который хотите купить: \n";
	int x = 0;
	cin >> x;
	ifstream file("Perfomances.txt");
	if (!file.is_open()) {
		cout << "[-] File is not opened!";
		exit(EXIT_FAILURE);
	}
	string line;
	while (!file.eof()) {
		getline(file, line);
		strs.push_back(line);
	}
	vector<string> ticket;
	boost::split(ticket, strs[x], boost::is_any_of(" "));
	if(ticket[0] == "Sold"){
		state = Sold;
		cout << "Билет уже куплен!\n";
	}
	else if (ticket[0] == "Free") {
		state = Sold;
	}
	file.close();
	ofstream File("Perfomances.txt");
	t.set_status(state);
	t.set_name(ticket[1]);
	t.set_type(ticket[2]);
	t.set_date(ticket[3]);
	t.set_cost(ticket[4]);
	t.set_duration(ticket[5]);
	t.set_row(ticket[6]);
	t.set_seat(ticket[7]);
	File << t.get_status() << ' ' << t.get_name() << ' ' << t.get_type() << ' ' << t.get_date() << ' ' << t.get_cost() << ' ' << t.get_duration() << ' '
		<< t.get_row() << ' ' << t.get_seat() << ' ' << endl;
	File.close();
	ifstream Nfile("Perfomances.txt");
	getline(Nfile, strs[x]);
	Nfile.close();
	ofstream FILE("Perfomances.txt");
	for (int i = 0; i < strs.size(); i++) {
		FILE << strs[i] << endl;
	}
	FILE.close();
}




