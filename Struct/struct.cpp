//Versao 1.0
// Escrever um algoritmo que solicite ao usuario dois numeros reais e ao final
// Apresentar a media aritmética e o maior numero

//Versao 2.0
//solicitar a quantidade de valores a serem informados

//Versao 3.0
//3.1 ao final apresentar os numeros informados pelo usuario
//3.2 todos os numeros pares amostra
//3.3 todos os numeros impar a mostra
//3.4 apresentar a media dos pares e dos impares

// Versão 4.0: Aqui introduzimos os vetores
// 4.1) Ao final emitir um relatorio com todas as notas acima da media
// 4.2) Ao final emitir um relatorio com todas as notas abaixo da media

// Versao 5.0:
// Solicitar tambem, alem das notas:
// 5.1) Nome do aluno
// 5.2) Idade
// 5.3) Sexo
// 5.4) Aprovado/Reprovado
// 5.5) As X notas do aluno e ao final gerar o relatorio de:
// 5.6) Nomes dos alunos aprovados
// 5.7) Nomes dos alunos Reprovados
// 5.8) Nomes dos alunos com media acima da nota de corte da turma
// 5.9) Nomes dos alunos com media abaixo da nota de corte da turma
// 5.10) Percentual de alunos e de alunas, aprovados e reprovados
// 5.11) a verdade a hipotese de que alunos mais jovens estudam e tiram notas melhores

#include <stdio.h> 
#include <locale.h>

struct Alunos {
	char Nome[30];
	int Idade;
	char Sexo;
	float Notas[10];
	float mediaAluno;
	bool Aprovado;
};


