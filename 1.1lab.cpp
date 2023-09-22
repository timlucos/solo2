/*
À) Ïåðåä main() â êîììåíòàðèÿõ îòâåòüòå íà âîïðîñû è íàïèøèòå ñîîòâåòñòâèÿ Ñ – Ñ++ äëÿ
ñëåäóþùèõ ôóíêöèé(ïðè÷åì ñîîòâåòñòâèÿ íåîáÿçàòåëüíî áóäóò â âèäå ôóíêöèé) :
	1) strlen - string::length
	2) strcpy - íåò àíàëîãà (ïèøåì a=b)
	3) strcmp - íå èìååò àíàëîãà
	4) strcat - someString.append
	5) someString[index] - someString.at(index)
	6) íå èìååò òî÷íîãî àíàëîãà (âîçìîæíî èñïîëüçîâàòü strcat/ctrncat) - push_back
	7) íå èìååò àíàëîãà - pop_back
	Ôóíêöèè ìîãóò íå èìåòü òî÷íîãî àíàëîãà â áèáëèîòåêå äðóãîãî ÿçûêà.Ïî÷åìó ? – îáúÿñíèòå ãëàâíóþ
	ðàçíèöó ñòðîê â Ñ è Ñ++.

	Ñòðîêè â C - ìàññèâ ýëåìåíòîâ char ñ null-áàéòîì â îêîí÷àíèè
	Ñòðîêè â C++ - îáúåêò êëàññà String ñ äèíàìè÷åñêîé ïàìÿòüþ

	Á) Òåïåðü íàïèøèòå ïðîãðàììó íà Ñ++, êîòîðàÿ áóäåò ñîðòèðîâàòü áóêâû â àëôàâèòíîì ïîðÿäêå â
	âåäåííîé ïîëüçîâàòåëåì ñòðîêå.Ïðè÷åì ïðîãðàììà äîëæíà óäàëÿòü ïðîáåëû è ïóíêòóàöèîííûå
	çíàêè.
	NB: Èñïîëüçóéòå òîëüêî áèáëèîòåêó <string>.
*/	

#include "taskOne.h"
#include <string>


// :D
extern "C"
{
	int printf(const char* format, ...);
}
//ñòðîêà ñ ñèìâîëàìè, êîòîðûå íàäî óáðàòü
const std::string badCharacters = "( ) ` ~ ! @ # $ % ^ & * - + = | \\ { } [ ] : ; \" ' < > , . ? / _ … \n";

void taskOne() {
	char inputString[8192]; //áóôåð ââîäà

	//çàïðîñèòü ñòðîêó
	printf("Ââåäèòå ñòðîêó:\n");
	fgets(inputString, _countof(inputString), stdin);

	//êîíâåðòèðîâàòü ñòðîêó C â String
	std::string unfilteredString(inputString);

	//îòôèëüòðîâàòü
	std::string filteredString = "";
	for (int i = 0; i < unfilteredString.length(); i++) {
		if (!checkForBadSymbol(unfilteredString.at(i))) {
			filteredString += unfilteredString.at(i);
		}
	}

	//îòñîðòèðîâàòü îòôèëüòðîâàííóþ ñòðîêó
	std::string sortedString = sortString(filteredString);

	//âûâåñòè
	printf("Îòñîðòèðîâàííàÿ ñòðîêà:\n");
	printf(sortedString.c_str());
	printf("\n\n");
}

//Îïðåäåëÿåò, ÿâëÿåòñÿ ëè ñèìâîë ïëîõèì (òðåáóþùèì ôèëüòðàöèè)
bool checkForBadSymbol(char testedChar) {
	//Ñðàâíèâàåì ñèìâîë ñ êàæäûì ýëåìåíòîâ ìàññèâà badSymbols
	for (int i = 0; i < badCharacters.length(); i++) {
		if (testedChar == badCharacters[i])
			return true;
	}
	return false;
}
//Ñîðòèðóåò âõîäíóþ ñòðîêó, èñïîëüçóÿ ñîðòèðîâêó ïóçûðüêîì
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
