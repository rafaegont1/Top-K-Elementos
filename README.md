<div style="display: inline-block;">
    <img align="center" height="20px" width="50px" src="https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white"/>
    <img align="center" height="20px" width="80px" src="https://badgen.net/badge/license/MIT/green"/>
    <img align="center" height="20px" width="60px" th="60px" src="https://img.shields.io/badge/Linux-E34F26?style=for-the-badge&logo=linux&logoColor=black"/>
</div>

# Trabalho de Aquecimento: Top K Elementos

Um exemplo clássico de problema que pode ser solucionado utilizando-se _hash_ e heap é o chamado top _k_ itens. Neste problema, é preciso encontrar os _k_ itens mais valiosos de uma coleção de dados. Logo, utiliza-se o hash para contar a frequência de todos os itens, enquanto o heap se aplica na manutenção de uma lista dos _k_ itens de maior valor. Sabendo-se disso, foi elaborada uma solução em _C++_ que dado uma entrada:

- Cria uma tabela de dispersão (_hash_) para contar a frequência de cada elemento tokenizado da coleção de dados de entrada.
- Cria uma árvore de prioridades (_heap_) de tamanho _k_ e insira os primeiros _k_ elementos do
hash nela.

  1. Para cada elemento restante na hash, compare a contagem com o menor valor do heap.
  1. Se a contagem for maior do que o menor valor da heap, remova o menor valor, insira o novo elemento e refaça a estrutura.
  1. Caso contrário, ignore o elemento e vá para o próximo.

- No final, a heap conterá os _k_ elementos com maiores valores (frequências) da coleção de dados. Então, imprima-os em ordem crescente.

Esse algoritmo é uma combinação eficiente do uso de hash para contar a frequência dos elementos e heap para manter a lista dos _k_ elementos com maiores valores. Sua complexidade, caso implementado adequadamente, é de _O(n log k)_, onde n é o tamanho da coleção de dados e _k_ o número de itens mais relevantes.

### O que é um contador de palavras?

Um contador de palavras é uma ferramenta que é usada para contar o número de palavras em um texto ou documento. É uma ferramenta comumente usada por escritores, estudantes, professores e editores para monitorar a quantidade de palavras em um trabalho escrito, como um ensaio, artigo, tese ou relatório.

Os contadores de palavras podem ser programas ou ferramentas online que contam automaticamente o número de palavras em um documento ou texto digitado. Algumas ferramentas mais avançadas também podem fornecer informações adicionais, como a contagem de caracteres, parágrafos e frases.

O uso de um contador de palavras pode ajudar os usuários a manter o controle do comprimento de um documento e a garantir que atendam aos requisitos de comprimento específicos de um projeto ou tarefa. Além disso, a contagem de palavras pode ser útil para avaliar a densidade do conteúdo, determinando a quantidade de informações que o autor conseguiu incluir em um espaço limitado.

