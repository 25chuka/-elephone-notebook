#include <iostream>
#include <Windows.h>
#include <iterator>
#include <set>

using namespace std;

class Contact {
public:
	int birthDate[3];
	string surname;
	int telephoneNumber;

	friend ostream& operator<<(ostream& out, const Contact& contact);
	friend istream& operator>>(istream& in, Contact& contact);
	bool operator<(const Contact& c) const {
		if (birthDate[2] != c.birthDate[2])
			return (birthDate[2] < c.birthDate[2]);
		if (birthDate[1] != c.birthDate[1])
			return (birthDate[1] < c.birthDate[1]);
		if (birthDate[0] != c.birthDate[0])
			return (birthDate[0] < c.birthDate[0]);
		if (surname != c.surname)
			return (surname < c.surname);
		return telephoneNumber < c.telephoneNumber;
	}
};


ostream& operator<<(ostream& out, const Contact& contact)
{
	out << "Фамилия : " << contact.surname << endl
		<< "Дата рождения : " << contact.birthDate[0] << "." << contact.birthDate[1] << "." << contact.birthDate[2] << endl
		<< "Телефон : " << contact.telephoneNumber << endl << endl;
	return out;
}

istream& operator>>(istream& in, Contact& contact)
{
	cout << "Введите Фамилию : ";
	in >> contact.surname;
	cout << "Дата рождения : " << endl;
	cout << "День : ";
	in >> contact.birthDate[0];
	if (contact.birthDate[0] > 31 || contact.birthDate[0] < 1) {
		cout << "Вы ввели несуществующий день.";
		exit(0);
	}
	cout << "Месяц : ";
	in >> contact.birthDate[1];
	if (contact.birthDate[1] > 12 || contact.birthDate[1] < 1) {
		cout << "Вы ввели несуществующий месяц.";
		exit(0);
	}
	cout << "Год : ";
	in >> contact.birthDate[2];
	if (contact.birthDate[2] > 2022) {
		cout << "Вы ввели несуществующий год.";
		exit(0);
	}
	cout << "Введите Номер (последние 9 цифр) : ";
	in >> contact.telephoneNumber;
	if (contact.telephoneNumber > 999999999 || contact.telephoneNumber<100000000) {
		cout << "Вы ввели несуществующий номер.";
		exit(0);
	}
	cout << endl;
	return in;
}





int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	set<Contact> MyDairy;
	set<Contact>::iterator iter;
	cout << "Добавте свой первый контак в записную книжку.\n";
	Contact contact;
	cin >> contact;
	MyDairy.insert(contact);
	

	int n;
	
	string findSurname;
	int findNum;
	int findDate[3];
	bool program = true;
	do {
		cout << "Выберите операцию над вашей записной книгой...\n"
			<< "1 - Добавить контакт.\n"
			<< "2 - Найти / удалить контакт.\n"
			<< "3 - Вывести на экран.\n"
			<< "4 - Завершить работу.\n";

		cin >> n;
		switch (n)
		{
		case 1:
			cin >> contact;
			MyDairy.insert(contact);
			
			break;

		case 2:
			cout << "Выберите параметра для нахождения контакта : \n"
				<< "1 - по фамилии.\n"
				<< "2 - по дате.\n"
				<< "3 - по номеру.\n";
			cin >> n;
			switch (n)
			{
			case 1:
				cout << "Введите фамилию для поиска : ";
				cin >> findSurname;
				for (iter = MyDairy.begin(); iter != MyDairy.end(); iter++) {
					if (iter->surname == findSurname) {
						cout << *iter;
						cout << "1 - Продолжить.\n"
							<< "2 - Удалить\n";
						cin >> n;
						if (n == 1) {
							n = 0;
							break;
						}
						else if (n == 2) {
							MyDairy.erase(*iter);
							cout << "Контакт удален!\n";
							n = 0;
							break;
						}
						else {
							cout << "Вы ввели неправильное число!";
							n = 0;
							break;
						}
						
					}
				}
				if (n)
					cout << "Контакт не найден!\n";
				break;
			case 2:
				
				cout << "Введите дату рождения для поиска : \n";

				cout << "День : ";
				cin >> findDate[0];
				cout << "Месяц : ";
				cin >> findDate[1];
				cout << "Год : ";
				cin >> findDate[2];
				for (iter = MyDairy.begin(); iter != MyDairy.end(); iter++) {
					if (iter->birthDate[0] == findDate[0] && iter->birthDate[1] == findDate[1] && iter->birthDate[2] == findDate[2]) {
						cout << *iter;
						cout << "1 - Продолжить.\n"
							<< "2 - Удалить\n";
						cin >> n;
						if (n == 1) {
							n = 0;
							break;
						}
						else if (n == 2) {
							MyDairy.erase(*iter);
							cout << "Контакт удален!\n";
							n = 0;
							break;
						}
						else {
							cout << "Вы ввели неправильное число!";
							n = 0;
							break;
						}
						
					}
				}
				if (n)
					cout << "Контакт не найден!\n";
				break;
			case 3:
				case3:
				cout << "Введите номер для поиска : ";
				cin >> findNum;
				for (iter = MyDairy.begin(); iter != MyDairy.end(); iter++) {
					if (iter->telephoneNumber == findNum) {
						cout << *iter;
						cout << "1 - Продолжить.\n"
							<< "2 - Удалить\n";
						cin >> n;
						if (n == 1) {
							n = 0;
							break;
						}
						else if (n == 2) {
							MyDairy.erase(*iter);
							cout << "Контакт удален!\n";
							n = 0;
							break;
						}
						else {
							cout << "Вы ввели неправильное число!";
							n = 0;
							break;
						}
						
					}
				}
				if (n)
					cout << "Контакт не найден!\n";
				break;
			default:
				cout << "Вы ввели неправильное число.\n";
				break;
			}
			
			break;
		case 3:
			iter = MyDairy.begin();
			while (iter != MyDairy.end()) {
				cout << *iter;
				iter++;
			}
			break;
		case 4:
			program = false;
			cout << "Работа программы завершена!\n";
			break;
		default:
			cout << "Вы ввели неправильное число.\n";
			break;
		}

	} while (program);

}
