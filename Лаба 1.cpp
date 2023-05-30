#include <iostream>
#include <string>

using namespace std;

// Структура Trio с тремя полями
struct Trio {
    unsigned int first;
    unsigned int second;
    unsigned int third;

    // Метод инициализации
    void init(unsigned int a, unsigned int b, unsigned int c) {
        first = a;
        second = b;
        third = c;
    }

    // Метод чтения
    void read() {
        cin >> first >> second >> third;
    }

    // Метод вывода
    void display() {
        cout << first << "." << second << "." << third << endl;
    }
};

// Класс Date с полем типа Trio
class Date {
private:
    Trio date;

public:
    // Метод получения года
    unsigned int getYear() {
        return date.first;
    }

    // Метод изменения года
    void setYear(unsigned int year) {
        date.first = year;
    }

    // Метод получения месяца
    unsigned int getMonth() {
        return date.second;
    }

    // Метод изменения месяца
    void setMonth(unsigned int month) {
        date.second = month;
    }

    // Метод получения дня
    unsigned int getDay() {
        return date.third;
    }

    // Метод изменения дня
    void setDay(unsigned int day) {
        date.third = day;
    }

    // Метод инициализации строки
    void init(string str) {
        sscanf(str.c_str(), "%u.%u.%u", &date.first, &date.second, &date.third);
    }

    // Метод вычисления даты через заданное количество дней
    void addDays(unsigned int days) {
        int year = date.first;
        int month = date.second;
        int day = date.third;

        // Добавляем заданное количество дней
        day += days;

        // Проверяем, сколько дней в месяце
        int daysInMonth;
        if (month == 2) {
            if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
                daysInMonth = 29;
            }
            else {
                daysInMonth = 28;
            }
        }
        else if (month == 4 || month == 6 || month == 9 || month == 11) {
            daysInMonth = 30;
        }
        else {
            daysInMonth = 31;
        }

        // Проверяем, нужно ли перейти на следующий месяц или год
        while (day > daysInMonth) {
            day -= daysInMonth;
            month++;
            if (month > 12) {
                month = 1;
                year++;
            }
            if (month == 2) {
                if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
                    daysInMonth = 29;
                }
                else {
                    daysInMonth = 28;
                }
            }
            else if (month == 4 || month == 6 || month == 9 || month == 11) {
                daysInMonth = 30;
            }
            else {
                daysInMonth = 31;
            }
        }

        // Записываем новую дату
        date.first = year;
        date.second = month;
        date.third = day;
    }

    // Метод вывода даты
    void display() {
        date.display();
    }
};

int main() {
    Date d;

    // Пример инициализации даты
    d.init("2022.01.01");

    // Пример изменения даты
    d.addDays(365);

    // Пример вывода даты
    d.display();

    return 0;
}