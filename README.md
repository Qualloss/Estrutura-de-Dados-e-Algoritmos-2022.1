"# Estrutura-de-Dados-e-Algoritmos-2022.1" 

Questões:
  Prova 1:
    Q1: 
      
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
