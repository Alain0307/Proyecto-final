#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "CORRECTOR.h"
#define MAXPALABRAS 10000

void Diccionario(char* szNombre, char szPalabras[][TAMTOKEN], int iEstadisticas[], int& iNumElementos) {

	FILE* fp;
	char szWords[MAXPALABRAS][TAMTOKEN];
	int szsimbolo, o, k, end, conta;
	char szcontrol[TAMTOKEN];

	fopen_s(&fp, szNombre, "r");

	szsimbolo = fgetc(fp);
	iNumElementos = 0;
	k = 0;

	while (feof(fp) == 0) {
		if (!((szsimbolo == 9) || (szsimbolo == 10) || (szsimbolo == 13) || (szsimbolo == 32) || (szsimbolo == 40) || (szsimbolo == 41) || (szsimbolo == 44) || (szsimbolo == 46) || (szsimbolo == 59))) {
			szWords[iNumElementos][k] = towlower((char)szsimbolo);
			szsimbolo = fgetc(fp);
			k++;
		}
		else {
			
			if (k > 0) {
				
				szWords[iNumElementos][k] = '\0';
				iEstadisticas[iNumElementos] = 1;
				
				if (iNumElementos > 0) {
					
					for(o=0; 0<iNumElementos; o++)
						if (strcmp(szWords[o], szWords[iNumElementos]) == 0) {

							iEstadisticas[o] = iEstadisticas[o]++;
							o = iNumElementos;
							iNumElementos = iNumElementos--;
						}
				}
				iNumElementos++;
				k = 0;
			}
			szsimbolo = fgetc(fp);
		}
	}
	fclose(fp);


}