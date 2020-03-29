#include <iostream>
#include <stdio.h>
using namespace std;

template <class T, class P = int>
class Air2 {
public:
	Air2(); //по умолчанию
	Air2(const Air2& temp); //копирующий
	Air2(const char* str, const T d, const T a, const P s); //с параметрами
	~Air2();
	void input();
	void print() const;
	Air2<T, P> operator+(const Air2<T, P>& obj);
	Air2<T, P>& operator=(const Air2<T, P>& obj);
	Air2<T, P>& operator+=(const Air2<T, P>& obj);
	bool operator==(const Air2<T, P>& obj) const;
	bool operator!=(const Air2<T, P>& obj) const;

protected:
	char* type = new char[10];		//military or public
	T distance_of_flight;			//дистанци€
	T max_altitude;					//высота полета
	P max_spead;
};

template <class T, class P>
Air2<T, P>::Air2()
{
	distance_of_flight = 425.5;
	max_altitude = 11.4;
	max_spead = 521.2;
	delete[] type;
	type = new char[10];
	strcpy(type, "public");
}

template <class T, class P>
Air2<T, P>::Air2(const Air2<T, P>& temp)
{
	if (&temp != this) {
		distance_of_flight = temp.distance_of_flight;
		max_altitude = temp.max_altitude;
		max_spead = temp.max_spead;
		delete[] type;
		type = new char[strlen(temp.type) + 1];
		strcpy(type, temp.type);
	}
}

template <class T, class P>
Air2<T, P>::Air2(const char* str, const T d, const T a, const P s)
{
	distance_of_flight = d;
	max_altitude = a;
	max_spead = s;
	delete[] type;
	type = new char[strlen(str) + 1];
	strcpy(type, str);
}

template <class T, class P>
Air2<T, P>::~Air2()
{
	delete[] type;
}

template <class T, class P>
void Air2<T, P>::input()
{
	cout << "¬ведите тип (military или public): ";
	cin >> type;
	cout << "¬ведите дистанцию полЄта (км): ";
	cin >> distance_of_flight;
	cout << "¬ведите максимальную высоту полЄта (км): ";
	cin >> max_altitude;
	cout << "¬ведите максимальную скорость (км/ч): ";
	cin >> max_spead;
}

template <class T, class P>
void Air2<T, P>::print() const
{
	cout << type << endl;
	cout << "ƒистанци€ полЄта: " << distance_of_flight << " км\n";
	cout << "ћаксимальна€ высота: " << max_altitude << " км\n";
	cout << "ћаксимальна€ скорость: " << max_spead << " км/ч\n";
}

template <class T, class P>
Air2<T, P> Air2<T, P>::operator+(const Air2<T, P>& obj)
{
	Air2 temp;

	temp.distance_of_flight = distance_of_flight + obj.distance_of_flight;
	temp.max_altitude = max_altitude + obj.max_altitude;
	temp.max_spead = max_spead + obj.max_spead;

	char* tmp = new char[strlen(type) + strlen(obj.type) + 2];
	strcpy(tmp, type);
	strcat(tmp, "-");
	delete[] temp.type;
	temp.type = new char[strlen(tmp) + strlen(obj.type) + 1];
	strcpy(temp.type, strcat(tmp, obj.type));

	delete[] tmp;
	return temp;
}

template <class T, class P>
Air2<T, P>& Air2<T, P>::operator=(const Air2<T, P>& obj)
{
	distance_of_flight = obj.distance_of_flight;
	max_altitude = obj.max_altitude;
	max_spead = obj.max_spead;
	delete[] type;
	type = new char[strlen(obj.type) + 1];
	strcpy(type, obj.type);

	return *this;
}

template <class T, class P>
Air2<T, P>& Air2<T, P>::operator+=(const Air2<T, P>& obj)
{
	distance_of_flight += obj.distance_of_flight;
	max_altitude += obj.max_altitude;
	max_spead += obj.max_spead;

	char* tmp = new char[strlen(type) + strlen(obj.type) + 2];
	strcpy(tmp, type);
	strcat(tmp, "-");
	delete[] type;
	type = new char[strlen(tmp) + strlen(obj.type) + 1];
	strcpy(type, strcat(tmp, obj.type));

	delete[] tmp;
	return *this;
}

template <class T, class P>
bool Air2<T, P>::operator==(const Air2<T, P>& obj) const
{
	return (strcmp(type, obj.type) == 0) ? true : false;
}

template <class T, class P>
bool Air2<T, P>::operator!=(const Air2<T, P>& obj) const
{
	return (strcmp(type, obj.type) == 0) ? false : true;
}

//------------------------------class PersonalTransport-----------------------------

class PersonalTransport {
public:
	PersonalTransport();
	PersonalTransport(const char* name, const double price);
	PersonalTransport(const PersonalTransport& obj);
	~PersonalTransport();
	void set_information();
	void get_information() const;
	PersonalTransport& operator=(const PersonalTransport& obj);
protected:
	char* drivers_name = new char[10];
	double service_a_month;
};

