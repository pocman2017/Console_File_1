#define _CRT_SECURE_NO_WARNINGS
#include "Functions.h"

void DataInitialization() // Инициализация данных
{
	// Создадим временный файл, в котором будет храниться временная информация (Буфер)
	ofstream _buf("Buffer.txt");
	
	if (!_buf)
		cout << "Ошибка создания буферного файла!" << endl;
	_buf.close();
}
void DataEntry() // Ввод данных вручную
{
	// Временные переменные
	string _surname;
	int _phoneNum;
	string _city;
	int n;

	cout << "Введите количество данных: ";
	cin >> n;
	// Открываем буферный файл и записываем в него данные
	ofstream record("Buffer.txt", ios::app);

	if (record)
	{
		record << n << endl;

		for (int i = 0; i < n; i++)
		{
			cout << "Введите данные № 1 (Фамилия): ";
			cin >> _surname;

			cout << "Введите данные № 2 (Номер телефона): ";
			cin >> _phoneNum;

			cout << "Введите данные № 3 (Город):";
			cin >> _city;

			record << _surname << endl;
			record << _phoneNum << endl;
			if (i < n - 1)
				record << _city << endl;
			else
				record << _city;
			cout << "-------------------" << endl;
		}
	}
	else
		cout << "Ошибка открытия файла!" << endl;
	record.close();
}
void DataReading(string filename) // Чтение данных из файла
{
	ifstream reading(filename);
	ofstream record("Buffer.txt", ios::out);

	if (reading)
	{
		if (record)
		{
			// Временные переменные
			string _surname;
			int _phoneNum;
			string _city;
			int n;
			// Считываем данные из файла
			reading >> n;
			record << n << endl;

			for (int i = 0; i < n; i++)
			{
				reading >> _surname;
				reading >> _phoneNum;
				reading >> _city;

				record << _surname << endl;
				record << _phoneNum << endl;
				if (i < n - 1)
					record << _city << endl;
				else
					record << _city;
			}
			cout << "Данные считаны!" << endl;
		}
		else
			cout << "Ошибка открытия файла!" << endl;
	}
	else
		cout << "Ошибка открытия файла!" << endl;
	// Закрываем файл
	reading.close();
	record.close();
}
void Print() // Вывод данных на консоль
{
	ifstream reading("Buffer.txt");
	if (reading)
	{
		string _surname;
		int _phoneNum;
		string _city;
		int n;

		reading >> n;
		cout << "Количество данных: " << n << endl << endl;
		for (int i = 0; i < n; i++)
		{
			cout << "Данные об № " << i + 1 << endl;

			reading >> _surname;
			cout << "Данные № 1 (Фамилия): " << _surname << endl;

			reading >> _phoneNum;
			cout << "Данные № 2 (Номер телефона): " << _phoneNum << endl;

			reading >> _city;
			cout << "Данные № 3 (Город): " << _city << endl;

			cout << "-----------------------------" << endl;
		}
	}
	else
		cout << "Ошибка открытия файла!" << endl;

	reading.close();
}
void DataChange() // Изменение данных
{
	/* Сохраним ещё раз данные
	   очистим буфер и снова начнем записывать данные в него
	   дойдем до необходимого и изменим ешо данные	
	*/
	Copy();

	ifstream reading("Buffer.txt");
	ofstream record("Buffer.txt", ios::out);

	if (reading)
	{
		if (record)
		{
			string _surname; // Временные переменные
			int _phoneNum;
			string _city;
			int n, _n;
			// Считываем из буферного файла в новый
			reading >> n;

			cout << "Выберите номер изменяемого элемента (от 1 до " << n << "): ";
			cin >> _n;
			_n--;

			system("cls");

			record << n << endl;

			if (n >= 0 && _n < n)
			{
				for (int i = 0; i < n; i++)
				{
					if (i != _n)
					{
						reading >> _surname;
						record << _surname << endl;

						reading >> _phoneNum;
						record << _phoneNum << endl;

						reading >> _city;
						if (i < n - 1)
							record << _city << endl;
						else
							record << _city;
					}
					else
					{
						cout << "Введите данные № 1 (Фамилия):";
						cin >> _surname;

						cout << "Введите данные № 2 (Номер телефона): ";
						cin >> _phoneNum;

						cout << "Введите данные № 3 (Город): ";
						cin >> _city;

						record << _surname << endl;
						record << _phoneNum << endl;
						if (i < n - 1)
							record << _city << endl;
						else
							record << _city;

						reading >> _surname;
						reading >> _phoneNum;
						reading >> _city;
					}
				}
				cout << "Данные изменены!" << endl;
			}
			else
				cout << "Номер введен неверно!" << endl;
		}
		else
			cout << "Ошибка открытия файла!" << endl;
	}
	else
		cout << "Ошибка открытия буферного файла!" << endl;

	record.close();
	reading.close();

	remove("Buffer.txt");
}
bool DataCleaning() // Очистка данных
{
	bool clear = false;
	// Открытие файла
	fstream _buf("Buffer.txt", ios::out);

	// Очищаем
	_buf.clear();

	// Проверяем что файл чистый
	if (_buf.peek() == EOF)
		clear = true;
	else
		clear = false;
	_buf.close();

	return clear;
}
void Copy() // Копирование данных в новый файл
{
	ifstream reading("Buffer.txt");
	ofstream record("Buffer.txt", ios::out);

	if (reading)
	{
		if (record)
		{
			string _surname; // Временные переменные
			int _phoneNum;
			string _city;
			int n;
			// Считываем из буферного файла в новый
			reading >> n;
			record << n << endl;

			for (int i = 0; i < n; i++)
			{
				reading >> _surname;
				record << _surname << endl;

				reading >> _phoneNum;
				record << _phoneNum << endl;

				reading >> _city;
				if (i < n - 1)
					record << _city << endl;
				else
					record << _city;
			}
		}
		else
			cout << "Ошибка открытия файла!" << endl;
	}
	else
		cout << "Ошибка открытия буферного файла!" << endl;
	record.close();
	reading.close();
}
int AmountOfData() // Выводит количество количество из данных
{
	ifstream _buf("Buffer.txt");
	int n;

	if (_buf)
	{
		_buf >> n;
	}
	else
		cout << "Ошибка откратия буферного файла!" << endl;

	_buf.close();

	return n;
}
void DeleteData() // Удаление данных
{
	// Запоминаем данные
	// Перезаписываем в исходный буфер
	// кроме удаляемого
	Copy();

	ifstream reading("Buffer_.txt");
	ofstream record("Buffer.txt", ios::out);

	if (reading)
	{
		if (record)
		{
			string _surname; // Временные переменные
			int _phoneNum;
			string _city;
			int n, _n;
			// Считываем из буферного файла в новый
			reading >> n;
			int b = n - 1;

			cout << "Выберете номер изменяемого элемента (от 1 до " << n << "): ";
			cin >> _n;
			_n--;

			system("cls");

			record << b << endl;
			if (_n >= 0 && _n < n)
			{
				for (int i = 0; i < n; i++)
				{
					if (i != _n)
					{
						reading >> _surname;
						record << _surname << endl;

						reading >> _phoneNum;
						record << _phoneNum << endl;

						reading >> _city;
						if (i < n - 1)
							record << _city << endl;
						else
							record << _city;
					}
					else
					{
						reading >> _surname;
						reading >> _phoneNum;
						reading >> _city;
					}
				}
				cout << "Данные удалены!" << endl;
			}
			else
				cout << "Номер введен неверно!" << endl;
		}
		else
			cout << "Ошибка открытия файла!" << endl;
	}
	else
		cout << "Ошибка открытия буферного файла!" << endl;
	record.close();
	reading.close();

	remove("Buffer.txt");
}
void AddData() // Добавление данных
{
	string _surname;
	int _phoneNum;
	string _city;
	int n = AmountOfData() + 1;
	// Открываем буферный файл
	ofstream record("Buffer.txt", ios::app);
	ofstream record_("Buffer.txt", ios::out | ios::in);

	if (record_)
	{
		record_ << n << endl;
	}
	else
		cout << "Ошибка открытия буферного файла!" << endl;

	if (record)
	{
		record << endl;

		cout << "Введите данные № 1 (Фамилия): ";
		cin >> _surname;

		cout << "Введите данные № 2 (Номер телефона): ";
		cin >> _phoneNum;

		cout << "Введите данные № 3 (Город): ";
		cin >> _city;

		record << _surname << endl;
		record << _phoneNum << endl;
		record << _city;
	}
	else
		cout << "Ошибка открытия файла!): ";

	record.close();
	record_.close();
}
void SaveData(string filename) // Сохранение данных
{
	ifstream reading("Buffer.txt");
	ofstream record(filename, ios::out);

	if (reading)
	{
		if (record)
		{
			string _surname; // Временные переменные
			int _phoneNum;
			string _city;
			int n;

			reading >> n;
			record << n << endl;

			for (int i = 0; i < n; i++)
			{
				reading >> _surname;
				record << _surname << endl;

				reading >> _phoneNum;
				record << _phoneNum << endl;

				reading >> _city;
				if (i < n - 1)
					record << _city << endl;
				else
					record << _city;
			}
			cout << "Данные сохранены в файле " << filename << endl;
		}
		cout << "Ошибка открытия буферного файла!" << endl;
	}
	else
		cout << "Ошибка открытия файла!" << endl;

	record.close();
	reading.close();
}
