#include <iostream>

using namespace std;

class Complex {
private:
    double r;
    double i;
public:
    Complex() {
        r = 0;
        i = 0;
    }

    Complex(double r, double i) {
        this->r = r;
        this->i = i;
    }

    double GetReal() const{
        return r;
    }

    double GetImage() const{
        return i;
    }

    void print() {
        cout << r;
        if (i == 1)
            cout << " +" << "i";
        else if (i > 0)
            cout << " +" << i << "i";
        if (i == -1)
            cout << " -" << "i";
        else if (i < 0)
            cout << " " << i << "i";
    }

    Complex operator+(const Complex& other) const {
        return Complex(r + other.GetReal(), i + other.GetImage());
    }

    Complex operator-(const Complex& other) const {
        return Complex(r - other.GetReal(), i - other.GetImage());
    }

    Complex operator*(const Complex& other) const {
        return Complex((r * other.GetReal()) - (i * other.GetImage()), (r * other.GetImage()) + (i * other.GetReal()));
    }
};

Complex EnterComplex(string str) {
    double r, i;
    cout << "Введите "<< str<<  " число в формате a +b ";
    cin >> r>>i;
    return Complex(r, i);
}


void Menu() {
    short change;
    Complex firstNum = EnterComplex("первое");
    Complex secondNum = EnterComplex("второе");

    cout << "Выберите операцию:\n1-Сложение\n2-Вычитание\n3-Умножение";
    cin >> change;

    switch (change) {
        case 1:
            (firstNum + secondNum).print();
            break;
        case 2:
            (firstNum - secondNum).print();
            break;
        case 3:
            (firstNum * secondNum).print();
            break;
        default:
            cout << "Данная операция не существует!";
            break;
    }
}


int main()
{
    setlocale(LC_ALL, "Russian");

    Menu();
}
