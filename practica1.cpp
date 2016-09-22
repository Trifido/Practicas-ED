#include <iostream>
#include <pthread.h>
#include "fun_tiempo.h"

using namespace std;

const unsigned long m=16;
const unsigned long n=4;
double resultado_parcial[n];

double f(double x){
	return 4.0/(1+x*x);
}

void *funcion_hebra(void * ih_void){
	unsigned long ih= (unsigned long) ih_void;
	double sumap= 0.0;

	for(int i=ih*(m/n); i<((ih*(m/n))+(m/n)); i++){
		sumap+=f((i+0.5)/(ih*(m/n)));
	}
	resultado_parcial[ih]=sumap;
}

double calcular_integral_concurrente()
{
	double total=0.0;
	pthread_t hebras[n];

	for(int j=0; j<n; j++)
		pthread_create(&hebras[j],NULL,funcion_hebra,NULL);

	for(int f=0; f<n; f++)
		pthread_join(hebras[f],NULL);

	for(int i=0; i<n; i++)
		total+=resultado_parcial[i];
}

int main(){
	cout << calcular_integral_concurrente() << endl;
}




