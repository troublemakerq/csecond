#include <iostream>

using namespace std;

//Необходимые структуры;
struct NAME
{
	char surname[56];
	char name[32];
	char patronomyc[56];
};

struct Birthday
{
	int date;
	int month;
	int year;
	bool isCorrect();
};

struct Adress
{
	int index;
	char country[32];
	char region[32];
	char city[32];
	char street[32];
	int home;
	int apartment;
};

struct School_child
{
	char sex[16];
	char nationality[32];
	float height;
	float weight;
	NAME fio;
	Birthday day;
	Adress house;
	char school[32];
	int Class;
	long long int phone;
	int count;
};

//функция проверки ввода даты рождения учитывая высокостный год;
bool Birthday::isCorrect()
{
	bool result = false;
	switch (month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
	{
		if ((date <= 31) && (date > 0))
			result = true;
		break;
	}

	case 4:
	case 6:
	case 9:
	case 11:
	{
		if ((date <= 30) && (date > 0))
			result = true;
		break;
	}

	case 2:
	{
		if (year % 4 != 0)
		{
			if ((date <= 28) && (date > 0))
				result = true;
		}
		else
			if (year % 400 == 0)
			{
				if ((date <= 29) && (date > 0))
					result = true;
			}
			else
				if ((year % 100 == 0) && (year % 400 != 0))
				{
					if ((date == 28) && (date > 0))
						result = true;
				}
				else
					if ((year % 4 == 0) && (year % 100 != 0))
						if ((date <= 29) && (date > 0))
							result = true;
		break;
	}

	default:
		result = false;
	}

	return result;
}

void memory(School_child*& arr, int& size) //создаем новый массив на 1 элемент больше и перезаписываем в него элементы старого массива;
{
	School_child* new_array = new School_child[size + 1];

	for (int i = 0; i < size; i++)
	{
		new_array[i] = arr[i];
	}

	size++;

	delete[] arr;

	arr = new_array;
}

void sort(School_child* arr, int size) //диалог с пользователем - спрашиваем хочет ли он отсортировать массив;
{
	int k;

	cout << "Хотите отсортировать массив? Возможна сортировка по номеру класса\n" << endl;
	cout << "Введите 1 если да или другое исло если нет: ";
	cin >> k;

	cout << endl;

	if (k == 1)
	{
		for (int i = 0; i < size; i++)
		{
			for (int i = 0; i < size - 1; i++)
			{
				if (arr[i].Class > arr[i + 1].Class)
				{
					School_child temp = arr[i];
					arr[i] = arr[i + 1];
					arr[i + 1] = temp;
				}
			}
		}

		cout << "Успешно отсортировано по номеру класса!" << endl << endl;
	}

	else
	{
		cout << "Вы решили не сортировать." << endl << endl;
	}
}

void search(School_child* arr, int size)
{
	int s, m, number, count = 0;
	string surname;

	cout << "Хотите найти нужного вам ученика? Возможен поиск по фамилии\n";
	cout << "Введите 1 если да или другое число если нет: ";
	cin >> s;
	cout << endl;

	if (s == 1)
	{
		cout << "Введите фамилию: ";
		cin >> surname;
		cout << endl;

		for (int i = 0; i < size; i++)
		{
			if (surname == arr[i].fio.surname)
			{
				cout << "ФИО: " << arr[i].fio.surname << " " << arr[i].fio.name << " " << arr[i].fio.patronomyc << "\n";
				cout << "Пол: " << arr[i].sex << ", Национальность: " << arr[i].nationality << ", Рост: " << arr[i].height << ", Вес: " << arr[i].weight << ", Номер телефона: " << arr[i].phone << "\n";
				cout << "Индекс дома: " << arr[i].house.index << ", Страна: " << arr[i].house.country << ", Регион:" << arr[i].house.region << ", Город: " << arr[i].house.city << "\n";
				cout << "Улица: " << arr[i].house.street << ", Дом: " << arr[i].house.home << ", Квартира: " << arr[i].house.apartment << "\n";
				cout << "Дата Рождения: " << arr[i].day.date << " " << arr[i].day.month << " " << arr[i].day.year << "\n";
				cout << "Школа: " << arr[i].school << ", Класс: " << arr[i].Class << endl << endl;
				count++;
			}
		}

		if (count == 0)
		{
			cout << "Нет ученика с данной фамилией" << endl;
		}

		cout << endl;
		cout << "Продолжить поиск? 1 если да, другое число если нет: ";
		cin >> m;
		cout << endl;

		if (m == 1)
		{
			search(arr, size);
			count = 0;
		}

		else
		{
			count = 0;
		}

	}

	else
	{
		cout << "Вы решили не искать." << endl;
	}

}

