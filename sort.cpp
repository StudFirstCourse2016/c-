#include <iostream>

#include <iomanip>

#include <ctime>

using namespace std;

void give_memory(int * & A, int size);

void delete_memory(int * & A);

void quickSort(int *A, int begin, int end);

void initArray(int *A, int size);

void printArray(int *A, int size);

int main() {

	int size ;

	int *A;

	cout << "enter size";
	cin >> size;

	give_memory(A, size);

	int begin;
	int end = size - 1;
	cout << "enter begin";
	cin >> begin;

	if (begin < 0) return 0;

	srand(time(NULL));

	initArray(A, size);

	printArray(A, size);

	cout << endl;

	quickSort(A, begin, end);

	printArray(A, size);

	delete_memory(A);

	system("pause");

	return 1;
}

void initArray(int *A, int size) {

	for (int i = 0; i < size; i++) {
		A[i] = rand() % 10;
	}
}
void printArray(int *A, int size) {
	for (int i = 0; i < size; i++) {
		cout << A[i] << setw(2);
	}
}
void quickSort(int *A, int begin, int end) {

	int right = end;
	int left = begin;
	int piv = A[(end + begin) / 2];

	while (left < right){
		while (A[left] < piv) left++;
		while (A[right] > piv) right--;
	
		if (left <= right) {
			swap(A[left], A[right]);
			right--; left++;
		}
	}
	
	if (left < end ) quickSort(A, left, end);
	if (right > begin) quickSort(A, begin, right);
}
void give_memory(int * & A, int size) {
	try {
		A = new int[size];
	}
	catch (...) {
		cout << "failed";
	}
}
void delete_memory(int * & A) {
	delete[] A;
}
