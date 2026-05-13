#include <iostream>
#include <string>
#include <algorithm>
#include <clocale>
#include <typeinfo>

using namespace std;

class AEROFLOT
{
private:
    string dest;
    int flightNum;
    string planeType;
public:
    friend ostream& operator<<(ostream& os, const AEROFLOT& f);
    friend istream& operator>>(istream& is, AEROFLOT& f);

    AEROFLOT() {}

    AEROFLOT(string dest, int flightNum, string planeType) {
        SetDestination(dest);
        SetFlightNumber(flightNum);
        SetPlaneType(planeType);
    }

    void SetDestination(string dest) {
        this->dest = dest;
    }
    
    void SetFlightNumber(int flightNum) {
        this->flightNum = flightNum;
    }

    void SetPlaneType(string planeType) {
        this->planeType = planeType;
    }

    string GetDestination() {
        return dest;
    }

    int GetFlightNumber() {
        return flightNum;
    }

    string GetPlaneType() {
        return planeType;
    }

    void print() {
        cout << "Номер рейса: ", flightNum, "\nПункт назначения: ", dest, "\nТип самолета: ", planeType, "\n";
    }

    bool operator<(const AEROFLOT& other) const {
        return this->dest < other.dest;
    }
};

ostream& operator<<(ostream& os, const AEROFLOT& f) {
    os << "Пункт назначения: " << f.dest << ", Номер рейса: " << f.flightNum
        << ", Тип самолета: " << f.planeType;
    return os;
}

istream& operator>>(istream& is, AEROFLOT& f) {
    cout << "Введите пункт назначения: ";
    is >> f.dest;

    cout << "Введите номер рейса: ";
    while (!(is >> f.flightNum)) {
        is.clear();
        is.ignore(1000, '\n');
        cout << "Ошибка! Введите корректное число для номера рейса: ";
    }

    cout << "Введите тип самолета: ";
    is >> f.planeType;
    return is;
}


int main() {
    setlocale(LC_ALL, "Russian");

    int len = 2;
    AEROFLOT* flights = new AEROFLOT[len];

    for (int i = 0; i < len; ++i) {
        cout << "Ресй " << i + 1 << ":\n";
        cin >> flights[i];
    }

    sort(flights, flights + len);

    string searchType;
    cout << "\nВведите тип самолет: ";
    cin >> searchType;

    bool found = false;
    for (int i = 0; i < len; ++i) {
        if (flights[i].GetPlaneType() == searchType) {
            cout << "Пункт: " << flights[i].GetDestination() << " Рейс: " << flights[i].GetFlightNumber() << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Рейсов нету" << endl;
    }

    return 0;
}
