#include <stdio.h>
#define MAXSIZE 15
 
struct stack {
  int stk[MAXSIZE];
  int top;
};

typedef struct stack STACK;
STACK s;
 
void push(void);
int  pop(void);
void display(void);
 
int main () {
    int escolha;
    s.top = -1;
 
    printf ("OPERACOES DE UMA PILHA\n");
    while (true) {
        printf ("\n ----------------");
        printf ("\n  1 --> PUSH     ");
        printf ("\n  2 --> POP      ");
        printf ("\n  3 --> DISPLAY  ");
        printf ("\n  4 --> SAIR     ");
        printf ("\n ----------------");
 
        printf("\n Escolha uma opcao: ");
        scanf("%d", &escolha);
        switch (escolha) {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            return(0);
        }
        fflush(stdin);
    }
}

void push () {  
    int num;
    if (s.top == (MAXSIZE - 1)) 
        printf ("\n Pilha cheia!");
    else {
        printf ("\n Insira o elemento: ");
        scanf ("%d", &num);
        s.top = s.top + 1;
        s.stk[s.top] = num;
        printf ("\n Elemento inserido! ");
    }
}

int pop () {
    int num;
    if (s.top == - 1) {
        printf ("\n Pilha vazia!");
        return (s.top);
    }
    else {
        num = s.stk[s.top];
        printf ("\n Elemento retirado: %d", s.stk[s.top]);
        s.top = s.top - 1;
    }
    return(num);
}

void display () {
    int i;
    if (s.top == -1)
      printf ("\n Pilha vazia!");
    else {
      printf ("\n Elementos na pilha:");
      for (i = s.top; i >= 0; i--)
        printf ("\n %d", s.stk[i]);
    }
    printf("\n");
}

