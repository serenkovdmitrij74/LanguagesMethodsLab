//interpolation search
#include <iostream>
#include <vector>


using namespace std;


vector<int> create_vector() {
    int n;
    printf("Enter n: ");
    cin >> n;
    vector<int> vec(n);

    for (int i = 0; i < n; i++) {
        printf("Enter item %d:", i + 1);
        cin >> vec[i];
    }

    return vec;
}

int interpolation_search(vector<int> vec) {
    int s, a = 0, b = vec.size() - 1, m = 0;
    printf("Enter the number to search: ");
    cin >> s;

    while (s >= vec[a] && s <= vec[b]) {
        if (vec[m] == s)
            return m;
        if (vec[a] == vec[b])
            break;

        m = (s - vec[a]) * (b - a) / (vec[b] - vec[a]) + a;

        if (vec[m] < s)
            a = m + 1;
        else if (vec[m] > s)
            b = m - 1;
    }

    printf("Element %d is not in this array\n", s);
    return -1;
}


int main()
{
    printf("result=%d", interpolation_search(create_vector()));
}
