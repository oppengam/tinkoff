/* На физкультуре происходит разбиение по двум командам. Ребята выстроены в шеренгу, у каждого из них есть свой рост a[i].
 * Разбиение по командам произойдет по принципу «четный-нечетный» — все школьники с четным ростом отправляются в одну команду, а нечетные — в другую.
 * В отличие от привычного урока, ребята не выстроились по росту.
 * Вместо привычного порядка они встали случайно.
 * Теперь физрук Яша смотрит на шеренгу и думает — может ли ровно одна
 * пара учеников поменяться местами так, чтобы команды оказались такими же, как и по принци-пу «первый-второй». 
 * Иначе говоря, он хочет получить такой порядок, при котором все ученики с четным ростом стоят на четных позициях, а с нечетным — на нечетных.
 * Помогите Яше найти нужную замену.
 *
 * 2 <= n <= 1000
 * 1 <= a[i] <= 10^9 */
#include <iostream>
#include <algorithm>

using namespace std;

bool check(long long a[], int n);
void even_odd(long long a[], int n, int indeces[]);

int main() {
    int n;

    cin >> n;

    long long a[n + 1];

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int indeces[] = {-1, -1};

    even_odd(a, n, indeces);

    cout << indeces[0] << ' ' << indeces[1];
}

bool check(long long a[], int n) {
    bool correct = true;

    for (int i = 1; i <= n && correct; i++) {
        if ((i % 2 == 0 && a[i] % 2 != 0) || (i % 2 != 0 && a[i] % 2 == 0)) {
            correct = false;
        }
    }

    return correct;
}

void even_odd(long long a[], int n, int indeces[]) {
    if (!check(a, n)) {
        int odd_ind = 1;
        int even_ind = 2;
        
        while (odd_ind <= n && a[odd_ind] % 2 != 0) {
            odd_ind += 2;
        }

        while (even_ind <= n && a[even_ind] % 2 == 0) {
            even_ind += 2;
        }

        if (odd_ind <= n && even_ind <= n) {
            swap(a[odd_ind], a[even_ind]);
        }

        if (check(a, n)) {
            indeces[0] = odd_ind;
            indeces[1] = even_ind;
        }
    } 
}
