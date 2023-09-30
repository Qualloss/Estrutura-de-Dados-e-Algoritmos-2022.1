"# Estrutura-de-Dados-e-Algoritmos-2022.1" 

Questões:

  Prova 1:
  
    Questão 01 - Lista Encadeada Simples 
      
      Seu código deve:

      Implementar a estrutura de dados lista encadeada simples incluindo, minimamente, as funções listadas abaixo;
      NewList(...) - Inicia uma lista vazia;
      Append(...) - Adiciona elemento ao final da lista;
      Insert(...) - Adiciona elemento em uma posição específica da lista;
      Display(...) - Imprime todos os elementos da lista;
      FreeList(...) - Apaga todos elementos da lista;
      Ler dois vetores e armazená-los em listas encadeadas separadas (ex.: "struct list *lista1, *lista2;");
      Os vetores deverão ser armazenados em suas respectivas listas com "Append(...)";
      As listas devem estar ordenadas da mesma forma que os vetores de entrada.
      Implementar uma função que insere a segunda lista em um determinado ponto da primeira lista;
      Inserir a segunda lista na primeira e imprimir o resultado;
      Implementar uma função que remove os valores repetidos de uma lista, mantendo apenas a primeira ocorrência;
      Remover os valores repetidos da junção das listas e imprimir o resultado.
      Seu código deve ler o seguinte modelo de entrada:

      3           // Quantidade de linhas a seguir.
      0 1 2 3 4 5
      0 9 8 0 0
      4           // Posição para inserção.
      Seu código deve ter o seguinte modelo de saída:

      0 1 2 3 0 9 8 0 0 4 5   // Print após inserção
      0 1 2 3 9 8 4 5         // Print após remoção de valores repetidos

    Questão 02 - Lista Duplamente Encadeada Não-Circular

      Seu código deve:

      Implementar a estrutura de dados lista duplamente encadeada não-circular incluindo, minimamente, as funções listadas abaixo;
      NewList(...) - Inicia uma lista vazia;
      Append(...) - Adiciona elemento ao final da lista;
      Display(...) - Imprime todos os elementos da lista;
      FreeList(...) - Apaga todos elementos da lista;
      Ler dois vetores e armazená-los em listas encadeadas separadas (ex.: "struct list *lista1, *lista2;");
      Os vetores deverão ser armazenados em suas respectivas listas com "Append(...)";
      As listas devem estar ordenadas da mesma forma que os vetores de entrada.
      Implementar uma função que procura os elementos da segunda lista na primeira e retorna uma terceira lista composta pelo caminho percorrido nessa procura;
      Assuma que a primeira lista sempre estará ordenada;
      Seu algoritmo deve procurar através do melhor caminho sempre;
      Você deve armazenar os valores toda vez que houver uma comparação;
      Você dever imprimir a lista resultante com o caminho percorrido.
      Seu código deve ler o seguinte modelo de entrada:
      
      2           // Quantidade de linhas a seguir.
      3 4 5 7 8
      1 10 6 4
      Seu código deve ter o seguinte modelo de saída:
      
      3 3 4 5 7 8 8 7 5 5 4

    Questão 03 - Lista Encadeada Simples Circular

      A turma de estrutura de dados decidiu se reunir no final do semestre para se conhecer. Como muitos gostavam de futebol, montaram dois times com 8 alunos cada e começaram a jogar. Um aluno que chegou atrasado para a reunião gritou: "20 minutos, 3 gols!". Após 20         minutos, o time perdedor teve que escolher alguém para sair. Como o assunto de lista ligadas ainda estava fresco na memória, decidiram fazer um círculo e utilizar esse conceito. Cada um falou um número de 0 a 10, somaram todos eles e escolheram alguém para              iniciar a contagem no sentido horário. A partir desse estudante, contaram até chegar na soma total. A pessoa em que a contagem acabar será quem dará lugar ao estudante que chegou depois.

      Seu código deve:
      
      Implementar a estrutura de dados lista encadeada circular incluindo, minimamente, as funções listadas abaixo;
      NewList(...) - Inicia uma lista vazia;
      Append(...) - Adiciona elemento ao final da lista;
      FreeList(...) - Apaga todos elementos da lista.
      Sua lista deve armazenar o nome e o valor que cada integrante falou;
      O vetor deve ser armazenado com "Append(...)";
      A lista deve estar ordenada da mesma forma que o vetor de entrada.
      Implementar uma função que percorre uma lista encadeada circular;
      Inicie a contagem em 0;
      Percorra a lista até alcançar o valor total;
      Imprima o nome da pessoa escolhida.
      Seu código deve ler o seguinte modelo de entrada:
      
      9           // Quantidade de linhas a seguir
      Ricardo 3
      Ariel 0
      Izak 2
      Jean 3
      Julia 5
      Mateus 8
      Felipe 1
      Luiz 2
      Ricardo     // Pessoa escolhida para iniciar a contagem
      Seu código deve ter o seguinte modelo de saída:
      
      Ricardo

    Questão 04 - Lista Encadeada Simples Circular & Pilha

      Seu código deve:

      Implementar a estrutura de dados lista encadeada circular incluindo, minimamente, as funções listadas abaixo;
      NewList(...) - Inicia uma lista vazia;
      Append(...) - Adiciona elemento ao final da lista;
      Pop(...) - Remove e retorna um elemento da lista;
      FreeList(...) - Apaga todos elementos da lista;
      Implementar a estrutura de dados pilha incluindo, minimamente, as funções listadas abaixo;
      NewStack(...) - Inicia uma pilha vazia;
      Push(...) - Adiciona elemento no topo da pilha;
      Pop(...) - Remove e retorna o elemento do topo da pilha;
      Display(...) - Imprime todos os elementos da pilha;
      FreeStack(...) - Apaga todos elementos da pilha utilizando pop;
      Ler um vetor e armazená-lo em uma lista encadeada circular;
      O vetor deve ser armazenado com "Append(...)";
      A lista deve estar ordenada da mesma forma que o vetor de entrada.
      Implementar uma função que procura o próximo maior elemento da lista, remove-o e o adiciona a uma pilha que deve ser retornada;
      A primeira pesquisa deve começar no primeiro valor da lista (o primeiro valor do vetor recebido);
      Ao chegar ao final da lista, você deve continuar até encontrar o valor novamente e removê-lo;
      A partir desse momento, as novas pesquisas não necessariamente iniciarão no primeiro valor, mas sim de onde você removeu o último;
      Você deve contar a quantidade de voltas feitas na lista e imprimir esse valor quando a lista estivar vazia;
      Você deve retornar a pilha resultante (que estará ordenada com os menores valores no topo e maiores na base);
      Você dever imprimir a pilha resultante.
      Seu código deve ler o seguinte modelo de entrada:
      
      1           // Quantidade de linhas a seguir.
      5 0 7 2 4
      Seu código deve ter o seguinte modelo de saída:
      
      5           // Quantidade de voltas realizadas
      0 2 4 5 7   // Valores nas ordem armazenada na pilha.

    Questão 05 - Pilha

      Seu código deve:
  
      Implementar a estrutura de dados pilha incluindo, minimamente, as funções listadas abaixo;
      NewStack(...) - Inicia uma pilha vazia;
      Push(...) - Adiciona elemento no topo da pilha;
      Pop(...) - Remove e retorna o elemento do topo da pilha;
      Display(...) - Imprime todos os elementos da pilha;
      FreeStack(...) - Apaga todos elementos da pilha utilizando pop;
      Ler dois vetores e armazená-los em pilhas separadas (ex.: "struct stack *pilha1, *pilha2;");
      Os vetores deverão ser armazenados em suas respectivas pilhas com "Push(...)";
      As pilhas resultantes resultantes devem estar ordenadas da mesma forma que o vetor de entrada (primeiro valor na base, último valor no topo).
      Implementar uma função que empilhe a segunda pilha na primeira sem alterar a ordem das mesmas;
      Utilize apenas pilhas.
      Você dever imprimir a pilha resultante.
      Seu código deve ler o seguinte modelo de entrada:
      
      2           // Quantidade de linhas a seguir.
      1 2 3 4 5
      6 7 8 9 0
      Seu código deve ter o seguinte modelo de saída:
      
      0
      9
      8
      7
      6
      5
      4
      3
      2
      1

    Questão 06 - Pilha

      Seu código deve:

      Implementar a estrutura de dados pilha incluindo, minimamente, as funções listadas abaixo;
      NewStack(...) - Inicia uma pilha vazia;
      Push(...) - Adiciona elemento no topo da pilha;
      Pop(...) - Remove e retorna o elemento do topo da pilha;
      FreeStack(...) - Apaga todos elementos da pilha utilizando pop;
      Ler um vetor e armazená-lo em uma pilha;
      O vetor deve ser armazenado com "Push(...)";
      A pilha resultante deve estar ordenada da mesma forma que o vetor de entrada (primeiro valor na base, último valor no topo).
      Implementar uma função que utilize 3 pilhas e transfira os elementos da primeira pilha para a terceira utilizando a segunda como auxiliar;
      Utilize apenas pilhas.
      A primeira pilha sempre estará ordenada (maior valor na base, menor no topo);
      Você nunca deve empilhar um valor maior sobre um valor menor;
      Utilize o método mais eficiente (cuidado com plágios);
      Você dever imprimir quantos passos foram necessários para mover a primeira pilha para a terceira.
      Seu código deve ler o seguinte modelo de entrada:
      
      1       // Quantidade de linhas a seguir
      2 1
      O que seu código deve simular:
      
      1   |   |
      2   |   |
      
      1º
      |   |   |
      2   1   |
      
      2º
      |   |   |
      |   1   2
      
      3º
      |   |   1
      |   |   2
      Seu código deve ter o seguinte modelo de saída:
      
      3

    Questão 07 - Pilhas & Filas

      Seu código deve:
  
      Implementar a estrutura de dados pilha incluindo, minimamente, as funções listadas abaixo;
      NewStack(...) - Inicia uma pilha vazia;
      Push(...) - Adiciona elemento no topo da pilha;
      Pop(...) - Remove e retorna o elemento do topo da pilha;
      Display(...) - Imprime todos os elementos da pilha;
      FreeStack(...) - Apaga todos elementos da pilha utilizando pop;
      Implementar a estrutura de dados fila incluindo, minimamente, as funções listadas abaixo;
      NewQueue(...) - Inicia uma fila vazia;
      Append(...) - Adiciona elemento no final da fila;
      Pop(...) - Remove e retorna o elemento na frente da fila;
      Display(...) - Imprime todos os elementos da fila;
      FreeQueue(...) - Apaga todos elementos da fila utilizando pop;
      Ler dois vetores e armazená-los em pilhas separadas (ex.: "struct stack *pilha1, *pilha2;");
      Os vetores deverão ser armazenados em suas respectivas pilhas com "Push(...)";
      As pilhas resultantes resultantes devem estar ordenadas da mesma forma que o vetor de entrada (primeiro valor na base, último valor no topo).
      Imprima as pilhas de acordo a representação abaixo (base na esquerda, topo na direita).
      Transferir os elementos da pilha para filas separadas (ex.: "struct queue *fila1, *fila2;");
      Os vetores deverão ser armazenados em suas respectivas filas com "Append(...)";
      As filas resultantes devem estar ordenadas da mesma forma que o vetor de entrada (primeiro valor na frente, último valor no final);
      Utilize pilhas para alcançar isso (dica: simule uma fila utilizando pilhas);
      Imprima as filas.
      Implementar uma função que recebe 2 filas e retorne uma terceira fila que intercala os valores das duas primeiras.
      Utilize apenas filas;
      Valores da primeira fila primeiro;
      A fila maior terá seus últimos elementos no final;
      Imprima a fila resultante;
      Seu código deve ler o seguinte modelo de entrada:
      
      2           // Quantidade de linhas a seguir.
      0 2 4 6 8 10 12
      1 3 5 7 9
      Seu código deve ter o seguinte modelo de saída:
      
      0 2 4 6 8 10 12
      1 3 5 7 9
      0 2 4 6 8 10 12
      1 3 5 7 9
      0 1 2 3 4 5 6 7 8 9 10 12
  

    Questão 08 - Fila

      Na última semana, a fila de entrada de um certo evento ficou extraordinariamente grande. Os organizadores perceberam que algumas pessoas necessárias para evento acontecer estavam presas nessa fila. Além disso, perceberam também uma certa quantidade de idosos e         grávidas ao longo da mesma.

      Para evitar que essa situação se repita, a equipe que organiza eventos como esse decidiu pedir à turma de estrutura de dados da UFBA para escrever um programa para auxiliá-los. Eles preferiram que esse programa fosse acionado manualmente toda vez que eles              julgassem que a fila precisasse ser organizada. O programa deve dividir a fila em duas:
      
      Não prioridade.
      Prioridade: a partir de 60 anos, até 5 anos, grávidas e palestrantes.
      Grávidas e palestrantes serão especificados pela posição na fila.
      Seu código deve:
      
      Implementar a estrutura de dados fila incluindo, minimamente, as funções listadas abaixo;
      NewQueue(...) - Inicia uma fila vazia;
      Append(...) - Adiciona elemento no final da fila;
      Pop(...) - Remove e retorna o elemento da frente (que está no início) da fila;
      Display(...) - Imprime todos os elementos da fila;
      FreeQueue(...) - Apaga todos elementos da fila utilizando pop;
      Ler um vetor e armazená-lo em uma fila;
      O vetor deve ser armazenado na fila com "Append(...)";
      A fila resultante deve estar ordenada da mesma forma que o vetor de entrada (primeiro valor na frente, último valor no final);
      Transferir os elementos dentro das especificações para uma fila separada;
      Todas as operações de transferência de fila deverão ser realizadas utilizando filas: Pop(...)" para remover da fila inicial, "Append(...)" para adicionar na fila auxiliar/final;
      As filas resultantes devem estar ordenadas da mesma forma que o vetor de entrada (primeiro valor na frente, último valor no final);
      Imprima as filas.
      Seu código deve ler o seguinte modelo de entrada:
      
      2           // Quantidade de linhas a seguir.
      50 65 30 33 11 3 25 39 17 22 27 26 44 28 53 28 20 70 58 27 33 36 49 17  // Vetor de idades
      7 8 14      // Vetor com a posição das grávidas e palestrantes na fila
      Seu código deve ter o seguinte modelo de saída:
      
      50 30 33 11 17 22 27 26 44 53 28 20 58 27 33 36 49 17 // Fila original sem os preferenciais
      65 3 25 39 28 70            // Fila preferencial

  Prova 2:

    Questão 01 - Selection Sort
    
      Implemente um algoritmo que recebe a seguinte entrada:

      7
      3
      10
      5
      9
      8
      1
      3
      A primeira linha informa quantas linhas você deve ler na sequência para executar o seu código. A segunda linha informa o número máximo de iterações que seu código deve executar. As demais linhas são os dados que precisam ser ordenados. Em seguida, seu                  algoritmo deve retornar os dados (10 5 9 8 1 3) ordenados usando o algoritmo de Seleção até a iteração 3 (segunda linha).
      
      Exemplo:
      
      Dados de entrada: 10 5 9 8 1 3
      Iteração 01:
      1 5 9 8 10 3
      Iteração 02:
      1 3 9 8 10 5
      Iteração 03:
      1 3 5 8 10 9 (retorno da função)
      
    Questão 02 - Insertion Sort

      Repita o exercício anterior, mas implementando o algoritmo de ordenação por inserção. Exemplo:

      Dados de entrada: 10 5 9 8 1 3
      Iteração 01:
      10
      Iteração 02:
      5 10
      Iteração 03:
      5 9 10 (retorno da função)

    Questão 03 - Bubble Sort

      Repita o exercício anterior, agora implementando o algoritmo de ordenação Bubblesort. Exemplo:

      Dados de entrada: 10 5 9 8 1 3
      Iteração 01:
      5 9 8 1 3 10
      Iteração 02:
      5 8 1 3 9 10
      Iteração 03:
      5 1 3 8 9 10 (retorno da função)

    Questão 04 - Quicksort

      Implemente o algoritmo de ordenação Quicksort, considerando a seguinte entrada:

      8
      1
      10
      5
      9
      8
      1
      3
      2
      
      A primeira linha informa quantas linhas você deve ler na sequência para executar o seu código. A segunda linha informa qual é a posição (começando da posição 0) do elemento que deve ser usado como pivô na primeira iteração. Nas iterações seguintes, o primeiro          valor deve ser escolhido. As demais linhas são os dados que precisam ser ordenados. Seu algoritmo deve executar todas as etapas do algoritmo e imprimir os dois próximos pivôs e o resultado final da ordenação. Exemplo:
      
      Dados de entrada: 10 5 9 8 1 3 2
      Iteração 01:
      [ 1 3 2 5 10 9 8 ]
      Iteração 02:
      [1 3 2] 5 [10 9 8]
      (…)
      Resultado final: 1 10 1 2 3 5 8 9 10

  
