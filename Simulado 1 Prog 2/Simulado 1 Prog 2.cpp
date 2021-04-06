#include <stdio.h>
#include <time.h>
#include <stdlib.h>

float imc[250];
float aux, aux2,aux3;


struct ficha_medica{
int codigo;
int origem;
int tipo_atendimento;
int sexo;
int idade;
int altura;
int peso;
int comorbidade;
};

struct ficha_medica ficha[250];

void preencher_struct (void){
    int i=0;
    for(i=0;i<250;i++){

    ficha[i].codigo = i+100;
    ficha[i].origem = rand()%2;
    ficha[i].tipo_atendimento = rand()%3;
    ficha[i].sexo = rand()%2;
    ficha[i].idade = rand()%72+18;
    ficha[i].altura = rand()%45+150;
    ficha[i].peso = rand()%70+50;
    ficha[i].comorbidade = rand()%4;
    }

}


void printar_struct(){
    int i=0;
    for(i=0;i<250;i++){
    printf("PESSOA %d\n\n",i+1);
    printf("Codigo = %d\n", ficha[i].codigo);
    printf("Origem (0 - Macae ou 1 - Regiao) = %d\n",ficha[i].origem);
    printf("Tipo de atendimento (0 - Particular, 1 - Plano ou 2 - SUS) = %d\n",ficha[i].tipo_atendimento);
    printf("Sexo (0 - Feminino ou 1 Masculino) = %d\n",ficha[i].sexo);
    printf("Idade = %d\n",ficha[i].idade);
    printf("Altura (em centimetros)= %d\n",ficha[i].altura);
    printf("Peso (em KG) = %d\n",ficha[i].peso);
    printf("Comorbidade (0 - Nenhuma, 1- Cardiaco, 2 Respiratorio, 3 Cardiaco e Respiratorio) = %d\n",ficha[i].comorbidade);
    printf("\n\n\n");
    }
}

void calculo_imc(){
    int i=0;
    for(i=0;i<250;i++){
	aux=ficha[i].peso;
    aux2=ficha[i].altura;
    imc[i]=(aux/(aux2*aux2))*10000;

    }


}


int main(){
    int i=0;
    int obesidade[250];
	float total_sem_comorbidades=0;
	float total_idade_sem_comorbidades=0;
	float media_idade_sem_comorbidades=0;
	float total_particular=0,total_plano=0,total_sus=0;
	float total_obesidade_e_outras=0;
	float total_todas_comorbidades=0;
	srand(time(NULL));
	//chamando funções
    preencher_struct();
    printar_struct();

    calculo_imc();
    for(i=0;i<250;i++){
    
    	printf("O IMC DA PESSOA %d eh %.2f\n",i+1,imc[i]);
    
   	 if(imc[i]>=30){
    	obesidade[i]=1;
		}

    }
	
	for(i=0;i<250;i++){
		
		if (obesidade[i]!=1 && ficha[i].comorbidade==0){
		total_sem_comorbidades++;
		aux3=ficha[i].idade;
		total_idade_sem_comorbidades=total_idade_sem_comorbidades+aux3;
		}
	
		if (ficha[i].tipo_atendimento==0){
			total_particular++;
		}
			else if(ficha[i].tipo_atendimento==1){
				total_plano++;
			}
				else if(ficha[i].tipo_atendimento==2){
					total_sus++;
				}
	
		if(obesidade[i]==1 && ficha[i].comorbidade!=0){
			total_obesidade_e_outras++;
		}
		
		if(obesidade[i]==1 && ficha[i].comorbidade==3){
			total_todas_comorbidades++;
		}
	}

	media_idade_sem_comorbidades=total_idade_sem_comorbidades/total_sem_comorbidades;
	
	printf("Media de idade de pacientes sem comorbidades: %.2f\n",media_idade_sem_comorbidades);
	printf("Total particular = %f (%.2f%%) \t Total plano = %f (%.2f%%) \t Total SUS = %f (%.2f%%)\n",total_particular,(total_particular/250)*100,total_plano,(total_plano/250)*100,total_sus,(total_sus/250)*100);
	printf("Total de pacientes com outras comorbidades alem da obesidade: %f (%.2f%%)\n",total_obesidade_e_outras,(total_obesidade_e_outras/250)*100);
	printf("Total de pacientes com todas comorbidades pesquisadas: %.f  (%.2f%%) ",total_todas_comorbidades,(total_todas_comorbidades/250)*100);
	
    return 0;
}

