#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void exercicio1() {
    int mat[] = {512, 102, 678, 205, 789, 317, 404};
    int busca = 317;
    int achou = 0;
    
    for(int i = 0; i < 7; i++) {
        if(mat[i] == busca) {
            printf("Aluno presente na posicao: %d\n", i);
            achou = 1;
        }
    }
    if(achou == 0) {
        printf("Aluno ausente\n");
    }
}

void exercicio2() {
    int prod[] = {55, 12, 89, 33, 21, 90, 44};
    int busca = 99;
    int i;
    int encontrado = 0;
    
    for(i = 0; i <= 7; i++) { 
        if(prod[i] == busca) {
            printf("Produto localizado\n");
            encontrado = 1;
        }
    }
    if(encontrado == 0) printf("Claramente este codigo nao existe no estoque\n");
}

void exercicio3() {
    int liv[] = {10, 23, 35, 47, 59, 62, 78, 91};
    int busca = 59;
    int inicio = 0, fim = 7;
    int iteracoes = 0;
    
    while(inicio <= fim) {
        iteracoes++;
        int meio = inicio + fim / 2; 
        
        if(liv[meio] == busca) {
            printf("Livro encontrado. Iteracoes: %d\n", iteracoes);
            break;
        }
        else if(liv[meio] < busca) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
}

void exercicio4() {
    int users[] = {101, 203, 305, 407, 509, 611, 713};
    int busca = 407;
    int inicio = 0, fim = 6, achou = 0;
    
    while(inicio <= fim) {
        int meio = (inicio + fim) / 2;
        if(users[meio] == busca) {
            printf("Acesso permitido\n");
            achou = 1;
            break;
        }
        if(users[meio] < busca) inicio = meio + 1;
        else fim = meio - 1;
    }
    if(achou == 0) printf("Usuario nao encontrado\n");
}

void exercicio5() {
    int arr[] = {45, 12, 78, 3, 56, 89, 23, 67};
    int aux;
    
    printf("Antes: ");
    for(int i=0; i<8; i++) printf("%d ", arr[i]);
    printf("\n");
    
    for(int i=0; i<8; i++) {
        for(int j=0; j<7; j++) {
            if(arr[j] > arr[j+1]) {
                aux = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = aux;
            }
        }
    }
    
    printf("Depois: ");
    for(int i=0; i<8; i++) printf("%d ", arr[i]);
    printf("\n");
    
    int busca = 56;
    int inicio = 0, fim = 7;
    while(inicio <= fim) {
        int meio = (inicio + fim) / 2;
        if(arr[meio] == busca) {
            printf("Valor 56 encontrado\n");
            break;
        }
        if(arr[meio] < busca) inicio = meio + 1;
        else fim = meio - 1;
    }
}

void exercicio6() {
    char nomes[5][20] = {"Daniel", "Ana", "Eduarda", "Carlos", "Bruna"};
    char busca[20] = "Carlos";
    
    for(int i = 0; i < 5; i++) {
        if(strcmp(nomes[i], busca) == 0) {
            printf("Nome encontrado: %s na posicao %d\n", nomes[i], i);
        }
    }
}

/*

Exercicio 7:

Em um vetor de 1000 elementos, a busca sequencial verifica elemento por elemento. Em média, ela precisará percorrer metade do vetor 
para encontrar o alvo, resultando em cerca de 500 operações. No pior dos casos (se o elemento for o último ou não existir), 
fará 1000 operações.
A busca binária é absurdamente mais eficiente neste cenário. Enquanto a busca sequencial precisaria de até 1000 verificações, 
a busca binária garante encontrar qualquer número (ou confirmar sua ausência) em no máximo 10 passos.

*/

void exercicio8() {
    int notas[] = {2, 3, 5, 6, 7, 8, 9, 10};
    int n = 8; 
    int nota_buscada;
    int inicio = 0, fim = n - 1, meio;
    int encontrada = -1;

    printf("Digite a nota que deseja buscar: ");
    scanf("%d", &nota_buscada);

    while (inicio <= fim) {
        meio = (inicio + fim) / 2;

        if (notas[meio] == nota_buscada) {
            encontrada = meio;
            break;
        } else if (notas[meio] < nota_buscada) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }

    if (encontrada != -1) {
        int maiores_que_a_nota = (n - 1) - encontrada;
        
        printf("Nota %d encontrada no sistema.\n", nota_buscada);
        printf("Quantidade de alunos com nota maior que %d: %d\n", nota_buscada, maiores_que_a_nota);
    } else {
        printf("A nota %d nao existe no sistema.\n", nota_buscada);
    }

    return 0;


// Exercicio 9: ======================

int busca_binaria(int vetor[], int tamanho, int alvo) {
    int inicio = 0, fim = tamanho - 1, meio;
    
    while (inicio <= fim) {
        meio = (inicio + fim) / 2;
        
        if (vetor[meio] == alvo) {
            return meio;
        } else if (vetor[meio] < alvo) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    
    return -1;
}

void exercicio9() {
    int vetor[] = {5, 10, 15, 20, 25, 30};
    int tamanho = 6;
    int alvo;
    
    printf("Digite o numero a ser buscado: ");
    scanf("%d", &alvo);
    
    int resultado = busca_binaria(vetor, tamanho, alvo);
    
    printf("Retorno: %d\n", resultado);
    
    return 0;
}

// ==============================

/*

Exercicio 10:

Lista Desordenada de 10 elementos: Busca Sequencial
Lista Ordenada de 1.000.000 de elementos: 

A busca binária tem complexidade O(\log n), o que significa que para 1.000.000 de elementos (Lista B), ela fará no máximo cerca de 
20 verificações. A busca sequencial tem complexidade O(n), o que exigiria até 1.000.000 de verificações. 

*/

void exercicio11() {
    int pedidos[] = {903, 112, 457, 221, 678, 345, 789, 150};
    int tamanho = 8;
    int codigo_buscado;
    int comparacoes = 0;
    int encontrado = -1;

    printf("Digite o codigo do pedido: ");
    scanf("%d", &codigo_buscado);

    for (int i = 0; i < tamanho; i++) {
        comparacoes++;
        if (pedidos[i] == codigo_buscado) {
            encontrado = i;
            break;
        }
    }

    if (encontrado != -1) {
        printf("Pedido %d encontrado na posicao: %d\n", codigo_buscado, encontrado);
        printf("Quantidade de comparacoes realizadas: %d\n", comparacoes);
    } else {
        printf("Pedido nao encontrado.\n");
    }

    return 0;
}

void exercicio12() {
    long long int telefones[] = {11987654321LL, 11991234567LL, 11993456789LL, 11995678901LL, 11997890123LL};
    int tamanho = 5;
    long long int numero_buscado;
    int inicio = 0, fim = tamanho - 1, meio;
    int encontrado = -1;

    printf("Digite o numero de telefone para busca (apenas numeros): ");
    scanf("%lld", &numero_buscado);

    while (inicio <= fim) {
        meio = (inicio + fim) / 2;

        if (telefones[meio] == numero_buscado) {
            encontrado = meio;
            break;
        } else if (telefones[meio] < numero_buscado) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }

    if (encontrado != -1) {
        printf("Telefone localizado na posicao: %d\n", encontrado);
    } else {
        printf("Numero nao encontrado na agenda.\n");
    }

    return 0;
}

void exercicio13() {
    int sensores[] = {45, 12, 78, 33, 90, 21, 56, 67};
    int tamanho = 8;
    int leitura_buscada;
    int verificacoes = 0;
    int encontrado = 0;

    printf("Digite a leitura do sensor que deseja buscar: ");
    scanf("%d", &leitura_buscada);

    for (int i = 0; i < tamanho; i++) {
        verificacoes++;
        if (sensores[i] == leitura_buscada) {
            encontrado = 1;
            break;
        }
    }

    if (encontrado) {
        printf("Leitura %d encontrada.\n", leitura_buscada);
    } else {
        printf("Leitura nao encontrada.\n");
    }
    
    printf("Total de verificacoes realizadas: %d\n", verificacoes);

    return 0;
}

void exercicio14() {
   
    long long int cpfs[] = {11111111111LL, 22222222222LL, 33333333333LL, 44444444444LL, 55555555555LL};
    int tamanho = 5;
    long long int cpf_buscado;
    int inicio = 0, fim = tamanho - 1, meio;
    int encontrado = -1;
    int etapas = 0;

    printf("Digite o CPF para busca (apenas numeros): ");
    scanf("%lld", &cpf_buscado);

    while (inicio <= fim) {
        etapas++;
        meio = (inicio + fim) / 2;

        if (cpfs[meio] == cpf_buscado) {
            encontrado = meio;
            break;
        } else if (cpfs[meio] < cpf_buscado) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }

    if (encontrado != -1) {
        printf("CPF localizado na posicao: %d\n", encontrado);
    } else {
        printf("CPF nao cadastrado.\n");
    }
    printf("Numero de etapas da busca: %d\n", etapas);

    return 0;

void exercicio15() {
    int dados[] = {88, 23, 45, 12, 67, 34, 90, 10};
    int tamanho = 8;
    int temp, alvo;
    int inicio = 0, fim = tamanho - 1, meio, encontrado = -1;

    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            if (dados[j] > dados[j + 1]) {
                temp = dados[j];
                dados[j] = dados[j + 1];
                dados[j + 1] = temp;
            }
        }
    }

    printf("Digite o valor para buscar: ");
    scanf("%d", &alvo);

    while (inicio <= fim) {
        meio = (inicio + fim) / 2;
        if (dados[meio] == alvo) {
            encontrado = meio;
            break;
        } else if (dados[meio] < alvo) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }

    if (encontrado != -1) {
        printf("Valor encontrado na posicao %d do vetor ordenado.\n", encontrado);
    } else {
        printf("Valor nao encontrado.\n");
    }

    return 0;

}

void exercicio16() {
    int votos[] = {3, 1, 4, 2, 5, 3, 2, 1, 4};
    int tamanho = 9;
    int candidato_buscado;
    int ocorrencias = 0;

    printf("Digite o numero do candidato: ");
    scanf("%d", &candidato_buscado);

    for (int i = 0; i < tamanho; i++) {
        if (votos[i] == candidato_buscado) {
            ocorrencias++;
        }
    }

    printf("O candidato %d recebeu %d voto(s).\n", candidato_buscado, ocorrencias);

    return 0;
}

void exercicio17() {
    int temperaturas[] = {15, 17, 19, 21, 23, 25, 27, 30};
    int tamanho = 8;
    int temp_buscada;
    int inicio = 0, fim = tamanho - 1, meio;
    int encontrada = -1;

    printf("Digite a temperatura a ser buscada: ");
    scanf("%d", &temp_buscada);

    while (inicio <= fim) {
        meio = (inicio + fim) / 2;

        if (temperaturas[meio] == temp_buscada) {
            encontrada = meio;
            break;
        } else if (temperaturas[meio] < temp_buscada) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }

    if (encontrada != -1) {
        printf("Temperatura %d registrada na posicao: %d\n", temp_buscada, encontrada);
    } else {
        printf("Temperatura nao registrada.\n");
        printf("Para manter a ordenacao, ela poderia ser inserida na posicao: %d\n", inicio);
    }

    return 0;
}

void exercicio18() {
    int filmes[] = {501, 123, 876, 234, 654, 345, 999};
    int tamanho = 7;
    int filme_buscado;
    int encontrado = -1;
    int verificacoes = 0;

    printf("Digite o ID do filme: ");
    scanf("%d", &filme_buscado);

    for (int i = 0; i < tamanho; i++) {
        verificacoes++;
        if (filmes[i] == filme_buscado) {
            encontrado = i;
            break;
        }
    }

    if (encontrado != -1) {
        printf("Filme encontrado na posicao: %d\n", encontrado);
    } else {
        printf("Filme nao encontrado.\n");
        printf("Total de elementos verificados: %d\n", verificacoes);
    }

    return 0;
}

void exercicio19() {
    int vetor[] = {12, 45, 12, 67, 89, 45, 23};
    int tamanho = 7;

    printf("Valores duplicados encontrados:\n");

    for (int i = 0; i < tamanho; i++) {
        int ja_checado = 0;
        for (int k = 0; k < i; k++) {
            if (vetor[k] == vetor[i]) {
                ja_checado = 1;
                break;
            }
        }
        
        if (ja_checado) {
            continue;
        }

        int contagem = 1;
        for (int j = i + 1; j < tamanho; j++) {
            if (vetor[i] == vetor[j]) {
                contagem++;
            }
        }

        if (contagem > 1) {
            printf("- %d (aparece %d vezes)\n", vetor[i], contagem);
        }
    }

    return 0;
}

/*

Exercicio 20:

A busca sequencial em um conjunto de dados que cresce constantemente faria o sistema colapsar rapidamente, pois cada busca exigiria 
percorrer os dados um a um. A busca binária reduz esse tempo drasticamente 
para frações de milissegundo.

*/

void exercicio21() {
    int historico[] = {321, 105, 876, 432, 210, 654, 999, 111};
    int tamanho = 8;
    int pagina_buscada;
    int comparacoes = 0;
    int posicao = -1;

    printf("Digite o ID da pagina para busca: ");
    scanf("%d", &pagina_buscada);

    for (int i = 0; i < tamanho; i++) {
        comparacoes++;
        if (historico[i] == pagina_buscada) {
            posicao = i;
            break; 
        }
    }

    if (posicao != -1) {
        printf("Pagina encontrada na posicao: %d\n", posicao);
    } else {
        printf("Pagina nao visitada.\n");
    }
    printf("Numero de comparacoes realizadas: %d\n", comparacoes);

    return 0;
}

void exercicio22() {
    int transacoes[] = {1001, 1020, 1055, 1100, 1200, 1300, 1500};
    int tamanho = 7;
    int codigo_buscado;
    int inicio = 0, fim = tamanho - 1, meio;
    int encontrado = -1;

    printf("Digite o codigo da transacao: ");
    scanf("%d", &codigo_buscado);

    while (inicio <= fim) {
        meio = (inicio + fim) / 2;
        printf("Iteracao -> Inicio: %d | Meio: %d | Fim: %d\n", inicio, meio, fim);

        if (transacoes[meio] == codigo_buscado) {
            encontrado = meio;
            break;
        } else if (transacoes[meio] < codigo_buscado) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }

    if (encontrado != -1) {
        printf("Transacao encontrada no indice %d.\n", encontrado);
    } else {
        printf("Transacao nao encontrada.\n");
    }

    return 0;
}

void exercicio23() {
    int vendas[] = {10, 25, 10, 30, 45, 25, 60, 10};
    int tamanho = 8;
    int produto_buscado;
    int encontrou_algum = 0;

    printf("Digite o ID do produto vendido: ");
    scanf("%d", &produto_buscado);

    printf("Posicoes onde o produto %d aparece: ", produto_buscado);
    for (int i = 0; i < tamanho; i++) {
        if (vendas[i] == produto_buscado) {
            printf("%d ", i);
            encontrou_algum = 1;
        }
    }

    if (!encontrou_algum) {
        printf("Nenhuma (produto nao encontrado).");
    }
    printf("\n");

    return 0;
}

void exercicio24() {
    int vetor[] = {5, 15, 25, 35, 45, 55};
    int tamanho = 6;
    int novo_valor;
    int inicio = 0, fim = tamanho - 1, meio;

    printf("Digite o novo valor a ser inserido: ");
    scanf("%d", &novo_valor);

    while (inicio <= fim) {
        meio = (inicio + fim) / 2;

        if (vetor[meio] == novo_valor) {
            inicio = meio; 
            break;
        } else if (vetor[meio] < novo_valor) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }

    printf("O valor %d deve ser inserido no indice: %d\n", novo_valor, inicio);

    return 0;
}

void exwercicio25() {
    int vetor[] = {77, 12, 89, 34, 56, 23, 90};
    int tamanho = 7;
    int valor_buscado;
    int verificacoes = 0;
    int encontrado = 0;

    printf("Digite o valor para busca: ");
    scanf("%d", &valor_buscado);

    for (int i = 0; i < tamanho; i++) {
        verificacoes++;
        if (vetor[i] == valor_buscado) {
            encontrado = 1;
            break; 
        }
    }

    if (encontrado) {
        printf("Valor encontrado!\n");
    } else {
        printf("Valor nao encontrado.\n");
    }
    printf("Total de verificacoes necessarias: %d\n", verificacoes);

    return 0;
}

/*

Exercicio 26:

O melhor cenário ocorre quando o elemento procurado é exatamente o primeiro do vetor (índice 0). O algoritmo faz 1 operação, 
encontra o alvo e encerra. Complexidade: O(1).
O pior cenário ocorre quando o elemento procurado é o último do vetor (índice 499) ou simplesmente não existe no vetor. 
O algoritmo será forçado a percorrer o array inteiro, de ponta a ponta, realizando 500 operações. Complexidade: O(N).

*/

// Exercicio 27: ===============

int busca_iterativa(int vetor[], int tamanho, int alvo) {
    int inicio = 0, fim = tamanho - 1, meio;
    while (inicio <= fim) {
        meio = (inicio + fim) / 2;
        if (vetor[meio] == alvo) return meio;
        if (vetor[meio] < alvo) inicio = meio + 1;
        else fim = meio - 1;
    }
    return -1;
}

// 2. Abordagem Recursiva (chamando a propria funcao)
int busca_recursiva(int vetor[], int inicio, int fim, int alvo) {
    if (inicio > fim) return -1;
    
    int meio = (inicio + fim) / 2;
    if (vetor[meio] == alvo) return meio;
    if (vetor[meio] < alvo) return busca_recursiva(vetor, meio + 1, fim, alvo);
    return busca_recursiva(vetor, inicio, meio - 1, alvo);
}

void exercicio27() {
    int vetor[] = {2, 4, 6, 8, 10, 12, 14, 16};
    int tamanho = 8;
    int alvo = 10;

    printf("Indice (Iterativa): %d\n", busca_iterativa(vetor, tamanho, alvo));
    printf("Indice (Recursiva): %d\n", busca_recursiva(vetor, 0, tamanho - 1, alvo));

    return 0;
}

// =====================================

void exercicio28() {
    int vetor[] = {11, 22, 33, 44, 55, 66, 77};
    int tamanho = 7;
    int alvo = 40; 
    int inicio = 0, fim = tamanho - 1, meio;

    printf("Buscando o valor: %d\n", alvo);

    while (inicio <= fim) {
        meio = (inicio + fim) / 2;
        printf("Etapa -> Inicio: %d, Meio: %d, Fim: %d (Avaliando vetor[%d] = %d)\n", 
               inicio, meio, fim, meio, vetor[meio]);

        if (vetor[meio] == alvo) {
            printf("Encontrado!\n");
            return 0;
        } else if (vetor[meio] < alvo) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }

    printf("\nBusca encerrada. Condicao de parada atingida: inicio (%d) > fim (%d).\n", inicio, fim);
    printf("O valor %d nao esta no vetor.\n", alvo);

    return 0;
}

/*

Exercicio 29:

A Busca Sequencial seria lenta demais para um sistema onde a busca precisa ser extremamente rápida em grandes volumes de dados.
A solução técnica ideal na prática é o uso de uma Hash Table, que permite buscas, inserções e deleções em tempo médio 
quase instantâneo (O(1)), independente da ordenação.
*/

/*

Exercicio 30:

I - Falsa. Se o vetor for muito pequeno, por ex: 3 elementos, o custo computacional de calcular o meio e gerenciar os ponteiros da busca binária 
pode ser milissegundos mais lento do que simplesmente olhar os 3 itens sequencialmente.
II - Verdadeira. A busca sequencial testa item por item, do início ao fim. independente da ordenação do algoritmo.
III - Verdadeira. A premissa central da busca binária é descartar metade do espaço de busca a cada iteração.
*/



