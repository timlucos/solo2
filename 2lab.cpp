/*
А) Перед main() в комментариях ответьте на вопросы и напишите соответствия С – С++ для
следующих операций :
1) int* ptr = (int*)malloc(sizeof(int)) - int* ptr = new int
2) int* ptrArr = (int*)malloc(sizeof(int) * N) - int* ptrArr = new int[N]
3) free(ptr) - delete ptr
4) free(ptrArr) - delete[] ptrArr
В С++ необходимо ли освобождать динамическую память? Да, оператором delete.
Можно ли освободить одну и ту же выделенную память дважды? Нет, это приводит к недокументированному поведению.
А можно ли освободить невыделенную память? Нет.

Б) Треугольник Фибоначчи. У некоторых это задание было на программировании по С.Теперь
требуется адаптировать эту программу(или написать заново) на С++ с определенными
требованиями(NB) :
	-именно пользователь должен решать(посредством ввода в командную строку) сколько строк у пирамиды должно быть;
	-перемещаться по массиву(-ам) необходимо только через указательную арифметику – Pointer Arithmetic[arr[i][j] - > *(*(arr + i) + j)];
	-использовать только динамическое выделение памяти
*/
#include "taskTwo.h"
#include <iostream>

void taskTwo() {
	int* height = new int;
	int* i = new int;
	int* j = new int;
	int* k = new int;

	std::cout << "Введите нужное количество строк пирамиды: ";
	std::cin >> *height;

	std::cout << '\n';
	for (*i = 0; *i <= *height; ++*i) {

		//выводим нужное кол-во пробелов
		for (*j = 0; *j < *height - *i; ++*j) {
			std::cout << " ";
		}
		//выводим нужное кол-во строк
		for (*k = 0; *k <= *i; ++*k) {
			printf("%d ", hosoyaNumber(i, k));
		}
		std::cout << "\n";
	}
	delete height, i, j, k;
}

int hosoyaNumber(int* n, int* i) {
	//формула с википедии
	return fibNumber(*i + 1) * fibNumber(*n - *i + 1);
}

int fibNumber(int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;
	return fibNumber(n - 1) + fibNumber(n - 2);
}