void massiv(School_child* arr, int size) //выводим информацию об учениках;
{
	cout << endl;

	for (int i = 0; i < size; i++)
	{
		cout << "ФИО: " << arr[i].fio.surname << " " << arr[i].fio.name << " " << arr[i].fio.patronomyc << "\n";
		cout << "Пол: " << arr[i].sex << ", Национальность: " << arr[i].nationality << ", Рост: " << arr[i].height << ", Вес: " << arr[i].weight << ", Номер телефона: " << arr[i].phone << "\n";
		cout << "Индекс дома: " << arr[i].house.index << ", Страна: " << arr[i].house.country << ", Регион:" << arr[i].house.region << ", Город: " << arr[i].house.city << "\n";
		cout << "Улица: " << arr[i].house.street << ", Дом: " << arr[i].house.home << ", Квартира: " << arr[i].house.apartment << "\n";
		cout << "Дата Рождения: " << arr[i].day.date << " " << arr[i].day.month << " " << arr[i].day.year << "\n";
		cout << "Школа: " << arr[i].school << ", Класс: " << arr[i].Class << endl << endl;
	}
}

int main()
{
	setlocale(LC_ALL, "RU");

	School_child* arr;
	int size;

	do
	{
		cout << "Введите количество учеников, информацию о которых вы будете вводить: ";
		cin >> size;
	} while (size < 1);

	arr = new School_child[size];

	//вводим информацию об учениках;
	for (int i = 0; i < size; i++)
	{
		cout << "Введите фамилию ученика под номером " << i + 1 << ": ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(arr[i].fio.surname, 56);
		cout << endl;

		cout << "Введите имя: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(arr[i].fio.name, 32);
		cout << endl;

		cout << "Введите отчество: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(arr[i].fio.patronomyc, 56);
		cout << endl;

		cout << "Введите пол: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(arr[i].sex, 16);
		cout << endl;

		cout << "Введите национальность: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(arr[i].nationality, 32);
		cout << endl;

		do
		{
			do
			{
				cout << "Введите рост в метрах: ";
				cin >> arr[i].height;
				cout << endl;
			} while (arr[i].height > 2.5);
		} while (arr[i].height < 0.3);

		do
		{
			do
			{
				cout << "Введите вес в килограммах: ";
				cin >> arr[i].weight;
				cout << endl;
			} while (arr[i].weight < 0);
		} while (arr[i].weight > 150);

		cout << "Введите номер телефона: ";
		cin >> arr[i].phone;
		cout << endl;

		do
		{
			cout << "Введите День Рождения: ";
			cin >> arr[i].day.date;
			cout << endl;
			cout << "Месяц: ";
			cin >> arr[i].day.month;
			cout << endl;
			cout << "Год: ";
			cin >> arr[i].day.year;
			cout << endl;
		} while (!arr[i].day.isCorrect());

		do
		{
			do
			{
				cout << "Введите индекс дома/квартиры: ";
				cin.ignore(cin.rdbuf()->in_avail());
				cin >> arr[i].house.index;
				cout << endl;
			} while (arr[i].house.index >= 100000);
		} while (arr[i].house.index < 10000);

		cout << "Введите страну: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(arr[i].house.country, 32);
		cout << endl;

		cout << "Введите регион: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(arr[i].house.region, 32);
		cout << endl;

		cout << "Введите город: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(arr[i].house.city, 32);
		cout << endl;

		cout << "Введите улицу: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(arr[i].house.street, 32);
		cout << endl;

		cout << "Введите номер дома: ";
		cin >> arr[i].house.home;
		cout << endl;

		cout << "Введите номер квартиры: ";
		cin >> arr[i].house.apartment;
		cout << endl;

		cout << "Введите номер школы: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(arr[i].school, 32);
		cout << endl;

		do
		{
			cout << "Введите класс: ";
			cin >> arr[i].Class;
			cout << endl;
		} while (arr[i].Class > 12);

		if (i == size - 1)
		{
			arr[i].count = 0;

			cout << "Хотите продолжить ввод учеников? Введите 1 если да или другое число если нет: ";
			cin >> arr[i].count;
			cout << endl;

			if (arr[i].count == 1)
			{
				//функция для выделения памяти если пользовать продолжит ввод;
				memory(arr, size);
			}
		}

	}

	if (size > 1)
	{
		//функция сортировки;
		sort(arr, size);

		//функция поиска по элементу;
		search(arr, size);
	}

	//если ученик всего 1 то поиск и сортировка невозможны;
	else
	{
		cout << "Так как ученик всего 1 функции поиска и сортировки недоступны" << endl << endl;
	}

	cout << "Информация об учениках: " << endl;

	//функция вывода информации об учениках;
	massiv(arr, size);
}