//ex6
#include <iostream>
#include <vector>


using namespace std;


void print_posl(vector<int> posl) {
    cout << "\n";
    for (int i = 0; i < posl.size(); i++) {
        cout << posl[i];
    }
}


vector<int> create_posl(int a, int b) {
    vector<int> posl(b-a);
    for (int i = 0; i < posl.size(); i++) {
        posl[i] = a+i+1;
    }

    return posl;
}


void inc_to_max(int e, vector<int> posl, vector<int> max_posl) {
    for (int i = posl[e]; posl[e] < max_posl[e]; i++) {
        posl[e] = i;
        if (e + 1 < posl.size()) {
            posl[e+1] = i+1;
            inc_to_max(e + 1, posl, max_posl);
        }
        else {
            print_posl(posl);
        }
    }
}


int main()
{
    int n, k;
    cout << "Write n:";
    cin >> n;
    cout << "Write k:";
    cin >> k;
    vector<int> posl = create_posl(0, k),  max_posl = create_posl(n - k, n);

    inc_to_max(0, posl, max_posl);
}
