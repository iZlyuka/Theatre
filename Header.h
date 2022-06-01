#ifndef HEADER_H
#define HEADER_H
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <boost/algorithm/string.hpp>

using namespace std;

void Menu();

class Ticket {
private:
	string state;
	string name;
	string date;
	string type;
	string cost;
	string duration;
	string row;
	string seat;
public:
	void set_status(string STATE) {
		state = STATE;
	}
	void set_name(string NAME) {
		name = NAME;
	}
	void set_type(string TYPE) {
		type = TYPE;
	}
	void set_date(string DATE) {
		date = DATE;
	}
	void set_cost(string COST) {
		cost = COST;
	}
	void set_duration(string DURATION) {
		duration = DURATION;
	}
	void set_row(string ROW){
		row = ROW;
	}
	void set_seat(string SEAT) {
		seat = SEAT;
	}
	string get_status() {
		return state;
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
	string get_duration() {
		return duration;
	}
	string get_row() {
		return row;
	}
	string get_seat() {
		return seat;
	}
	void sell();
};

class TicketsControl {
public:
	string* Search(const string&, int&);
	void printTickets();
};

void Head();

#endif // HEADER_H
