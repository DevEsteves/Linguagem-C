#include <stdio.h>
#include <stdlib.h>

typedef struct Teste{
	int num[5];
	int frente;
	int fundo;
	int inicio;
} Fila;


void Iniciar(Fila *in);
int Inserir(Fila *x);
void Mostrar(Fila *y);
void Deletar(Fila *d);

int main(void)
{
	Fila ex, *p;
	p = &ex;
	int op, op2;
	
    if(p->inicio!=1)
	{
        Iniciar(&ex);
	}
	
	do{
		printf("--------Menu Principal-----------\n1 - Inserir\n2 - Visualizar fila\n3 - Deletar\n\n");
		scanf("%d",&op);
		switch(op)
		{
			case 1: Inserir(&ex); break;
			case 2: Mostrar(&ex); break;
			case 3: Deletar(&ex); break;
			case 4: printf("Volte sempre\n");
			default: printf("Insira uma opcao valida\n");
		}	
	}while(op!=4);
	
	return 0;
}

void Iniciar(Fila *in)
{
	int i;
	in->frente = 0;
	in->fundo = 0;
	for(i=0;i<5;i++)
	{
		in->num[i] = 0;
	}
	in->inicio = 1;
}

int Inserir(Fila *x)
{
	int valor;
	
	scanf("%d",&valor);
	
    if(x->fundo==5)
    {
    	printf("Fila Lotada\n");
    	return 0;
	}
	else if(x->frente==x->fundo)
	{
		x->num[x->frente] = valor;
	}
	else if(x->fundo>x->frente)
	{
		x->num[x->fundo] = valor;
	}
	x->fundo = x->fundo + 1;
	
}

void Mostrar(Fila *y)
{
	int i;
	if(y->frente==y->fundo)
	{
		printf("Fila Vazia\n");
	}
	else if(y->frente!=y->fundo)
	{
		printf("----------Fila-----------\n");
		for(i=y->frente;i<y->fundo;i++)
	    {
			printf("%d\n",y->num[i]);
	    }
    }
}

void Deletar(Fila *d)
{
	int i, y;
	if(d->fundo>=0)
	{
		for(i=1, y = 0;i<=4, y<=4;i++, y++)
		{
			d->num[y] = d->num[i];
		}
		if(d->fundo>0)
		{
			d->fundo = d->fundo - 1;
		}
	}else
	{
		printf("Fila Vazia\n");
	}
}