## Considerações
- Este programa lê uma coleção de arquivos contento textos sem nenhuma formatação onde cada sentença termina por um sinal de pontuação (`.`, `,`, `?`, `!`, `:`, `;`).
- Cada parágrafo é separado por, pelo menos, uma linha em branco.
- Foram consideradas como palavras qualquer sequência de letras delimitada por espaço em branco, ”coluna da esquerda”, ”coluna da direita” e símbolos de pontuação.
- Além dos sinais de pontuação e espaços em branco, será considerado, para separar as palavras, caracteres como `'`, `"`, `(`, `)`, `\`, `/`, `-` e `\n`.
- Os arquivos a serem utilizados para teste possuem formatação `input%d.data`, onde `%d` é o número do arquivo, que começa de `1` e vai até não encontrar mais nenhum arquivo.
- O tamanho _k_ de itens valiosos é 20.

## Arquivos utilizados

- `main.cpp` é o ponto de entrada do programa, onde a sua execução começa.
- `utils.hpp` _header_ da biblioteca de utilidades, onde as definições das funções utilizadas para a construção do programa estão situadas, como a leitura dos arquivos de entrada.
- `utils.cpp` é onde o corpo das funções definidas no _header_ citado acima se encontram.

## Decisões de implementação

Primeiramente, foi necessário abrir os arquivos de entrada para leitura. Para tanto, foi alocado um espaço na memória, em um ponteiro `buffer`, do tamanho da primeira entrada, para lê-lo. O tipo do ponteiro é `wchar_t *`, pois as entradas possuem codificação especial. Então, foi lida a entrada neste ponteiro, onde cada caractere foi analisado individualmente, para determinar se o caractere analisado é um separador de palavras. Quando o caractere não é uma separador de palavras, ele é concatenado ao final de uma _string_ temporária.

Caso o seja, o programa entenderá que a _string_ temporária é uma palavra completa, e o programa irá verificar se esta _string_ é uma _stop word_. Se a palavra não o for, ela é adicionada a um `unordered_map` do tipo `<std::wstring, unsigned short>`, onde o seu valor será incrementado em um.

Para armazenar as _stop words_, foi utilizado um `unordered_set`. Se a _string_ temporária estiver neste _set_, ela não é contabilizada. A utilização, tanto do `unordered_map`, quanto do `unordered_set`, foi escolhida devido ao custo constante de O(1) de pesquisa em situações ideias.

Assim que o programa lê todas as palavras do primeiro arquivo, o espaço alocado para o ponteiro do `buffer` é liberado, e então o programa tenta abrir a entrada `input2.data`. Caso não consiga abrir, o `buffer` receberá um `nullptr`, informando ao _loop_ que todas as palavras dos arquivos de entrada já foram lidos.

Logo, é criado um iterador que aponta para o início do _map_ que contém as palavras. Os vinte primeiros itens deste iterador são armazenados em um `vector`, e então é utilizada a função `make_heap` da biblioteca padrão do _C++_. Esta função faz um _min heap_ destes vinte primeiros itens, fazendo com que o item de menor valor seja o primeiro elemento do _heap_.

O iterador então continua verificando se o item atual possui maior valor que o primeiro item do _heap_; caso o seja, este primeiro item é substituído pelo item atual do iterador, e é feito então um novo ```ncias ide`ncia`make_heap`, para garantir que o item de menor valor esteja na primeira posição. Isso continua até que o iterador chegue ao final do _map_.

Por final, é realizado um _max heap_ no _heap_, para então imprimí-lo na tela. É importante destacar que utilizou-se a biblioteca padrão do _C++_ ao máximo, devido a sua alta performance e confiabilidade. Foi considerada a realização deste presente trabalho em _C_, porém, este encontraria maior propensão a error de acesso inválido de memória e uma função _hash_ que gerasse muitas colisões, tornando o programa mais lento.

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

É possível ainda construir um _min-heap_ pelo procedimento _BUILD-MIN-HEAP_, que é o o mesmo que _BUILD-MAX-HEAP_ mas com a chamada para _MAX-HEAPIFY_ na linha 3 substituída por uma chamada para _MIN-HEAPIFY_. _BUILD-MIN-HEAP_ produz um _min-heap_ de uma matriz linear não ordenada em tempo linear.

## Tabela hash

Muitos programas requerem uma estrutura dinâmica que suporte apenas as operações de inserção, busca e exclusão a partir de uma chave, semelhantes a um dicionário. Uma tabela de dispersão (hash table) é uma estrutura de dados eficiente para implementar esses dicionários. Embora a busca por um elemento em uma tabela de hash possa levar tanto tempo quanto a busca em uma lista encadeada - O(n) no pior caso - na prática, o hashing demonstra um desempenho extremamente eficaz. Sob suposições razoáveis, o tempo médio para encontrar um elemento em uma tabela de hash é O(1).

Uma tabela de hash estende o conceito mais básico de uma matriz convencional. O acesso direto em uma matriz convencional explora eficientemente nossa capacidade de examinar qualquer posição arbitrária na matriz em tempo O(1). Podemos explorar esse acesso direto quando podemos arcar com a alocação de uma matriz que contenha uma posição para cada possível chave.

Quando o número de chaves armazenadas é significativamente menor em comparação com o total de chaves possíveis, as tabelas de hash se tornam uma alternativa eficaz para o endereçamento direto de uma matriz. Isso ocorre porque uma tabela de hash geralmente utiliza uma matriz com um tamanho proporcional ao número de chaves efetivamente armazenadas. Em vez de utilizar a chave diretamente como um índice de matriz, o índice da matriz é calculado a partir da chave.

Compilando o programa com o _GCC_, a função _hash_ para os `unordered_map` e `unordered_set` é o MurmurHash 2. Ela é uma função de _hash_ não criptográfica amplamente utilizada que oferece uma boa distribuição de valores _hash_ com um bom desempenho. Esta _hash_ foi projetado para ser rápido e eficiente em termos de tempo de execução, com uma boa dispersão de valores hash para reduzir colisões. Segue abaixo a implementação da MurmurHash 2:

```
// Implementation of Murmur hash for 32-bit size_t.
size_t _Hash_bytes(const void* ptr, size_t len, size_t seed)
{
  const size_t m = 0x5bd1e995;
  size_t hash = seed ^ len;
  const char* buf = static_cast<const char*>(ptr);

  // Mix 4 bytes at a time into the hash.
  while (len >= 4)
  {
    size_t k = unaligned_load(buf);
    k *= m;
    k ^= k >> 24;
    k *= m;
    hash *= m;
    hash ^= k;
    buf += 4;
    len -= 4;
  }

  // Handle the last few bytes of the input array.
  switch (len)
  {
    case 3:
      hash ^= static_cast<unsigned char>(buf[2]) << 16;
      [[gnu::fallthrough]];
    case 2:
      hash ^= static_cast<unsigned char>(buf[1]) << 8;
      [[gnu::fallthrough]];
    case 1:
      hash ^= static_cast<unsigned char>(buf[0]);
      hash *= m;
  };

  // Do a few final mixes of the hash.
  hash ^= hash >> 13;
  hash *= m;
  hash ^= hash >> 15;
  return hash;
}
```

Nesta implementação da MurmurHash 2, utilizada pelo compilador _GCC_, é retornado um valor do tipo `size_t` de 32 bits. Esta função recebe três parâmetros:

- `const void* ptr` um ponteiro para os dados de entrada que você deseja calcular o hash;
- `size_t len` um valor do tipo `size_t` que representa o comprimento dos dados de entrada;
- `size_t seed` um valor também do tipo `size_t` que é usado como semente inicial para o cálculo do hash.

Primeiramente, é definida a constante `size_t m = 0x5bd1e995` para ser utilizada nos cálculos da função de hash. Então, a variável `size_t hash = seed ^ len` é inicializa usando uma operação XOR entre a semente e o tamanho dos dados. Em `const char* buf = static_cast<const char*>(ptr)` o ponteiro é convertido para um ponteiro de caractere.

O _loop_ principal processa os dados em blocos de 4 _bytes_ cada. Ele aplica uma série de operações de mistura (multiplicações, _bit shifts_ e _bitwise XORs_) para calcular o hash incrementalmente.

No `switch (len)`, os últimos bytes dos dados de entrada (menos de 4 bytes) são utilizados aplicando operações _bit shift_ e _bitwise XOR_ para calcular o hash restante.

Por fim, são realizam algumas misturas finais no valor hash, utilizando também _bit shift_ e _bitwise XOR_, para então retornar o valor hash calculado.

## Casos sem tratamento

O algoritmo reconhece como fazendo parte de uma palavra qualquer caractere que não seja os já citados anteriormente. Com isso, é possível que caracteres especiais façam parte de uma palavra, fazendo com que algo que não poderia ser considerado como palavra o seja, o que é algo indesejado. Uma possível solução para este problema seria acrescentá-los à _string_ constante que define os caracteres a não serem lidos. Outra solução seria colocar estes caracteres, caso formem uma palavra por si só, na lista de _stop words_.

## Exemplo

Foi realizado um teste com dois arquivos de entrada `inputa1.data` e `input2.data`, a fim de demonstrar a saída após a execução do programa, conforme mostrado abaixo.

`input1.data`

```
Dom Casmurro

