#include <iostream>
#include <vector>
using namespace std;

bool isArithmetic(const vector<double>& arr) {
    if (arr.size() < 2) return false;

    double diff = arr[1] - arr[0];
    for (size_t i = 2; i < arr.size(); ++i) {
        if ((arr[i] - arr[i - 1]) != diff) {
            return false;
        }
    }
    return true;
}

bool isGeometric(const vector<double>& arr) {
    if (arr.size() < 2) return false;

    if (arr[0] == 0) return false; // To prevent division by zero
    double ratio = arr[1] / arr[0];
    for (size_t i = 2; i < arr.size(); ++i) {
        if (arr[i - 1] == 0 || (arr[i] / arr[i - 1]) != ratio) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<double> arr(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    if (isArithmetic(arr)) {
        cout << "The series is Arithmetic (Symmetric)." << endl;
    } else if (isGeometric(arr)) {
        cout << "The series is Geometric (Doubles)." << endl;
    } else {
        cout << "The series is neither Arithmetic nor Geometric." << endl;
    }

    return 0;
}
