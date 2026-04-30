#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class AEROFLOT
{
private:
    string dest;
    int flightNum;
    string planeType;
public:
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

    static bool AeroSort(AEROFLOT a, AEROFLOT b) {
        return (a.GetDestination()<b.GetDestination());
    }
};


int main()
{
    
    AEROFLOT flights[7];
    int ef = 0;
    string a = "ABC", b="BCD";

    cout << (a > b)<< endl;


    cout << ('A'<'B');

    while (ef < 7){
        string dest;
        int num;
        string type;
        cout << "Введите пункт назначения: \n";
        cin >> dest;
        cout << "Введите номер рейса: \n";
        cin >> num;
        cout << "Введите тип самолета: \n";
        cin >> type;

        flights[ef] = AEROFLOT(dest, num, type);
        ef += 1;
    }

    

    sort(flights, flights + 7, AEROFLOT.AeroSort);
}
