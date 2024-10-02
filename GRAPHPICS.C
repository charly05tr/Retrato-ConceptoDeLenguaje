#include <stdio.h>
#include <graphics.h>
#define N 15
typedef struct poligono
{
	int *puntos;
	int cantidadPuntos;
	int colorRelleno;
	int colorBorde;
	FILE *arch;
} poligono;

int cara[168], nariz[76], boca[58], ojo1[30], ojo2[48], ceja1[74], ceja2[56], pelo[182], i;
int oreja1[52], oreja2[42], cuerpo1[34], cuerpo2[42], cuello[56], pupila1[28], pupila2[42];
poligono poligonos[N] = {
	{cara,    81, LIGHTMAGENTA, DARKGRAY},     {nariz,   38, LIGHTRED, BLACK},
	{boca,    29, RED, RED},          	       {ojo1,    15, WHITE, LIGHTGRAY},
	{ojo2,    24, WHITE, LIGHTGRAY}, 	       {ceja1,   37, BLACK, BLACK},
	{ceja2,   28, BLACK, BLACK}, 		       {pelo,    91, BLACK, DARKGRAY},
	{oreja1,  26, LIGHTMAGENTA, DARKGRAY}, 	   {oreja2,  21, LIGHTMAGENTA, DARKGRAY},
	{cuerpo1, 17, BLACK, DARKGRAY},            {cuerpo2, 21, BLACK, DARKGRAY},
	{cuello,  28, LIGHTMAGENTA, LIGHTMAGENTA}, {pupila1, 14, BLACK, BLACK},
	{pupila2, 21, BLACK, BLACK}};

void obtenerPoligonos(void);
void iniciarGraficos(void);
void terminarGraficos(void);

void main(void)
{
	iniciarGraficos();
	obtenerPoligonos();
	for (i = 0; i < N; i++) {
		setcolor(poligonos[i].colorBorde);
		setfillstyle(SOLID_FILL, poligonos[i].colorRelleno);
		fillpoly(poligonos[i].cantidadPuntos, poligonos[i].puntos);
	}
	sleep(10);
	terminarGraficos();
}

void obtenerPoligonos(void)
{
	char nombreArch[25];
	int j;
	for (i = 0; i < N; i++) {
		sprintf(nombreArch,"C:\\TC20\\selfie\\%d.txt", i);
		poligonos[i].arch = fopen(nombreArch, "r");
		for (j = 0; fscanf(poligonos[i].arch, "%d", &poligonos[i].puntos[j]) == 1; j++);
		fclose(poligonos[i].arch);
	}
}

void iniciarGraficos(void)
{
	int adap, modo;
	adap = DETECT;
	initgraph(&adap, &modo, "c:\\tc20\\bin");
}

void terminarGraficos(void)
{
	restorecrtmode();
	closegraph();
	cleardevice();
}