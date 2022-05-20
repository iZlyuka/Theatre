#ifndef HEADER_H
#define HEADER_H
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

void Menu();

class Tickets {
private:
	string name;
	string date;
	string type;
	string cost;
	string duration;
	string seats;
public:
	void set_name() {
		string NAME;
		getline(cin, NAME);
		name = NAME;
	}
	void set_type() {
		string TYPE;
		getline(cin, TYPE);
		type = TYPE;
	}
	void set_date() {
		string DATE;
		getline(cin, DATE);
		date = DATE;
	}
	void set_cost() {
		string COST;
		getline(cin, COST);
		cost = COST;
	}
	void set_duration() {
		string DURATION;
		getline(cin, DURATION);
		duration = DURATION;
	}
	void set_seats() {
		string SEATS;
		getline(cin, SEATS);
		seats = SEATS;
	}
	string get_name() {
		return name;
	}
	string get_type() {
		return type;
	}
	string get_date() {
		return date;
	}
	string get_cost() {
		return cost;
	}
	string get_duratiion() {
		return duration;
	}
	string get_seats() {
		return seats;
	}
	void buy();
	void ToReserve();
	void Perfomances();
	void Basket();
	void Reserve();
	void head();
	void headBasket();
};

class Seats {
private:
	string amount;
	string cost;
public:
	void set_cost() {
		string COST;
		getline(cin, COST);
		cost = COST;
	}
	void set_amount() {
		string AMOUNT;
		getline(cin, AMOUNT);
		amount = AMOUNT;
	}
	string get_amount() {
		return amount;
	}
	string get_cost() {
		return cost;
	}
};


#endif // HEADER_H