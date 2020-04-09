#include <iostream>
#include <stdio.h>
#include <new>
using namespace std;

class bad_value : public exception {};

template <class T, class P = int>
class Air2 {
public:
	Air2(); //�� ���������
	Air2(const Air2& temp); //����������
	Air2(const char* str, const T d, const T a, const P s); //� �����������
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
	T distance_of_flight;			//���������
	T max_altitude;					//������ ������
	P max_spead;
};

template <class T, class P>
Air2<T, P>::Air2()
{
	distance_of_flight = 425.5;
	max_altitude = 11.4;
	max_spead = 521.2;
	delete[] type;
	type = new char[7];
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
	if (distance_of_flight < 0) throw bad_value();
	max_altitude = a;
	if (max_altitude < 0) throw bad_value();
	max_spead = s;
	if (max_spead < 0) throw bad_value();
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
	cout << "������� ��� (military ��� public): ";
	cin >> type;
	cout << "������� ��������� ����� (��): ";
	cin >> distance_of_flight;
	if (distance_of_flight < 0) throw bad_value();
	cout << "������� ������������ ������ ����� (��): ";
	cin >> max_altitude;
	if (max_altitude < 0) throw bad_value();
	cout << "������� ������������ �������� (��/�): ";
	cin >> max_spead;
	if (max_spead < 0) throw bad_value();
}

template <class T, class P>
void Air2<T, P>::print() const
{
	cout << type << endl;
	cout << "��������� �����: " << distance_of_flight << " ��\n";
	cout << "������������ ������: " << max_altitude << " ��\n";
	cout << "������������ ��������: " << max_spead << " ��/�\n";
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
	service_a_month = 10000;
}

PersonalTransport::PersonalTransport(const char* name, const double price) {
	delete[] drivers_name;
	drivers_name = new char[strlen(name) + 1];
	strcpy(drivers_name, name);
	if (price < 0) throw bad_value();
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
	cout << "������� ��� ������ ��������/������: ";
	cin >> drivers_name;
	cout << "������� ����� �� ��������� � �����: ";
	cin >> service_a_month;
	if (service_a_month < 0) throw bad_value();
}

void PersonalTransport::get_information() const {
	cout << "��� ������ ��������/������: " << drivers_name << endl;
	cout << "����� �� ��������� � �����: " << service_a_month << '$' << endl;
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
	Plane(const Plane<T, P>& obj);
	~Plane();
	void input();
	void print() const;
	Plane<T, P>& operator=(const Plane<T, P>& obj);

protected:
	int capacity; //�����������
};

template <class T, class P>
Plane<T, P>::Plane() : Air2(), PersonalTransport()
{
	capacity = 2;
}

template <class T, class P>
Plane<T, P>::Plane(const char* str, const int d, const int a, const double s, const char* name, const double price, const int capacity) : Air2(str, d, a, s), PersonalTransport(name, price)
{
	if (capacity < 0) throw bad_value();
	this->capacity = capacity;
}

template <class T, class P>
Plane<T, P>::Plane(const Plane<T, P>& obj)
{
	if (&obj != this) {
		//data 1st base class
		distance_of_flight = obj.distance_of_flight;
		max_altitude = obj.max_altitude;
		max_spead = obj.max_spead;
		delete[] type;
		type = new char[strlen(obj.type) + 1];
		strcpy(type, obj.type);
		//data 2nd base class
		delete[] drivers_name;
		drivers_name = new char[strlen(obj.drivers_name) + 1];
		strcpy(drivers_name, obj.drivers_name);
		service_a_month = obj.service_a_month;
		//own data
		capacity = obj.capacity;
	}
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
	cout << "������� ����������� ������� (���-�� �������): ";
	cin >> capacity;
	if (capacity < 0) throw bad_value();
}

template <class T, class P>
void Plane<T, P>::print() const
{
	Air2::print();
	PersonalTransport::get_information();
	cout << "����������� �������: " << capacity << " �������" << endl;
}

template <class T, class P>
Plane<T, P>& Plane<T, P>::operator=(const Plane<T, P>& obj)
{
	//data 1st base class
	distance_of_flight = obj.distance_of_flight;
	max_altitude = obj.max_altitude;
	max_spead = obj.max_spead;
	delete[] type;
	type = new char[strlen(obj.type) + 1];
	strcpy(type, obj.type);
	//data 2nd base class
	delete[] drivers_name;
	drivers_name = new char[strlen(obj.drivers_name) + 1];
	strcpy(drivers_name, obj.drivers_name);
	service_a_month = obj.service_a_month;
	//own data
	capacity = obj.capacity;

	return *this;
}

