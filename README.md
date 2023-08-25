# Trabalho de Aquecimento: Top K Elementos

Um exemplo clássico de problema que pode ser solucionado utilizando-se _hash_ e heap é o chamado top _k_ itens. Neste problema, é preciso encontrar os _k_ itens mais valiosos de uma coleção de dados. Logo, utiliza-se o hash para contar a frequência de todos os itens, enquanto o heap se aplica na manutenção de uma lista dos _k_ itens de maior valor. Sabendo-se disso, foi elaborada uma solução em _C++_ que dado uma entrada:

- Cria uma tabela de dispersão (_hash_) para contar a frequência de cada elemento tokenizado da coleção de dados de entrada.
- Cria uma árvore de prioridades (_heap_) de tamanho _k_ e insira os primeiros _k_ elementos do
hash nela.

1. Para cada elemento restante na hash, compare a contagem com o menor valor do heap.
2. Se a contagem for maior do que o menor valor da heap, remova o menor valor, insira o novo elemento e refaça a estrutura.
3. Caso contrário, ignore o elemento e vá para o próximo.

- No final, a heap conterá os _k_ elementos com maiores valores (frequências) da coleção de dados. Então, imprima-os em ordem crescente.

Esse algoritmo é uma combinação eficiente do uso de hash para contar a frequência dos elementos e heap para manter a lista dos _k_ elementos com maiores valores. Sua complexidade, caso implementado adequadamente, é de _O(nlogk)_, onde n é o tamanho da coleção de dados e _k_ o número de itens mais relevantes.

### O que é um contador de palavras?

Um contador de palavras é uma ferramenta que é usada para contar o número de palavras em um texto ou documento. É uma ferramenta comumente usada por escritores, estudantes, professores e editores para monitorar a quantidade de palavras em um trabalho escrito, como um ensaio, artigo, tese ou relatório.

Os contadores de palavras podem ser programas ou ferramentas online que contam automaticamente o número de palavras em um documento ou texto digitado. Algumas ferramentas mais avançadas também podem fornecer informações adicionais, como a contagem de caracteres, parágrafos e frases.

O uso de um contador de palavras pode ajudar os usuários a manter o controle do comprimento de um documento e a garantir que atendam aos requisitos de comprimento específicos de um projeto ou tarefa. Além disso, a contagem de palavras pode ser útil para avaliar a densidade do conteúdo, determinando a quantidade de informações que o autor conseguiu incluir em um espaço limitado.

