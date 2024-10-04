#include "Didenko.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <vector>
#include <chrono>
#include <iomanip>
#include <sstream>
#include <Windows.h>

using namespace std;
using namespace std;
using namespace std::chrono;

class Guest {
private:
	int id;
	string name;
	int age;
	string phone;
	int roomNumber = 0;

	static int lastID;//Статичная переменная для того чтобы id было уникальным
public:
	Guest() {}
	Guest(string name, int age, string phone) :name(name), age(age), phone(phone), id(lastID++) {}

	int getID() {
		return this->id;
	}

	void setRoomNumber(int newRoomNumber) {
		roomNumber = newRoomNumber;
	}

	int getRoomNumber() {
		return this->roomNumber;
	}

	void setName(string newName) {
		name = newName;
	}

	string getName() {
		return this->name;
	}

	void setAge(int newAge) {
		age = newAge;
	}

	int getAge() {
		return age;
	}

	void setPhone(string newPhone) {
		phone = newPhone;
	}

	string getPhone() {
		return phone;
	}

	void info() {
		cout << "ID: " << id << endl;
		cout << "Name: " << name << endl;
		cout << "Age: " << age << endl;
		cout << "Phone number: " << phone << endl;
		cout << "Room number: " << roomNumber << endl;
		cout << "\n\n";
	}
};

class Room {
public:
	virtual ~Room() = default;

	virtual int getID() = 0;
	virtual void setNumber(int newNumber) = 0;
	virtual int getNumber() = 0;
	virtual string getType() = 0;
	virtual void setTitle(string newTitle) = 0;
	virtual string getTitle() = 0;
	virtual void setBeds(int newBed) = 0;
	virtual int getBed() = 0;
	virtual void setStatus(bool newStatus) = 0;
	virtual bool getStatus() = 0;
	virtual void setPrice(int price) = 0;
	virtual int getPrice() = 0;
	virtual int getSizeNow() = 0;

	virtual void addGuest(Guest* guest) = 0;
	virtual void checkOutGuest() = 0;

	virtual void info() = 0;
};

class StandartRoom :public Room {
private:
	int id;
	int number;
	string type = "Standart Room";
	string title;
	int beds;
	bool status = false;
	int price = 2000;
	vector <Guest*> guests;

	static int lastID;
public:
	StandartRoom(int number, int beds, string title) :number(number), beds(beds), title(title), id(lastID++) {}
	~StandartRoom() {
		for (auto g : guests) {
			delete g;
		}
	}

	int getSizeNow() {
		return guests.size();
	}

	int getID() {
		return id;
	}
	void setNumber(int newNumber) {
		number = newNumber;
	}
	int getNumber() {
		return number;
	}
	string getType() {
		return type;
	}
	void setTitle(string newTitle) {
		title = newTitle;
	}
	string getTitle() {
		return title;
	}
	void setBeds(int newBed) {
		beds = newBed;
	}
	int getBed() {
		return beds;
	}
	void setStatus(bool newStatus) {
		status = newStatus;
	}
	bool getStatus() {
		return status;
	}
	void setPrice(int newPrice) {
		price = newPrice;
	}
	int getPrice() {
		return price;
	}

	void addGuest(Guest* guest) {
		if (guests.size() >= beds) {
			throw "В комнате нет места";
		}
		guests.push_back(guest);
		guest->setRoomNumber(number);
	}

	void checkOutGuest() {
		if (guests.size() < 0) {
			throw "В комнате нет гостей";
		}
		guests.clear();
	}

	void info() {
		cout << "ID: " << id << endl;
		cout << "Number: " << number << endl;
		cout << "Type: " << type << endl;
		cout << "Title: " << title << endl;
		cout << "Beds: " << beds << endl;
		cout << "Status: " << status << endl;
		cout << "Guests in room: " << endl;
		if (guests.size() > 0) {
			for (auto g : guests) {
				g->info();
			}
		}
	}
};

class VIPRoom :public Room {
private:
	int id;
	int number;
	string type = "VIP Room";
	string title;
	int beds;
	bool status = false;
	int price = 2000;
	vector <Guest*> guests;

	static int lastID;
public:
	VIPRoom(int number, int beds, string title) :number(number), beds(beds), title(title), id(lastID++) {}
	~VIPRoom() {
		for (auto g : guests) {
			delete g;
		}
	}

	int getSizeNow() {
		return guests.size();
	}

	int getID() {
		return id;
	}
	void setNumber(int newNumber) {
		number = newNumber;
	}
	int getNumber() {
		return number;
	}
	string getType() {
		return type;
	}
	void setTitle(string newTitle) {
		title = newTitle;
	}
	string getTitle() {
		return title;
	}
	void setBeds(int newBed) {
		beds = newBed;
	}
	int getBed() {
		return beds;
	}
	void setStatus(bool newStatus) {
		status = newStatus;
	}
	bool getStatus() {
		return status;
	}
	void setPrice(int newPrice) {
		price = newPrice;
	}
	int getPrice() {
		return price;
	}