PersonalTransport::PersonalTransport() {
	delete[] drivers_name;
	drivers_name = new char[10];
	strcpy(drivers_name, "Alex");
	service_a_month = 1000;
}

PersonalTransport::PersonalTransport(const char* name, const double price) {
	delete[] drivers_name;
	drivers_name = new char[strlen(name) + 1];
	strcpy(drivers_name, name);
	service_a_month = price;
}

PersonalTransport::PersonalTransport(const PersonalTransport& obj) {
	delete[] drivers_name;
	drivers_name = new char[strlen(obj.drivers_name) + 1];
	strcpy(drivers_name, obj.drivers_name);
	service_a_month = obj.service_a_month;
}

PersonalTransport::~PersonalTransport() {
	delete[] drivers_name;
}

void PersonalTransport::set_information() {
	cout << "¬ведите им€ вашего водител€/пилота: ";
	cin >> drivers_name;
	cout << "¬ведите траты на транспорт в мес€ц: ";
	cin >> service_a_month;
}

void PersonalTransport::get_information() const {
	cout << "»м€ вашего водител€/пилота: " << drivers_name << endl;
	cout << "¬ведите траты на транспорт в мес€ц: " << service_a_month << endl;
}

PersonalTransport& PersonalTransport::operator=(const PersonalTransport& obj) {
	delete[] drivers_name;
	drivers_name = new char[strlen(obj.drivers_name) + 1];
	strcpy(drivers_name, obj.drivers_name);
	service_a_month = obj.service_a_month;

	return *this;
}

//-----------------------------class Plane<T,P>---------------------------------------

template <class T, class P>
class Plane : public Air2<int, double>, public PersonalTransport {
public:
	Plane();
	Plane(const char* str, const int d, const int a, const double s, const char* name, const double price, const int capacity);
	~Plane();
	void input();
	void print() const;

protected:
	int capacity; //вместимость
};

template <class T, class P>
Plane<T, P>::Plane() : Air2(), PersonalTransport()
{
	capacity = 2;
}

template <class T, class P>
Plane<T, P>::Plane(const char* str, const int d, const int a, const double s, const char* name, const double price, const int capacity) : Air2(str, d, a, s), PersonalTransport(name, price)
{
	this->capacity = capacity;
}

template <class T, class P>
Plane<T, P>::~Plane()
{
	Air2::~Air2();
	PersonalTransport::~PersonalTransport();
}

template <class T, class P>
void Plane<T, P>::input()
{
	Air2::input();
	PersonalTransport::set_information();
	cout << "¬ведите вместимость самолЄта: ";
	cin >> capacity;
}

template <class T, class P>
void Plane<T, P>::print() const
{
	Air2::print();
	PersonalTransport::get_information();
	cout << "¬местимость самолЄта: " << capacity << endl;
}


int main() {

	setlocale(LC_ALL, "Russian");

	//------------------------Plane<int, double>---------------------------

	Plane<int, double> my_plane1, my_plane2;

	cout << "¬ведите информацию о первом самолЄте:" << endl;
	my_plane1.input();
	cout << endl << "¬ведите информацию о втором самолЄте:" << endl;
	my_plane2.input();

	cout << endl << "»нформаци€ о первом самолЄте: " << endl;
	my_plane1.print();
	cout << endl << "»нформаци€ о втором самолЄте: " << endl;
	my_plane2.print();
	cout << endl;
	//------------------------Plane<double, int>----------------------------

	Plane<double, int> my_plane3, my_plane4;

	cout << "¬ведите информацию о третьем самолЄте:" << endl;
	my_plane3.input();
	cout << endl << "¬ведите информацию о четвертом самолЄте:" << endl;
	my_plane4.input();

	cout << endl << "»нформаци€ о третьем самолЄте: " << endl;
	my_plane3.print();
	cout << endl << "»нформаци€ о четвертом самолЄте: " << endl;
	my_plane4.print();
	cout << endl;

	//------------------------Plane<double, double>-------------------------

	Plane<double, double> my_plane5, my_plane6;

	cout << "¬ведите информацию о п€том самолЄте:" << endl;
	my_plane5.input();
	cout << endl << "¬ведите информацию о шестом самолЄте:" << endl;
	my_plane6.input();

	cout << endl << "»нформаци€ о п€том самолЄте: " << endl;
	my_plane5.print();
	cout << endl << "»нформаци€ о шестом самолЄте: " << endl;
	my_plane6.print();
	cout << endl;

	//------------------------Plane<int, int>-------------------------------

	Plane<int, int> my_plane7, my_plane8;

	cout << "¬ведите информацию о седьмом самолЄте:" << endl;
	my_plane7.input();
	cout << endl << "¬ведите информацию о восьмом самолЄте:" << endl;
	my_plane8.input();

	cout << endl << "»нформаци€ о седьмом самолЄте: " << endl;
	my_plane7.print();
	cout << endl << "»нформаци€ о восьмом самолЄте: " << endl;
	my_plane8.print();

	system("pause");
	return 0;
}