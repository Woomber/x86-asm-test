#include <stdio.h>

void subir_volumen() {

	/*
		Uso de Suma en paquetes
	*/

	short int arreglo[] = { 5, 16, 20, 12 }, volumen[] = { 2, 2, 2, 2 }, salida[20];

	_asm {
		MOVQ	MM0, arreglo
		MOVQ	MM2, volumen
		PADDUSW	MM0, MM2
		MOVQ	salida, MM0
	}

	for (unsigned char i = 0; i < 4; i++) {
		printf("%d ", salida[i]);
	}

	printf("\n\n");
}