Machado de Assis

CAPÍTULO PRIMEIRO / DO TÍTULO

Uma noite destas, vindo da cidade para o Engenho Novo, encontrei num trem da Central um rapaz
aqui do bairro, que eu conheço de vista e de chapéu. Cumprimentou-me, sentou-se ao pé de mim,
falou da lua e dos ministros, e acabou recitando-me versos. A viagem era curta, e os versos pode ser
que não fossem inteiramente maus. Sucedeu, porém, que, como eu estava cansado, fechei os olhos
três ou quatro vezes; tanto bastou para que ele interrompesse a leitura e metesse os versos no bolso.

-- Continue, disse eu acordando.

-- Já acabei, murmurou ele.

-- São muito bonitos.
```

`input2.data`

```
 A semana Texto-fonte: Obra Completa de Machado de Assis. 

Rio de Janeiro: Nova Aguilar, Vol. 

III, . 

Publicado originalmente na Gazeta de Notícias, Rio de Janeiro, de // a //.   

de abril Na segunda feira da semana que findou, acordei cedo, pouco depois das galinhas, e dei-me ao gosto de propor a mim mesmo um problema. 

Verdadeiramente era uma charada; mas o nome de problema dá dignidade, e excita para logo a atenção dos leitores austeros. 

Sou como as atrizes, que já não fazem benefício, mas festa artística. 

