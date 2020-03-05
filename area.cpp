#include <stdio.h>

void area_triangulo() {

	/*
		CALCULAR EL ¡REA DE UN TRI¡NGULO
	*/

	short int base, altura;
	int area;

	base = 250;
	altura = 300;

	_asm {
		// multiplicar
		MOV AX, base
		MUL altura
		// obtener la parte alta del resultado
		AND EDX, 0xFFFF
		SHL EDX, 16
		// preparar la parte baja
		AND EAX, 0xFFFF
		// juntar ambas partes
		OR EAX, EDX
		// dividir entre 2
		SAR EAX, 1
		// enviar resultado
		MOV area, EAX
	}

	printf("%d\n", area);

}

void area_circulo() {
	/*
		CALCULAR EL ¡REA DE UN CÌRCULO
		USANDO FPU
	*/

	float radio, area;

	radio = 5;

	_asm {
		FINIT
		FLD		radio			// recibe un m32fp
		FMUL	ST(0), ST(0)
		FLDPI
		FMUL	ST(0), ST(1)	// ST(0) *= ST(1)
		FSTP	area
	}

	printf("%f\n", area);
}