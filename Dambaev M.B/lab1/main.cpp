#include <iostream>
#include <string>

using namespace std;
int main()
{
    int i = 0, s = 0, sum[80];

    setlocale(LC_ALL, "Russian");

    cout << "Введите строку: ";

    string str, str_1[80];
    getline(cin, str);
    str += " ";

    while (i < str.length() - 1) {
        while (str[i] != ' ' && str[i] != '.' && str[i] != ',' && str[i] != '!' && str[i] != '?') {
            str_1[s] += str[i];
            i++;
        }
        s++;
        while (str[i] == ' ' || str[i] == '.' || str[i] == ',' || str[i] == '!' || str[i] == '?') {
            str_1[s] += str[i];
            i++;
        }
        s++;
    }
    for (int i = 0; i <= s; i++) {
        sum[i] = -1;
        if (str_1[i][0] != ' ' && str_1[i][0] != ',' && str_1[i][0] != '.' && str_1[i][0] != '!' && str_1[i][0] != '?') {
            for (int k = 0; k < str_1[i].length(); k++) {
                sum[i] += str_1[i][k];
            }
        }
    }
    string c1;
    int c2;
    for (int i = 0; i <= s; i++) {
        if (sum[i] != -1) {
            for (int k = i + 1; k <= s; k++) {
                if (sum[k] < sum[i] && sum[k] != -1 && sum[i] != -1) {
                    c1 = str_1[i];
                    str_1[i] = str_1[k];
                    str_1[k] = c1;
                    c2 = sum[i];
                    sum[i] = sum[k];
                    sum[k] = c2;
                }
            }
        }
    }
    for (int i = 0; i <= s; i++) {
        cout << str_1[i];
    }
}