A coisa é a mesma, os bilhetes crescem de igual modo, seja em número, seja em preço; o resto, comédia, drama, opereta, uma polca entre dois atos, uma poesia, vários ramalhetes, lampiões fora, e os colegas em grande gala, oferecendo em cena o retrato à beneficiada. 

Tudo pede certa elevação. 
```

Após a análise das duas entradas, o programa imprimiu a seguinte saída:

```
ainda: 768
assim: 610
tudo: 751
todos: 526
outra: 573
homem: 537
pode: 612
outros: 492
aqui: 506
dia: 482
tão: 431
vez: 500
grande: 474
outro: 581
tempo: 493
lo: 415
dias: 443
agora: 476
nada: 454
bem: 475

446 ms
```

Assim, o _heap_ ficou da seguinte forma:

<table align="center" style="width: 50%">
  <tr>
    <td align="center" style="width: 33%">768</td>
    <td align="center" style="width: 33%">610</td>
    <td align="center" style="width: 33%">751</td>
    <td align="center" style="width: 33%">526</td>
    <td align="center" style="width: 33%">573</td>
    <td align="center" style="width: 33%">537</td>
    <td align="center" style="width: 33%">612</td>
    <td align="center" style="width: 33%">492</td>
    <td align="center" style="width: 33%">506</td>
    <td align="center" style="width: 33%">482</td>
    <td align="center" style="width: 33%">431</td>
    <td align="center" style="width: 33%">500</td>
    <td align="center" style="width: 33%">474</td>
    <td align="center" style="width: 33%">581</td>
    <td align="center" style="width: 33%">493</td>
    <td align="center" style="width: 33%">415</td>
    <td align="center" style="width: 33%">443</td>
    <td align="center" style="width: 33%">476</td>
    <td align="center" style="width: 33%">454</td>
    <td align="center" style="width: 33%">475</td>
  </tr>
</table>

Conforme discorrido anteriormente, os filhos de cada nó, em um _max heap_, são menores que o nó pai. Os filhos da esquerda e da direita do item `ainda: 768` são, respectivamente, `assim: 610` (_2i_) e `tudo: 751` (_2i + 1_). A árvore abaixo mostra a árvore da raiz até a profundidade 3, conforme a saída do programa.

```
       768
     /     \
   610     751
   / \     / \
 526 573 537 612
 / \ / \ / \ / \
```

O exemplo aqui exposto foi compilado com o GNU Compiler Collection (gcc) versão 4:10.2.1-1, no sistema operacional Debian 11 (Bullseye). O computador possuia uma placa-mãe ASUS AM1M-A/BR, 8 GB de memória RAM DDR3 e um processador AMD Athlon 5150 (arquitetura x86_64).

## Conclusão

Pode-se afirmar que a código cumpriu com o que foi proposto na atividade, criando um contador de palavras que armazena as palavras que mais aparecem nos textos de entrada em um _max heap_. A execução do programa ocorreu conforme esperado, como foi possível verificar no exemplo citado.

Dessa forma, é possível afirmar que a utilização da estratégia de colocar os itens em um _min heap_, de forma que o elemento de menor valor fique em primeiro foi eficiente, para então fazer novamente o _heap_ que, conforme discorrido anteriormente, possui custo linear.

Ainda existem alguns pontos de possível melhora no programa, como a verificação das exceções vistas nos casos sem tratamento. Portanto, uma revisão do programa o tornaria ainda melhor, pois, nestas atuais condições, o usuário poderá comprometer a execução do programa, dependendo do que este colocar como entrada.

## Compilação e Execução

O algoritmo do labirinto decorrente disponibilizado possui um arquivo Makefile que realiza todo o procedimento de compilação e execução. Para tanto, temos as seguintes diretrizes de execução:


| Comando                |  Função                                                                                           |                     
| -----------------------| ------------------------------------------------------------------------------------------------- |
|  `make clean`          | Apaga a última compilação realizada contida na pasta build                                        |
|  `make`                | Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build           |
|  `make run`            | Executa o programa da pasta build após a realização da compilação                                 |


## Contato

<a style="color:black" href="mailto:rafaelg000@gmail.com?subject=[GitHub]%20Source%20Dynamic%20Lists">
    ✉️ <i>rafaelg000@gmail.com</i>
</a>
