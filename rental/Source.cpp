#include <iostream>
#include <vector>

using namespace std;

class Car {
protected:
	string Name;
	string Model;
	string Color;
	string Gearbox;
	int NumberOfDoors;
	int YearOfFab;
	float PricePerDay;
public:
	Car() {}
	Car(string name, string model, int year, float pricePerDay, string color, string gearbox, int noOfDoors) {
		Name = name;
		Model = model;
		YearOfFab = year;
		PricePerDay = pricePerDay;
		Color = color;
		Gearbox = gearbox;
		NumberOfDoors = noOfDoors;
	}
	//setters
	void setName(string name) {
		Name = name;
	}
	void setModel(string model) {
		Model = model;
	}
	void setYearOfFab(int year) {
		YearOfFab = year;
	}
	void setPrice(float pricePerDay) {
		PricePerDay = pricePerDay;
	}
	void setColor(string color) {
		Color = color;
	}
	void setGearbox(string gearbox) {
		Gearbox = gearbox;
	}
	void setNumberOfDoors(int noOfDoors) {
		NumberOfDoors = noOfDoors;
	}

	//getters
	string getName() {
		return Name;
	}
	string getModel() {
		return Model;
	}
	int getYear() {
		return YearOfFab;
	}
	float getPricePerDay() {
		return PricePerDay;
	}
	string getColor() {
		return Color;
	}
	string getGearbox() {
		return Gearbox;
	}
	int getNumberOfDoors() {
		return NumberOfDoors;
	}
};

class Combustion : public Car {
public:
	string Type;
	Combustion() {}
	Combustion(string name, string model, int year, float pricePerDay, string color, string gearbox, int noOfDoors, string type) :Car(name, model, year, pricePerDay, color, gearbox, noOfDoors) {
		Type = type;
	}

	void setType(string type) {
		Type = type;
	}

	string getType() {
		return Type;
	}

	void printList(vector<Combustion> c) {
		cout << "-------------------------LIST OF CARS-------------------------\n";
		for (int i = 0; i < c.size(); i++) {
			cout << i + 1 << ". " << c[i].getName() << " " << c[i].getModel() << ", " << "price per day: " << c[i].getPricePerDay() << "$. \n";
		}
	}

	Combustion addCar() {
		string name, model, color, gearbox, type;
		int year, numberOfDoors;
		float price;
		cout << "Okay, you want to add a car, first of all, I need a name: ";
		cin >> name;
		cout << "model: ";
		cin >> model;
		cout << "year of fabrication: ";
		cin >> year;
		cout << "price per day: ";
		cin >> price;
		cout << "color: ";
		cin >> color;
		cout << "type of gearbox: ";
		cin >> gearbox;
		cout << "number of doors: ";
		cin >> numberOfDoors;
		cout << "combustion type: ";
		cin >> type;

		Combustion car = (Combustion(name, model, year, price, color, gearbox, numberOfDoors, type));
		return car;
	}

	void removeCar(int cnt, vector<Combustion> c) {
		for (int i = 0; i < c.size(); i++) {
			if (cnt == i)
			{
				c.erase(c.begin() + cnt - 1);
			}
		}
	}

	void specCombustion(vector<Combustion> c) {
		string type;
		string ans;
		cout << "Do you prefer Diesel, Gasoline, Hybrid or Electric ?\nPlease write down:\n";
		cin >> type;
		for (int i = 0; i < c.size(); i++) {
			if (type == c[i].getType())
			{
				cout << i + 1 << "." << c[i].getName() << " " << c[i].getModel() << endl;
				cout << "Do you want more details?\nType 'yes' or 'no': ";
				cin >> ans;
				cout << "--------------------------------------------------------------\n";
				if (ans == "yes") {
					cout << i + 1 << "." << c[i].getName() << " " << c[i].getModel() << ", " << c[i].getYear() << ", " << c[i].getGearbox() << ", " << c[i].getColor() << ", " << c[i].getNumberOfDoors() << ", " << "price/day: " << c[i].getPricePerDay() << "$" << endl;
				}
				else if (ans == "no") {
					cout << "Okay, let me show you again the list: \n";
					cout << i + 1 << "." << c[i].getName() << " " << c[i].getModel() << endl;
				}

			}
		}
		cout << "--------------------------------------------------------------\n";
	}