## Considerações
- Este programa deverá ler uma coleção de arquivos contento textos sem nenhuma formatação ("arquivo ASCII") onde cada sentença termina por um sinal de pontuação (".",
"?", "!"").
- Cada parágrafo é separado por, pelo menos, uma linha em branco.
- Considere como palavra uma sequência de letras delimitada por espaço em branco, ”coluna da esquerda”, ”coluna da direita” e símbolos de pontuação.
- Faz parte do projeto do seu programa fornecer uma saída legível.
- Os arquivos a serem utilizados para teste serão disponibilizados junto a essa descrição e devem ser utilizados para quaisquer validações, não sendo necessário a adoção de mais entradas para esse processo.
- A documentação detalhando todo o processo de desenvolvimento deve ser produzida como README.mb e disponibilizada no git junto com o projeto.

## Heap

A estrutura de dados conhecida como _heap_ binário é um arranjo que pode ser visualizado como uma árvore binária praticamente completa. Cada nodo presente na árvore corresponde a um elemento no arranjo. A árvore é preenchida completamente em todos os níveis, exceto possivelmente o nível mais inferior, que é preenchido da esquerda até um certo ponto. Um arranjo, denotado como _A_, utilizado para representar um _heap_, é composto por dois atributos: _A.length_, que indica o número de elementos no arranjo, e _A.heap-size,_ que representa a quantidade de elementos do _heap_ que estão armazenados no arranjo _A_.

Dito de outra forma, embora _A[1..A.length]_ possa conter números, somente os elementos em _A[1..A.heap-size]_, onde _0_ ≤ _A.heap-size_ ≤ _A.length_, são considerados elementos válidos do heap. O topo da árvore corresponde a _A[1]_. Dado o índice _i_ de um nó, é simples calcular os índices do seu pai, filho esquerdo e filho direito.

```
PARENT(i)
return [i/2]

LEFT(i)
return [2i]

RIGHT(i)
return [2i + 1]
```

Para determinar o filho esquerda, é possível pode calcular _2i_ em uma única instrução, simplesmente alterando a representação binária de _i_, movendo um bit para a esquerda. Da mesma forma, para encontrar o filha da direita, pode-se calcular rapidamente _2i + 1_ alterando a representação binária de _i_, movendo um bit para a esquerda e incrementando um bit menos significativo. A fim de determinar o pai, desloca-se _i_ um bit para a direitapor.

Existem dois tipos de heaps binários: _max-heaps_ e _min-heaps_. Em ambos os tipos, os valores armazenados nos nós satisfazem uma propriedade de _heap_, cujos detalhes dependem do tipo de _heap_.

Em um _max-heap_, a propriedade chave é que para todo nó _i_, com exceção da raiz, vale que _A[Parent(i)]_ ≥ _A[i]_. Isso significa que o valor de um nó não excede o valor de seu pai. Assim, o maior elemento em um _max-heap_ é guardado no nó raiz, e a subárvore enraizada em qualquer nó contém valores que não são maiores do que aqueles presentes no próprio nó. Um _min-heap_ segue uma lógica inversa: a propriedade fundamental é que para todo nó i diferente da raiz, temos _A[Parent(i)]_ ≤ _A[i]_.

Ao representar um _heap_ como uma árvore, a altura de um nó dentro do _heap_ é definida como o número de arestas no caminho mais longo que desce do nó até uma folha. A altura do _heap_, por sua vez, é definida como a altura de sua raiz. Dado que um _heap_ com _n_ elementos é construído com base em uma árvore binária completa, sua altura é limitada por _Θ(lg n)_. As operações fundamentais em _heaps_ operam com uma complexidade de tempo proporcional à altura da árvore, resultando em um limite de _O(lg n)_ para a execução.

Para manter a propriedade de _max-heap_, utiliza-se o procedimento chamado _MAX-HEAPIFY_. Esse procedimento recebe como entrada uma matriz _A_ e um índice _i_ na matriz. Ao ser invocado, a função _MAX-HEAPIFY_ assume que as árvores binárias enraizadas nos índices _LEFT.i_ e _RIGHT.i_ são _max-heaps_, mas que o valor em _A[i]_ pode ser menor do que seus filhos, violando, assim, a propriedade de _max-heap_. Através da execução do procedimento _MAX-HEAPIFY_, permite-se que o valor presente em _A[i]_ "flua para baixo" na estrutura do _max-heap_, de modo que a subárvore enraizada no índice _i_ se ajuste à propriedade de _max-heap_.

```
MAX-HEAPIFY(A, i)
1 l D LEFT(i)
2 r D RIGHT(i)
3 if l <= A:heap-size and A[l] > A[i]
4    largest = l
5 else largest = i
6 if r <= A.heap-size and A[r] > A[largest]
7    largest = r
8 if largest != i
9    exchange A[i] with A[largest]
10   MAX-HEAPIFY(A, largest)
```

Em cada passo do procedimento, determina-se qual dos elementos entre _A[i]_, _A[LEFT(i)]_ e _A[RIGHT(i)]_ é o maior, e armazenamos seu índice na variável 'maior'. Se _A[i]_ for o maior, então a subárvore enraizada no nó _i_ já é um max-heap e o procedimento é concluído. No entanto, se um dos filhos possuir o maior valor, realizamos uma troca entre _A[i]_ e _A[largest]_, efetivamente fazendo com que o nó _i_ e seus filhos satisfaçam a propriedade de _max-heap_. É importante notar que o nó indexado por 'maior' agora contém o valor original de _A[i]_. Portanto, a subárvore enraizada em 'maior' pode não mais obedecer à propriedade de _max-heap_. Isso nos leva a chamar o procedimento _MAX-HEAPIFY_ recursivamente nessa subárvore, assegurando que ela se ajuste à propriedade de _max-heap_.

O tempo de execução do procedimento _MAX-HEAPIFY_ em uma subárvore de tamanho _n_, enraizada em um determinado nó _i_, é o tempo constante _Θ(1)_ para corrigir as relações entre os elementos _A[i]_, _A[LEFT(i)]_, e _A[RIGHT(i)]_, acrescido do tempo para executar _MAX-HEAPIFY_ em uma subárvore enraizada em um dos filhos do nó _i_ (assumindo que a chamada recursiva ocorre). As subárvores filhas têm tamanho no máximo _2n/3_ — o pior caso ocorre quando o nível inferior da árvore está exatamente meio cheio. Dessa forma, podemos descrever o tempo de execução do _MAX-HEAPIFY_ por meio da recorrência _T(n) ≤ T(2n/3) + Θ(1)_.

A solução para essa recorrência, utilizando o caso 2 do Teorema Mestre, resulta em _T(n) = O(lg n)_. De forma alternativa, é possível descrever o tempo de execução do _MAX-HEAPIFY_ em um nó com altura _h_ como sendo _O(h)_.

O procedimento MAX-HEAPIFY pode ser utilizado de baixo para cima para converter um matriz _A[1.. n]_, onde _n = A.length_, em um _max-heap_. Os elementos na submatriz _A[([n/2] + 1).. n]_ são todas folhas da árvore, e assim cada uma é um _heap_ de 1 elemento. O procedimento pelo qual passa o _BUILD-MAX-HEAP_ os nós restantes da árvore e executa _MAX-HEAPIFY_ em cada um.

```
BUILD-MAX-HEAP(A)
1 A.heap-size = A.length
2 for i = [A.length/2] downto 1
3   MAX-HEAPIFY(A, i)
```

O custo do _BUILD-MAX-HEAP_ é _O(n)_. Sendo assim, é possível afirmar que a construção de um heap possui custo linear.

É possível construir um _min-heap_ pelo procedimento _BUILD-MIN-HEAP_, que é o o mesmo que _BUILD-MAX-HEAP_ mas com a chamada para _MAX-HEAPIFY_ na linha 3 substituída por uma chamada para _MIN-HEAPIFY_. _BUILD-MIN-HEAP_ produz um _min-heap_ de uma matriz linear não ordenada em tempo linear.

```
       1114
     /      \
   768      612
   / \      / \
 610 751  537 581
 / \ / \  / \ / \
..................
```
