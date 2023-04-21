#include <iostream>
#include <stdio.h>
#include <locale>

using namespace std;
float min_distance; float max_distance;
int min_time; int max_time;


struct Date
{
	unsigned short day;
	unsigned short month;
	unsigned short year;
};

struct Record
{
	char type[15];
	char route[8];
	float distance;
	int time;
	struct Date date;
};

void draw_line()
{
	cout << "+"; cout.width(83); cout.fill('-'); cout << right << '+' << endl;
}

void draw_mline()
{
	cout.fill('-'); cout << left << "|";
	cout.width(15); cout << right << "+";
	cout.width(8); cout << right << "+";
	cout.width(28); cout << right << "+";
	cout.width(21); cout << right << "+";
	cout.width(11); cout << right << "|" << endl;
}

void header()
{
	draw_line();
	cout.fill(' ');
	cout.width(83); cout << left << "|Ведомость общественного транспорта"; cout << '|' << endl;
	draw_mline();
}
void categories()
{
	cout.fill(' ');
	cout.width(15); cout << "|Вид транспорта";
	cout.width(8); cout << "|Маршрут";
	cout.width(28); cout << "|Протяжённость маршрута (км)";
	cout.width(21); cout << "|Время в дороге (мин)";
	cout.width(11); cout << left << "|Дата"; cout << right << '|' << endl;
	draw_mline();
}

void note()
{
	cout.fill(' ');
	cout.width(83); cout << left << "|Примечание: Тр. - трамвай, Т-с - троллейбус, А - автобус"; cout << '|' << endl;
	draw_line();
}

void print_date(unsigned short day, unsigned short month, unsigned short year)
{
	if (day > 9) {
		cout << day;
	}
	else {
		cout << "0" << day;
	}
	cout << ".";
	if (month > 9) {
		cout << month;
	}
	else {
		cout << "0" << month;
	}
	cout << ".";
	cout << year;
}


void prints(struct Record* record)
{
	for (int i = 0; i < 3; i++)
	{
		cout << "|"; cout.fill(' '); cout.width(14); cout << left << record[i].type;
		cout << "|"; cout.width(7); cout << left << record[i].route;
		cout << "|"; cout.width(27); cout << left << record[i].distance;
		cout << "|"; cout.width(20); cout << left << record[i].time;
		cout << "|"; print_date(record[i].date.day, record[i].date.month, record[i].date.year);
		cout << "|" << endl;
		draw_mline();
	}
}

void replace(Record* record)
{
	int pos_min_distance;
	int pos_max_distance;
	int pos_min_time;
	int pos_max_time;

	min_distance = record[0].distance;
	for (int i = 1; i < 3; i++)
	{
		if (min_distance > record[i].distance)
		{
			min_distance = record[i].distance;
			pos_min_distance = i;
		}
	}

	max_distance = record[0].distance;
	for (int i = 1; i < 3; i++)
	{
		if (max_distance < record[i].distance)
		{
			max_distance = record[i].distance;
			pos_max_distance = i;
		}
	}

	min_time = record[0].time;
	for (int i = 1; i < 3; i++)
	{
		if (min_time > record[i].time)
		{
			min_time = record[i].time;
			pos_min_time = i;
		}
	}

	max_time = record[0].time;
	for (int i = 1; i < 3; i++)
	{
		if (max_time < record[i].time)
		{
			max_time = record[i].time;
			pos_max_time = i;
		}
	}

	record[pos_min_distance].distance = max_distance;
	record[pos_max_distance].distance = min_distance;
	record[pos_min_time].time = max_time;
	record[pos_max_time].time = min_time;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	struct Record record[3];

	cout << "Изначальная таблица из практики №0:" << endl;
	cout << endl;

	record[0] = { "Тр.", "12", 27.55, 75, {11,4,2023} };
	record[1] = { "Т-с", "17", 13.6, 57, {12,4,2023} };
	record[2] = { "А", "12а", 57.3, 117, {11,5,2023} };

	header();

	categories();

	prints(record);

	note();

	cout << endl;

	cout << "Таблица с заменёнными местами значениями:" << endl;
	cout << endl;

	replace(record);

	header();

	categories();

	prints(record);

	note();
}
