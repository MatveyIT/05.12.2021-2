#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;
void fill_random(int** mas, int n, int m) {
	srand(time(0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			mas[i][j] = rand() % 21 - 10;
		}
	}
}
void print_matrix(int** mas, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << setw(4) << mas[i][j];
		}
		cout << endl;
	}
}
int count_positiv(int** mas, int n, int m) {
	int k = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mas[i][j] > 0) k++;
		}

	}
	return k;
}
int count_chot(int** mas, int n, int m) {
	int k = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mas[i][j] % 2 == 0) k++;
		}

	}
	return k;
}
double amean(int** mas, int n, int m) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
			sum += mas[i][i];
	}
	return static_cast<double>(sum) / n;
}
int sum_amean(int** mas, int n, int m) {
	int s = 0;
	for (int i = 0; i < n; i++) {
		s += mas[i][i];

	}
	return s;
}
long long int fact(int k) {
	long long int f = 1;
	for (int i = 1; i <= k; i++) {
		f *= i;
	}
	return f;

}
void reverse_row(int** mas, int k, int m) {
	int s = m / 2;
	for (int j = 0; j< m/2; j++) {
		swap(mas[k][j], mas[k][m - 1 - j]);
	}
}
int main() {
	setlocale(LC_ALL, "rus");
	 int n = 5;
	 int m = 5;
	int** mas;
	mas = new int* [n];
	for (int i = 0; i < n; i++) {
		mas[i] = new int[m];
	}
	fill_random(mas, n, m);
	print_matrix(mas, n, m);
	cout << "Количество положительных" << count_positiv(mas, n, m) << endl;
	cout << "Количество чотных" << count_chot(mas, n, m) << endl;
	cout << "Среднее арифм главной" << amean(mas, n, m) << endl;
	cout << "Факториал суммы главной диагонали" << fact(sum_main(mas, n, m)) << endl;
	reverse_row(mas, 0, m);
	print_matrix(mas, n, m);
}
