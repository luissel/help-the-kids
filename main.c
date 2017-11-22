#include <stdio.h>

#include "pointerutil.h"

int main() {
	int firstValue;

	printf("Introduceti un numar:\n");
	scanf("%d", &firstValue);
	printf("\nDupa citire, valoarea este, dupa cum stim deja: %d.\n", firstValue);

	firstValue = 7;
	printf("I-am atribuit o alta valoare si acum este: %d.\n", firstValue);

	int *pFirst = &firstValue;
	printf("Adresa variabilei \"firstValue\" este: %p.\n", &firstValue);
	printf("O retinem intr-un pointer la int, pFirst: %p.\n", &firstValue);

	*pFirst = 5;
	printf(
		"I-am schimbat valoarea lui firstValue prin dereferentierea lui "
		"pFirst, adica modificarea valorii de la adresa %p: %d\n",
		pFirst, firstValue
	);

	int secondValue = 1 + (2 << 8) + (3 << 16) + (4 << 24);
	printf(
		"Cream o variabila, secondValue, ai carei octeti vrem sa fie de la cel"
		"mai mic, la cel mai mare: 1, 2, 3, 4.\nVa arata astfel: [4][3][2][1].\n"
	);
	printf("Valoarea decimala: %d.\n", secondValue);

	// Moduri diferite de a accesa separat cei 4 octeti
	// MODUL 1
	int leastByteMask = (1 << 8) - 1;
	printf("\nAfisarea separata a octetilor. Modul 1.\n");
	printf("---------------------------------------\n");
	printf("Cel mai mic octet din secondValue: %d.\n",
		secondValue & leastByteMask);
	printf("Al doilea octet din secondValue: %d.\n",
		(secondValue >> 8) & leastByteMask);
	printf("Al treilea octet din secondValue: %d.\n",
		(secondValue >> 16) & leastByteMask);
	printf("Cel mai mare octet din secondValue: %d.\n",
		(secondValue >> 24) & leastByteMask);

	// MODUL 2
	int mask8bits = 1 << 8;
	int mask16bits = 1 << 16;
	int mask24bits = 1 << 24;
	printf("\nAfisarea separata a octetilor. Modul 2.\n");
	printf("---------------------------------------\n");
	printf("Cel mai mic octet din secondValue: %d.\n",
		secondValue % mask8bits);
	printf("Al doilea octet din secondValue: %d.\n",
		(secondValue / mask8bits) % mask8bits);
	printf("Al treilea octet din secondValue: %d.\n",
		(secondValue / mask16bits) % mask8bits);
	printf("Cel mai mare octet din secondValue: %d.\n",
		(secondValue / mask24bits) % mask8bits);

	// MODUL 3
	char *pSecond = (char *) &secondValue;
	printf("\nAfisarea separata a octetilor. Modul 3.\n");
	printf("---------------------------------------\n");
	printf("Cel mai mic octet din secondValue: %d.\n",
		*pSecond);
	printf("Al doilea octet din secondValue: %d.\n",
		*(pSecond + 1));
	printf("Al treilea octet din secondValue: %d.\n",
		*(pSecond + 2));
	printf("Cel mai mare octet din secondValue: %d.\n",
		*(pSecond + 3));

	printf("\nNe propunem sa modificam octetul cu valoarea 3 in 71.\n");
	*(pSecond + 2) = 71;
	printf("Noua valoare decimala: %d.\n", secondValue);

	printf(
		"\nNe propunem sa citim un vector de la tastatura si sa retinem"
		"numarul de elemente pare, numarul de elemente prime si media"
		"aritmetica a acestora.\nIntroduceti lungimea vectorului:\n"
	);

	int vLength, i, v[100], evenCount, primeCount;
	float average;
	scanf("%d", &vLength);
	printf("Introduceti elementele vectorului:\n");
	for (i = 0; i < vLength; ++i) {
		scanf("%d", &v[i]);
	}

	// Functia este implementata in "pointerutil.h"
	getDataFromVector(v, vLength, &evenCount, &primeCount, &average);

	return 0;
}