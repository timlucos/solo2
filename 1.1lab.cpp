/*
При выполнении данной задачи вы должны сравнить библиотеки “string.h” или <cstring> (С) и
<string> (С++).
А) Перед main() в комментариях /* */ ответьте на вопросы и напишите соответствия С – С++ для
следующих функций (причем соответствия необязательно будут в виде функций):
1) strlen - …
2) strcpy - …
3) strcmp - …
4) strcat - …
5) someString[index] - … (getting the character at index)
6) … - push_back
7) … - pop_back
Функции могут не иметь точного аналога в библиотеке другого языка. Почему? – объясните главную
разницу строк в С и С++.
*/	

#include "1.1lab.h"
#include <string>


// :D
extern "C"
{
	int printf(const char* format, ...);
}

const std::string badCharacters = "( ) ` ~ ! @ # $ % ^ & * - + = | \\ { } [ ] : ; \" ' < > , . ? / _ … \n";

void taskOne() {
	char inputString[8192]; 

	
	printf("Ââåäèòå ñòðîêó:\n");
	fgets(inputString, _countof(inputString), stdin);

	
	std::string unfilteredString(inputString);

	
	std::string filteredString = "";
	for (int i = 0; i < unfilteredString.length(); i++) {
		if (!checkForBadSymbol(unfilteredString.at(i))) {
			filteredString += unfilteredString.at(i);
		}
	}

	
	std::string sortedString = sortString(filteredString);

	
	printf("Îòñîðòèðîâàííàÿ ñòðîêà:\n");
	printf(sortedString.c_str());
	printf("\n\n");
}


bool checkForBadSymbol(char testedChar) {

	for (int i = 0; i < badCharacters.length(); i++) {
		if (testedChar == badCharacters[i])
			return true;
	}
	return false;
}

std::string sortString(std::string s) {
	std::string sortedString = s;
	bool swapped;

	for (int i = 0; i < sortedString.length(); i++) {
		swapped = false;

		for (int j = 0; j < sortedString.length() - i - 1; j++) {
			if (sortedString.at(j) < sortedString.at(j + 1)) continue;

			char buf = sortedString.at(j);
			sortedString.at(j) = sortedString.at(j + 1);
			sortedString.at(j + 1) = buf;
			swapped = true;
		}
		if (!swapped) break;
	}

	return sortedString;
}