	void addGuest(Guest* guest) {
		if (guests.size() >= beds) {
			throw "В комнате нет места";
		}
		guests.push_back(guest);
		guest->setRoomNumber(number);
	}

	void checkOutGuest() {
		if (guests.size() < 0) {
			throw "В комнате нет гостей";
		}
		guests.clear();
	}

	void info() {
		cout << "ID: " << id << endl;
		cout << "Number: " << number << endl;
		cout << "Type: " << type << endl;
		cout << "Title: " << title << endl;
		cout << "Beds: " << beds << endl;
		cout << "Status: " << status << endl;
		cout << "Guests in room: " << endl;
		if (guests.size() > 0) {
			for (auto g : guests) {
				g->info();
			}
		}
	}
};

class PremiumRoom :public Room {
private:
	int id;
	int number;
	string type = "Premium Room";
	string title;
	int beds;
	bool status = false;
	int price = 2000;
	vector <Guest*> guests;

	static int lastID;
public:
	PremiumRoom(int number, int beds, string title) :number(number), beds(beds), title(title), id(lastID++) {}
	~PremiumRoom() {
		for (auto g : guests) {
			delete g;
		}
	}

	int getSizeNow() {
		return guests.size();
	}

	int getID() {
		return id;
	}
	void setNumber(int newNumber) {
		number = newNumber;
	}
	int getNumber() {
		return number;
	}
	string getType() {
		return type;
	}
	void setTitle(string newTitle) {
		title = newTitle;
	}
	string getTitle() {
		return title;
	}
	void setBeds(int newBed) {
		beds = newBed;
	}
	int getBed() {
		return beds;
	}
	void setStatus(bool newStatus) {
		status = newStatus;
	}
	bool getStatus() {
		return status;
	}
	void setPrice(int newPrice) {
		price = newPrice;
	}
	int getPrice() {
		return price;
	}

	void addGuest(Guest* guest) {
		if (guests.size() >= beds) {
			throw "В комнате нет места";
		}
		guests.push_back(guest);
		guest->setRoomNumber(number);
	}

	void checkOutGuest() {
		if (guests.size() < 0) {
			throw "В комнате нет гостей";
		}
		guests.clear();
	}

	void info() {
		cout << "ID: " << id << endl;
		cout << "Number: " << number << endl;
		cout << "Type: " << type << endl;
		cout << "Title: " << title << endl;
		cout << "Beds: " << beds << endl;
		cout << "Status: " << status << endl;
		cout << "Guests in room: " << endl;
		if (guests.size() > 0) {
			for (auto g : guests) {
				g->info();
			}
		}
	}
};

class LuxRoom :public Room {
private:
	int id;
	int number;
	string type = "Lux Room";
	string title;
	int beds;
	bool status = false;
	int price = 2000;
	vector <Guest*> guests;

	static int lastID;
public:
	LuxRoom(int number, int beds, string title) :number(number), beds(beds), title(title), id(lastID++) {}
	~LuxRoom() {
		for (auto g : guests) {
			delete g;
		}
	}

	int getSizeNow() {
		return guests.size();
	}

	int getID() {
		return id;
	}
	void setNumber(int newNumber) {
		number = newNumber;
	}
	int getNumber() {
		return number;
	}
	string getType() {
		return type;
	}
	void setTitle(string newTitle) {
		title = newTitle;
	}
	string getTitle() {
		return title;
	}
	void setBeds(int newBed) {
		beds = newBed;
	}
	int getBed() {
		return beds;
	}
	void setStatus(bool newStatus) {
		status = newStatus;
	}
	bool getStatus() {
		return status;
	}
	void setPrice(int newPrice) {
		price = newPrice;
	}
	int getPrice() {
		return price;
	}

	void addGuest(Guest* guest) {
		if (guests.size() >= beds) {
			throw "В комнате нет места";
		}
		guests.push_back(guest);
		guest->setRoomNumber(number);
	}

	void checkOutGuest() {
		if (guests.size() < 0) {
			throw "В комнате нет гостей";
		}
		guests.clear();
	}

	void info() {
		cout << "ID: " << id << endl;
		cout << "Number: " << number << endl;
		cout << "Type: " << type << endl;
		cout << "Title: " << title << endl;
		cout << "Beds: " << beds << endl;
		cout << "Status: " << status << endl;
		cout << "Guests in room: " << endl;
		if (guests.size() > 0) {
			for (auto g : guests) {
				g->info();
			}
		}
	}
};

class Bill {
private:
	int id;
	int guestID;
	int roomID;
	float amount = 0;
	time_t checkInDate;
	time_t checkOutDate;

	static int lastID;
public:
	Bill(int guestID, int roomID) :guestID(guestID), roomID(roomID), id(lastID++) {
		this->checkInDate = time(nullptr);
	}

	int getID() {
		return id;
	}

	int getGuestID() {
		return guestID;
	}

	void setGuestID(int newID) {
		guestID = newID;
	}

	int getRoomID() {
		return roomID;
	}

	void setRoomID(int newID) {
		roomID = newID;
	}

