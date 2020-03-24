#include <iostream>
#include <stdio.h>
using namespace std;

template <class T, class P = int>
class Air2 {
public:
	Air2(); //�� ���������
	Air2(const Air2& temp); //����������
	Air2(const char* str, T d, T a, P s); //� �����������
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
Air2<T, P>::Air2(const char* str, T d, T a, P s)
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
	cout << "������� ��� (military ��� public): ";
	cin >> type;
	cout << "������� ��������� ����� (��): ";
	cin >> distance_of_flight;
	cout << "������� ������������ ������ ����� (��): ";
	cin >> max_altitude;
	cout << "������� ������������ �������� (��/�): ";
	cin >> max_spead;
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

//-----------------------------class Plane<T,P>---------------------------------------

template <class T, class P>
class Plane : public Air2<int, double> {
public:
	Plane();
	Plane(const char* str, T d, T a, P s, const int capacity);
	~Plane();
	void input();
	void print() const;

protected:
	int capacity; //�����������
};

template <class T, class P>
Plane<T, P>::Plane() : Air2()
{
	capacity = 2;
}

template <class T, class P>
Plane<T, P>::Plane(const char* str, T d, T a, P s, const int capacity)
{
	this->capacity = capacity;
}

template <class T, class P>
Plane<T, P>::~Plane()
{
	Air2::~Air2();
}

template <class T, class P>
void Plane<T, P>::input()
{
	Air2::input();
	cout << "������� ����������� �������: ";
	cin >> capacity;
}

template <class T, class P>
void Plane<T, P>::print() const
{
	Air2::print();
	cout << "����������� �������: " << capacity << endl;
}


int main() {

	setlocale(LC_ALL, "Russian");

	//------------------------Plane<int, double>---------------------------

	Plane<int, double> my_plane1, my_plane2;

	cout << "������� ���������� � ������ �������:" << endl;
	my_plane1.input();
	cout << endl << "������� ���������� � ������ �������:" << endl;
	my_plane2.input();

	cout << endl << "���������� � ������ �������: " << endl;
	my_plane1.print();
	cout << endl << "���������� � ������ �������: " << endl;
	my_plane2.print();
	cout << endl;
	//------------------------Plane<double, int>----------------------------

	Plane<double, int> my_plane3, my_plane4;

	cout << "������� ���������� � ������� �������:" << endl;
	my_plane3.input();
	cout << endl << "������� ���������� � ��������� �������:" << endl;
	my_plane4.input();

	cout << endl << "���������� � ������� �������: " << endl;
	my_plane3.print();
	cout << endl << "���������� � ��������� �������: " << endl;
	my_plane4.print();
	cout << endl;

	//------------------------Plane<double, double>-------------------------

	Plane<double, double> my_plane5, my_plane6;

	cout << "������� ���������� � ����� �������:" << endl;
	my_plane5.input();
	cout << endl << "������� ���������� � ������ �������:" << endl;
	my_plane6.input();

	cout << endl << "���������� � ����� �������: " << endl;
	my_plane5.print();
	cout << endl << "���������� � ������ �������: " << endl;
	my_plane6.print();
	cout << endl;

	//------------------------Plane<int, int>-------------------------------

	Plane<int, int> my_plane7, my_plane8;

	cout << "������� ���������� � ������� �������:" << endl;
	my_plane7.input();
	cout << endl << "������� ���������� � ������� �������:" << endl;
	my_plane8.input();

	cout << endl << "���������� � ������� �������: " << endl;
	my_plane7.print();
	cout << endl << "���������� � ������� �������: " << endl;
	my_plane8.print();

	system("pause");
	return 0;
}