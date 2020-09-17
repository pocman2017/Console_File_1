#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

// Прототипы функций
void DataInitialization(); // Инициализация данных
void DataEntry(); // Ввод данных вручную
void DataReading(string filename); // Чтение данных из файла
void Print(); // Вывод данных на консоль
void DataChange(); // Изменение данных
bool DataCleaning(); // Очистка данных
void Copy(); // Копирование данных
int AmountOfData(); // Количество данных
void DeleteData(); // Удаление данных
void AddData(); // Добавление данных
void SaveData(string filename); // Сохранение данных
