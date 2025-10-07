/*   			ESTOQUE

	Autores:
		Gabriel Mechi Lima
		Henrique Abreu Hollanda da Rocha
		Pedro Bizzari
		João Vitor Antonacci Bittencourt	 

	Data: 26/05/2025

	Descrição: Algoritmo para determinar a quantidade de vendas efetuadas, sob certas condições, em um estoque
	
*/

#include <stdio.h>

int main()
{
    FILE *arquivo;
    int estoque[501][501];	//Matriz 500 x 500
    int m, n;
    int i, j;
    int r;
    int qtdPedidos;
    int tipoPedido, tamanhoPedido;
    int contVendas;
    
    contVendas = 0;
    i = 1;
    j = 1;

    // Abrir o arquivo
    arquivo = fopen("Entrada.txt", "r");
    
	if (arquivo != NULL)
	{
	
    	// Ler número de tipos e tamanhos
    	fscanf(arquivo, "%d %d", &m, &n);

    	if ((m>0 && m<501) && (n>0 && n<501))
		{
        	// Preencher estoque
    		while(i<=m)
			{
				while(j<=n)
				{
            		fscanf(arquivo, "%d", &r);
            		
					if(r>=0 && r<=10)
					{
						estoque[i][j] = r;
						j++;
					}
				}
			
				i++;
				j = 1;
			}	
    	}   	

    	// Ler quantidade de pedidos
    	fscanf(arquivo, "%d", &qtdPedidos);

    	if(qtdPedidos>=1 && qtdPedidos<=1000)
		{
    		// Processar pedidos
    		for (i = 1; i<=qtdPedidos; i++)
			{
        		fscanf(arquivo, "%d %d", &tipoPedido, &tamanhoPedido);

        		if ((tipoPedido>=1 && tipoPedido <= m) && (tamanhoPedido >= 1 && tamanhoPedido <= n))
				{
            		if (estoque[tipoPedido][tamanhoPedido] > 0)
					{
                		estoque[tipoPedido][tamanhoPedido] = estoque[tipoPedido][tamanhoPedido] - 1;
                		contVendas++;
            		}
        		}
    		}
    	}
		
    	printf("\n %d\n", contVendas);
		fclose(arquivo);
	}
	
    return 0;
}