	void moreDetails(vector<Combustion> c) {
		int iter;
		cout << "Can you please give me the number of the car you would like more details about?\n ";
		cin >> iter;

		for (int i = 0; i < c.size(); i++) {
			if (iter - 1 == i) {
				cout << ">" << c[i].getName() << " " << c[i].getModel() << ", " << c[i].getYear() << ", " << c[i].getGearbox() << ", " << c[i].getColor() << ", number of doors: " << c[i].getNumberOfDoors() << ", " << c[i].getType() << ", " << "price/day: " << c[i].getPricePerDay() << "$" << endl;
			}
		}
	}
};

int main()
{
	string ans;
	int selection = 123;
	int cnt = 1234;
	Combustion car;
	vector<Combustion> carList;
	carList.push_back(Combustion("Toyota", "Auris", 2014, 19.99, "Black", "Manual", 5, "Diesel"));
	carList.push_back(Combustion("Mazda", "3", 2005, 9.99, "Black", "Manual", 5, "Gasoline"));
	carList.push_back(Combustion("Suzuki", "Vitara", 2021, 29.99, "Beige", "Manual", 5, "Hybrid"));
	carList.push_back(Combustion("Toyota", "Prius", 2005, 16.99, "Red", "Automatic", 5, "Hybrid"));
	carList.push_back(Combustion("Dacia", "Logan", 2016, 9.99, "Blue", "Manual", 5, "Gasoline"));
	carList.push_back(Combustion("Opel", "Vectra", 2003, 6.99, "Blue", "Manual", 5, "Diesel"));
	carList.push_back(Combustion("Toyota", "GT86", 2018, 24.99, "Orange", "Manual", 3, "Gasoline"));

	cout << "Hello!\nHere is your car rental app, which allows you to rent out your cars!\nWhat do you want to do?\n";
	do {
		cout << "1.List of cars.\n2.Add a car.\n3.Remove a car.\n4.Car or cars with a specified combustion system.\n5.More details about a car by iteration.\n0.Exit.\n--------------------------------------------------------------\n";
		cin >> selection;
		switch (selection)
		{
		case 1:
			car.printList(carList);
			cout << "--------------------------------------------------------------\n";
			break;
		case 2:
			carList.push_back(car.addCar());
			cout << "--------------------------------------------------------------\n";
			break;
		case 3:
			cout << "Do you want to remove the last car or a specific car?\nAnswer with 'last' or 'specific': ";
			cin >> ans;
			if (ans == "specific") {
				cout << "Okay, you want a specific car, please tell me what car from the list:\n";
				for (int i = 0; i < carList.size(); i++) {
					cout << i + 1 << ". " << carList[i].getName() << " " << carList[i].getModel() << ". \n";
				}
				cout << "What number?\n";
				cin >> cnt;
				for (int i = 0; i < carList.size(); i++) {
					if (cnt == i)
					{
						carList.erase(carList.begin() + cnt - 1);
					}
				}
			}
			else if (ans == "last")
			{
				carList.pop_back();
			}
			cout << "--------------------------------------------------------------\n";
			break;
		case 4:
			car.specCombustion(carList);
			cout << "--------------------------------------------------------------\n";
			break;
		case 5:
			car.printList(carList);
			cout << "--------------------------------------------------------------\n";
			car.moreDetails(carList);
			cout << "--------------------------------------------------------------\n";
			break;
		default:
			cout << "Oupsie! There was a problem from you, not from me! Byeee\n--------------------------------------------------------------\n";
			break;
		}
	} while (selection != 0);

	return 0;
}