int main() {

	setlocale(LC_ALL, "Russian");
	bool exception;
	//------------------------Plane<int, double>---------------------------

	do {
		try
		{
			exception = false;
			Plane<int, double> my_plane1, my_plane2;

			cout << "������� ���������� � ������ �������:" << endl;
			my_plane1.input();
			my_plane2 = my_plane1;

			Plane<int, double> my_plane3(my_plane2);

			cout << endl << "���������� � ������ �������:" << endl;
			my_plane1.print();
			cout << endl << "���������� � ������ ������� (����� ������� � ������� ��������� =):" << endl;
			my_plane2.print();
			cout << endl << "���������� � ������� ������� (����� ������� � ������� ����������� ������������):" << endl;
			my_plane3.print();
			//����� ������� �������� ������
			cout << endl << "��������� ���������� � ������� �������:" << endl;
			my_plane3.Air2::input();
			my_plane3.set_information();	//����� ��� ������� ����� - PersonalTransport::set_information()
			cout << endl << "����� ���������� �� �������� �������:" << endl;
			my_plane3.Air2::print();
			my_plane3.get_information();
			cout << endl;
		}
		catch (bad_alloc& e) {
			cout << "������ ��� ������ �� ��������. ������� ��� ���." << endl;
			exception = true;
		}
		catch (bad_value& e) {
			cout << "������� ����������������� ��������. ������� ��� ���." << endl;
			exception = true;
		}
	} while (exception == true);
	
	//------------------------Plane<double, int>----------------------------

	do {
		try
		{
			exception = false;
			Plane<double, int> my_plane4, my_plane5;

			cout << "������� ���������� � ��������� �������:" << endl;
			my_plane4.input();
			my_plane5 = my_plane4;

			Plane<double, int> my_plane6(my_plane5);

			cout << endl << "���������� � ��������� �������:" << endl;
			my_plane4.print();
			cout << endl << "���������� � ����� ������� (����� ���������� � ������� ��������� =):" << endl;
			my_plane5.print();
			cout << endl << "���������� � ������ ������� (����� ������ � ������� ����������� ������������):" << endl;
			my_plane6.print();
			//����� ������� �������� ������
			cout << endl << "��������� ���������� � ������ ��������:" << endl;
			my_plane6.Air2::input();
			my_plane6.set_information();
			cout << endl << "����� ���������� � ������ ��������:" << endl;
			my_plane6.Air2::print();
			my_plane6.get_information();

			cout << endl;
		}
		catch (bad_alloc& e) {
			cout << "������ ��� ������ �� ��������. ������� ��� ���." << endl;
			exception = true;
		}
		catch (bad_value& e) {
			cout << "������� ����������������� ��������. ������� ��� ���." << endl;
			exception = true;
		}
	} while (exception == true);

	//------------------------Plane<double, double>-------------------------

	do {
		try
		{
			exception = false;
			Plane<double, double> my_plane7, my_plane8;

			cout << "������� ���������� � ������� �������:" << endl;
			my_plane7.input();
			my_plane8 = my_plane7;

			Plane<double, double> my_plane9(my_plane8);

			cout << endl << "���������� � ������� �������:" << endl;
			my_plane7.print();
			cout << endl << "���������� � ������� ������� (����� �������� � ������� ��������� =):" << endl;
			my_plane8.print();
			cout << endl << "���������� � ������� ������� (����� �������� � ������� ����������� ������������):" << endl;
			my_plane9.print();
			//����� ������� �������� ������
			cout << endl << "��������� ���������� � ������� ��������:" << endl;
			my_plane9.Air2::input();
			my_plane9.set_information();
			cout << endl << "����� ���������� � ������� ��������:" << endl;
			my_plane9.Air2::print();
			my_plane9.get_information();

			cout << endl;
		}
		catch (bad_alloc& e) {
			cout << "������ ��� ������ �� ��������. ������� ��� ���." << endl;
			exception = true;
		}
		catch (bad_value& e) {
			cout << "������� ����������������� ��������. ������� ��� ���." << endl;
			exception = true;
		}
	} while (exception == true);

	//------------------------Plane<int, int>-------------------------------

	do {
		try
		{
			exception = false;
			Plane<int, int> my_plane10, my_plane11;

			cout << "������� ���������� � ������� �������:" << endl;
			my_plane10.input();
			my_plane11 = my_plane10;

			Plane<int, int> my_plane12(my_plane11);

			cout << endl << "���������� � ������� �������:" << endl;
			my_plane10.print();
			cout << endl << "���������� � ������������ ������� (����� �������� � ������� ��������� =):" << endl;
			my_plane11.print();
			cout << endl << "���������� � ����������� ������� (����� ������������� � ������� ����������� ������������):" << endl;
			my_plane12.print();
			//����� ������� �������� ������
			cout << endl << "��������� ���������� � ����������� �������:" << endl;
			my_plane12.Air2::input();
			my_plane12.set_information();
			cout << endl << "����� ���������� � ����������� �������:" << endl;
			my_plane12.Air2::print();
			my_plane12.get_information();

			cout << endl << "���������� � ����������� ������� (����� ��������������):" << endl;
			my_plane12.print();
		}
		catch (bad_alloc& e) {
			cout << "������ ��� ������ �� ��������. ������� ��� ���." << endl;
			exception = true;
		}
		catch (bad_value& e) {
			cout << "������� ����������������� ��������. ������� ��� ���." << endl;
			exception = true;
		}
	} while (exception == true);
	
	std::system("pause");
	return 0;
}