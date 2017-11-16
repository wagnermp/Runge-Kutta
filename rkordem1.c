/*exercicio 1 aula dia 14 de novembro de 2017
Resolver y'=1+(1-y)^2, 2<=t<=3, y(2)=1 com N=10 pontos*/
#include <stdio.h>
#include <math.h>
FILE *arquivo;
#define n 10

double f( double t, double y )
{
	return ( 1 + pow(t-y, 2) );
}

main()
{
	int i;
	double a, b, t, y, ti, yi, h, k1, k2, k3, k4;


	//Abertura do arquivo para Gravação
	arquivo = fopen("dadosRungeKutta4.dat", "w");

	//Intervalo utilizado para calcular o espaçamento
	a = 2.0;
	b = 3.0;
	
	//Calculando o espaçamento
	h = (b-a)/(n*1.0);

	//Inicializando x e y
	t = 2.0;
	y = 1.0;
	
	//Gravando no arquivo o primeiro ponto a ser plotado
	fprintf(arquivo, "%lf\t\t%lf\n", t, y);
	printf("\n1º Ponto = (%lf, %lf).", t, y );

	//Inicializando as constantes k[n]
	k1 = 0.0;
	k2 = 0.0;
	k3 = 0.0;
	k4 = 0.0;
	
	//Calculando os demais pontos e os armazenando no arquivo
	for( i=0; i<n; i++)
	{
		ti = t + h;
		k1 = f(t, y);
		k2 = f( t+(h/2.0), y+(k1*h/2.0) );
		k3 = f( t+(h/2.0), y+(k2*h/2.0) );
		k4 = f( t + h, y + h*k3 );

		yi = y + (1/6.0)*(k1 + 2*k2 + 2*k3 + k4)*h;

		printf("\nPasso %d: f(%lf, %lf) = %lf, %dº Ponto = (%lf, %lf).", i, t, y, f(t, y), i+1, ti, yi );
		fprintf(arquivo, "%lf\t\t%lf\n", ti, yi);

		printf("\nk1 = %lf.\nk2 = %lf.\nk3 = %lf.\nk4 = %lf.\n", k1, k2, k3, k4);

		t = ti;
		y = yi;

		k1 = 0.0;
		k2 = 0.0;
		k3 = 0.0;
		k4 = 0.0;

	}

	printf("\n\n");
	
	//Fechando arquivo
	fclose(arquivo);

}