int main() {
	setlocale(LC_ALL, "Portuguese");
	float media;
	float notaCorte, resultado;
	int qtdNotas, resposta, qtdAlunos=0, qtdMasc=0, qtdFem=0;
	int menorIdade, qtdAprovadosNovos=0, qtdReprovadosNovos=0, maiorIdade;
	int qtdAprovadosVelhos=0, qtdReprovadosVelhos=0;
	float aprovados=0, reprovados=0;

	printf(" Informe a media para aprovacao: ");
	scanf("%f", &media);
	printf("\n Informe a quantidade de notas: ");
	scanf("%d", &qtdNotas);

	struct Alunos turma [999];

	do {
		qtdAlunos=qtdAlunos+1;
		// Aqui Coletar os dados dos alunos...
		//Pegar o sexo
		do {
	    printf(" Informe o sexo do(a) %i. aluno(a)? [M/F] ", qtdAlunos);
		  scanf("%s", &turma[qtdAlunos].Sexo);
		} while(turma[qtdAlunos].Sexo != 'M' &
		        turma[qtdAlunos].Sexo != 'm' &&
						turma[qtdAlunos].Sexo != 'F' and
						turma[qtdAlunos].Sexo != 'f' );

		//Pegar o nome
		if (turma[qtdAlunos].Sexo == 'M' | turma[qtdAlunos].Sexo == 'm') {
		  printf(" Informe o nome do %i. aluno: ", qtdAlunos);
		  qtdMasc++;
		}
		if (turma[qtdAlunos].Sexo == 'F' || turma[qtdAlunos].Sexo == 'f') {
		  printf(" Informe o nome da %i. aluna: ", qtdAlunos);
		  qtdFem++;
		}
    scanf("%s", &turma[qtdAlunos].Nome);

		//Pegar a Idade
		do {
		  printf(" Informe a idade de %s [de 7 a 99]: ", turma[qtdAlunos].Nome);
		  scanf("%i", &turma[qtdAlunos].Idade);
	  } while(turma[qtdAlunos].Idade < 7 or
		        turma[qtdAlunos].Idade > 99);

   if (qtdAlunos==1) {
   	  menorIdade = turma[qtdAlunos].Idade;
   	  maiorIdade = turma[qtdAlunos].Idade;
   	}
   	else if (menorIdade > turma[qtdAlunos].Idade)
   	  menorIdade = turma[qtdAlunos].Idade;
   	else if (maiorIdade < turma[qtdAlunos].Idade)
   	  maiorIdade = turma[qtdAlunos].Idade;

		//Pegar as notas
		for (int i=1; i<=qtdNotas; i++) {
		  printf(" Informe a %i. nota de %s: ", i, turma[qtdAlunos].Nome);
		  scanf("%f", &turma[qtdAlunos].Notas[i]);
		}
		// Aqui Calcular a media...
		for ( int i=1; i<=qtdNotas; i++)
			turma[qtdAlunos].mediaAluno = turma[qtdAlunos].Notas[i] + turma[qtdAlunos].mediaAluno;
		turma[qtdAlunos].mediaAluno = turma[qtdAlunos].mediaAluno/qtdNotas;
		printf(" %0.1f ", turma[qtdAlunos].mediaAluno);

		//Aprovado ou Reprovado

		//if (turma[qtdAlunos].mediaAluno >= media) {
		//	turma[qtdAlunos].Aprovado = true;
		//}
		//else {
		//	turma[qtdAlunos].Aprovado = false;
		//}

		turma[qtdAlunos].Aprovado = turma[qtdAlunos].mediaAluno >= media;

		//Mostrar Notas
		printf("\n As notas de %s: ", turma[qtdAlunos].Nome);
		for (int i=1; i<=qtdNotas; i++) {
		  printf("\n %i nota: %0.1f ", i, turma[qtdAlunos].Notas[i]);
		}
		// Aqui Perguntar se deseja cadastrar outro aluno...
		printf("\n Deseja informar o proximo aluno? [1/Sim ou 2/Nao] ");
		scanf("%d", &resposta);
	} while(resposta == 1);

	// Aqui, apresentar os relatorios...
	//Aprovados
	printf("\n------Aprovados---------");
	for(int i=1; i<=qtdAlunos; i++){
		if(turma[i].Aprovado) {
			printf("\n - %s  %0.2f", turma[i].Nome, turma[i].mediaAluno);
			aprovados++;
		}
	}
	//Reprovados
	printf("\n------Reprovados---------");
	for(int i=1; i<=qtdAlunos; i++){
		if(!turma[i].Aprovado){
			printf("\n - %s  %0.2f", turma[i].Nome, turma[i].mediaAluno);
			reprovados++;
		}
	}
	//Calcular a Nota de  corte
	printf("\n A nota de Corte : ");
	for ( int i=1; i<=qtdAlunos; i++){
			notaCorte = notaCorte+ turma[i].mediaAluno;
		}
		notaCorte = notaCorte/qtdAlunos;
		printf("%0.1f ", notaCorte);

	//Acima da Media
	printf("\n --- Acima da Media ---");
	for(int i=1; i<=qtdAlunos; i++){
		if(turma[i].mediaAluno > notaCorte ){
			printf("\n%s ", turma[i].Nome);
		}
	}
	//Abaixo da media
	printf("\n --- Abaixo da Media --- ");
	for(int i=1; i<=qtdAlunos; i++){
		if(turma[i].mediaAluno < notaCorte ){
			printf("\n%s ", turma[i].Nome);
		}
	}
  //Para saber se os aprovados em maioria são menores ou maiores de idade
	float  mediaDasIdades = ((maiorIdade-menorIdade)/2)+menorIdade;

	//Alunos abaixo do meio das idades
	printf("\n --- Abaixo do Meio das idades --- ");
	for(int i=1; i<=qtdAlunos; i++){
		if (turma[i].Idade < mediaDasIdades){
			printf("\n - %s  %0.2f", turma[i].Nome, turma[i].mediaAluno);
			if (turma[i].mediaAluno >= media)
			  qtdAprovadosNovos++;
			else
        qtdReprovadosNovos++;
		}
	}

	//Alunos acima do meio das idades
	printf("\n --- Acima do meio das idades --- ");
	for(int i=1; i<=qtdAlunos; i++){
		if (turma[i].Idade >= mediaDasIdades){
			printf("\n - %s  %0.2f", turma[i].Nome, turma[i].mediaAluno);
			if (turma[i].mediaAluno >= media)
			  qtdAprovadosVelhos++;
			else
        qtdReprovadosVelhos++; 		}
	}
	printf("\nA porcentagem de alunos aprovados e: %0.0f%% ", (aprovados / qtdAlunos * 100));
	printf("\nA porcentagem de alunos reprovados e: %0.0f%% ", (reprovados / qtdAlunos * 100));
	printf("\nO total de alunos e: %i ", (qtdMasc));
	printf("\nO total de alunas e: %i ", (qtdFem));
	float auxiliar1 = qtdMasc;
	float auxiliar2 = qtdAlunos;
	printf("\nA porcentagem de alunos e: %0.0f%% ", (auxiliar1 / auxiliar2 * 100));
	auxiliar1 = qtdFem;
	printf("\nA porcentagem de alunas e: %0.0f%% ", (auxiliar1 / auxiliar2 * 100));
  if (qtdAprovadosNovos >= qtdAprovadosVelhos)
	  printf("\n a verdade a hipotese de que alunos mais jovens estudam e tiram notas melhores que alunos mais velhos!");
  else
	  printf("\n a verdade a hipotese de que alunos com mais idade estudam e tiram notas melhores que alunos mais novos!");
}