	float getAmount() {
		return amount;
	}

	void setAmount(float newAmount) {
		amount = newAmount;
	}

	time_t getCheckIn() {
		return checkInDate;
	}

	void setCheckIn(time_t newCheckIn) {
		checkInDate = newCheckIn;
	}

	time_t getCheckOut() {
		return checkOutDate;
	}

	void setCheckOut(time_t newCheckIn) {
		checkOutDate = newCheckIn;
	}

	void info() {
		cout << "ID:" << id << endl;
		cout << "Guest ID: " << guestID << endl;
		cout << "Room ID: " << roomID << endl;
		/*cout << "Check in date: " << checkInDate << endl;
		cout << "Check out date: " << checkOutDate << endl;*/
	}
};

class HotelManagement {
private:
	vector <Guest*> guests;
	vector <Room*> rooms;
	vector <Bill*> bills;

public:
	HotelManagement() {}

	Room* searchEmptyRoom(int beds, string type) {
		Room* room;
		for (auto r : rooms) {
			if (r->getStatus() == false && r->getBed() <= beds && r->getType() == type) {
				room = r;
				r->info();
				return room;
			}
		}
	}

	Room* addRoom(int number, int beds, string title) {
		Room* room;
		if (title == "Standart Room") {
			room = new StandartRoom(number, beds, title);
		}

		else if (title == "VIP Room") {
			room = new VIPRoom(number, beds, title);
		}

		else if (title == "Premium Room") {
			room = new PremiumRoom(number, beds, title);
		}

		else if (title == "Lux Room") {
			room = new LuxRoom(number, beds, title);
		}

		else {
			throw "Неправильное название комнаты";
		}
		rooms.push_back(room);
		return room;
	}

	void addRoom(Room* room) {//Перегрузка чтобы в массив можно было передавать объекты
		rooms.push_back(room);
	}

	Guest* addGuest(string name, int age, string phone) {
		Guest* newGuest = new Guest(name, age, phone);
		guests.push_back(newGuest);
		return newGuest;
	}

	void addGuest(Guest* guest) {//Перегрузка чтобы в массив можно было передавать объекты
		guests.push_back(guest);
	}

	void addGuestToRoom(Guest* guest, Room* room) {
		if (room->getSizeNow() <= 0) {
			throw "В комнате не живет владелец!";
		}
		room->addGuest(guest);
	}

	void checkInGuest(Guest* guest, Room* room) {
		room->addGuest(guest);
		Bill* newBill = new Bill(guest->getID(), room->getID());
		bills.push_back(newBill);
	}

	void checkOutGuests(Room* room) {
		room->checkOutGuest();
	}

	void showGuests() {
		for (auto g : guests) {
			g->info();
		}
	}

	void showRooms() {
		for (auto r : rooms) {
			r->info();
		}
	}

	void showBills() {
		for (auto b : bills) {
			b->info();
		}
	}

};

void menu() {
	cout << "Добро пожаловать в отель: \n выберите действие: \n 1 - добавить гостя \n 2 - добавление комнаты" << endl;
	int result = 0;
	cin >> result;
	HotelManagement* h1 = new HotelManagement();
	if (result == 1) {
		string name;
		int age;
		string phone;
		cout << "Введите имя гостя: " << endl;
		cin >> name;
		cout << "Введите возраст гостя: " << endl;
		cin >> age;
		cout << "Введите номер гостя: " << endl;
		cin >> phone;
		Guest* newGuest = new Guest(name, age, phone);
		h1->addGuest(newGuest);
	}
	else if (result == 2) {
		int number;
		string title;
		int beds;
		int type;
		cout << "Выберите вид комнаты: \n 1 - Standart \n 2 - VIP \n 3 - Premium \n 4 - Lux" << endl;
		cin >> type;
		cout << "Введите номер комнаты: " << endl;
		cin >> number;
		cout << "Введите название комнаты: " << endl;
		cin >> title;
		cout << "Введите кровати в комнате: " << endl;
		cin >> beds;
		if (type == 1) {
			StandartRoom* r1 = new StandartRoom(number, beds, title);
			h1->addRoom(r1);
		}
		else if (type == 2) {
			VIPRoom* r1 = new VIPRoom(number, beds, title);
			h1->addRoom(r1);
		}
		else if (type == 3) {
			PremiumRoom* r1 = new PremiumRoom(number, beds, title);
			h1->addRoom(r1);
		}
		else if (type == 4) {
			LuxRoom* r1 = new LuxRoom(number, beds, title);
			h1->addRoom(r1);
		}
		else {
			cout << "неправильно выбрано действие" << endl;
		}
	}
	else {
		cout << "неправильно выбрано действие" << endl;
	}
}

int Guest::lastID = 0;
int StandartRoom::lastID = 0;
int VIPRoom::lastID = 0;
int PremiumRoom::lastID = 0;
int LuxRoom::lastID = 0;
int Bill::lastID = 0;

int main()
{
	setlocale(LC_ALL, "rus");

	menu();
}