#include <iostream>
#include <stdio.h>
#include <locale>

using namespace std;

struct Data
{
	char tran[15];
	char num[8];
	float km;
	int min;
	char date[11];
} Data[3];

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

void prints(int i)
{
	cout << "|"; cout.fill(' '); cout.width(14); cout << left << Data[i].tran;
	cout << "|"; cout.width(7); cout << left << Data[i].num;
	cout << "|"; cout.width(27); cout << left << Data[i].km;
	cout << "|"; cout.width(20); cout << left << Data[i].min;
	cout << "|"; cout.width(10); cout << left << Data[i].date << "|" << endl;
	draw_mline();
}
int main()
{
	setlocale(LC_ALL, "Russian");

	Data[0] = { "Тр.", "12", 27.55, 75, "11.04.2023" };
	Data[1] = { "Т-с", "17", 13.6, 57, "12.04.2023" };
	Data[2] = { "А", "12а", 57.3, 117, "11.04.2023" };

	header();

	categories();

	prints(0);
	prints(1);
	prints(2);

	note();

}

