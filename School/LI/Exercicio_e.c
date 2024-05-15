#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

// OPEN 

#define TABLE_SIZE 5 // Tamanho da tabela de hash

// Estrutura da tabela de hash
typedef struct HashTable {
    int size; // Tamanho da tabela de hash
    int *table; // Ponteiro para a tabela de hash
} HashTable;

// Estrutura para o resultado da inserção
typedef struct InsertResult {
    int index; // Índice onde a inserção ocorreu (-1 se falhou)
    int value; // Valor inserido
} InsertResult;


void deleteKey(HashTable* ht, int key);

// Função para criar uma nova tabela de hash
HashTable* newHashTable(int size) {
    HashTable* ht = (HashTable*)malloc(sizeof(HashTable));
    ht->size = size;
    ht->table = (int*)calloc(size, sizeof(int)); // Inicializa a tabela com zeros
    return ht;
}

// Função de hash simples para este exemplo (resto da divisão)
int hash(int key, int size) {
    return key % size;
}

void reorganizeHashTable(HashTable* ht) {
    // Cria uma nova tabela de hash temporária com o mesmo tamanho
    HashTable* temp = newHashTable(ht->size);

    // Insere todos os elementos da tabela atual na tabela temporária
    for (int i = 0; i < ht->size; i++) {
        if (ht->table[i] != 0 && ht->table[i] != -1) {
            // Recalcula o índice usando a função de hash
            int newIndex = hash(ht->table[i], ht->size);
            
            // Encontra a próxima posição vazia na tabela temporária
            while (temp->table[newIndex] != 0 && temp->table[newIndex] != -1) {
                newIndex = (newIndex + 1) % ht->size;
            }
            
            // Insere o elemento na tabela temporária
            temp->table[newIndex] = ht->table[i];
        }
    }

    // Copia os elementos da tabela temporária de volta para a tabela original
    for (int i = 0; i < ht->size; i++) {
        // Verifica se a posição correspondente na tabela temporária está marcada como deletada
        if (temp->table[i] == -1) {
            ht->table[i] = -1; // Mantém a posição na tabela original marcada como deletada
        } else {
            ht->table[i] = temp->table[i]; // Copia o elemento da tabela temporária para a tabela original
        }
    }


    // Libera a memória da tabela temporária
    free(temp->table);
    free(temp);
}




// Função para inserir um elemento na tabela de hash em silêncio (sem imprimir nada)
void insertNewKeySilently(HashTable* ht, int key) {
    // Calcula o índice usando a função de hash
    int index = hash(key, ht->size); 
    int initial_index = index; // Salva o índice inicial para detecção de loop completo

    // Procura por uma posição livre usando sondagem linear
    while (ht->table[index] != 0 && ht->table[index] != -1) {
        index = (index + 1) % ht->size; // Avança para a próxima posição (com circularidade)

        // Se a sondagem completar uma volta completa, retorna com falha
        if (index == initial_index) {
            printf("GIVING UP!!!\n");
            return;
        }
    }

    // Se encontrou um espaço livre ou um espaço marcado como deletado, insere o elemento na posição
    ht->table[index] = key;
}



// Função para inserir uma chave na tabela de hash usando endereçamento aberto com sondagem linear
InsertResult insertOpenAddressing(HashTable* ht, int key) {
    InsertResult result;

    // Verifica se o elemento já está na tabela
    for (int i = 0; i < ht->size; i++) {
        if (ht->table[i] == key) {
            deleteKey(ht, key); // Remove o elemento sem imprimir nada
            insertNewKeySilently(ht, key); 
            result.index = -1;
            result.value = key;
            return result;
        }
    }

    // Calcula o índice usando a função de hash
    int index = hash(key, ht->size); 
    int initial_index = index; // Salva o índice inicial para detecção de loop completo

    // Procura por uma posição livre usando sondagem linear
    while (ht->table[index] != 0 && ht->table[index] != -1) {
        index = (index + 1) % ht->size; // Avança para a próxima posição (com circularidade)

        // Se a sondagem completar uma volta completa, retorna com falha
        if (index == initial_index) {
            printf("GIVING UP!!!\n");
            result.index = -1;
            return result;
        }
    }

    // Se encontrou um espaço livre ou um espaço marcado como deletado, insere o elemento na posição
    ht->table[index] = key;
    result.index = index;
    result.value = key;
    return result;
}

// Função para excluir uma chave da tabela de hash
void deleteKey(HashTable* ht, int key) {
    // Procura a chave na tabela e marca a posição como deletada (-1) se encontrada
    for (int i = 0; i < ht->size; i++) {
        if (ht->table[i] == key) {
            ht->table[i] = -1;
            return;
        }
    }
}

// Função para imprimir a tabela de hash
void printHashTable(HashTable* ht) {

    for (int i = 0; i < ht->size; i++) {
        if (ht->table[i] == -1) {
            printf("%d\tD\n", i);
        } else if (ht->table[i] != 0) {
            printf("%d\t%d\n", i, ht->table[i]);
        }
    }
}
//FIM DO OPEN

//LINK

// Estrutura do nó da lista encadeada
typedef struct Node {
    int key; // Chave armazenada no nó
    struct Node* next; // Ponteiro para o próximo nó na lista
} Node;

// Estrutura da tabela de hash
typedef struct HashTable2 {
    int size; // Tamanho da tabela de hash
    Node** table; // Array de ponteiros para os nós da lista encadeada
} HashTable2;

// Função para criar uma nova tabela de hash
HashTable2* newHashTable2(int size) {
    HashTable2* ht = (HashTable2*)malloc(sizeof(HashTable2));
    ht->size = size;
    ht->table = (Node**)calloc(size, sizeof(Node*)); // Inicializa a tabela com NULLs
    return ht;
}

// Função para inserir um elemento na tabela de hash usando lista encadeada
void insertLinkedList(HashTable2* ht, int key) {
    int index = hash(key, ht->size); // Calcula o índice usando a função de hash
    Node* newNode = (Node*)malloc(sizeof(Node)); // Cria um novo nó com a chave
    newNode->key = key;

    // Adiciona o novo nó no início da lista encadeada
    newNode->next = ht->table[index];
    ht->table[index] = newNode;
}

// Função para deletar um elemento da lista encadeada
void deleteLinkedList(Node** headRef) {
    if (*headRef == NULL) {
        printf("NO\n"); // Se a lista estiver vazia, imprime NO
        return;
    }
    
    Node* temp = *headRef;
    *headRef = (*headRef)->next;
    free(temp);
    printf("OK\n");
}

// Função para deletar uma chave na tabela de hash
void deleteKeyLink(HashTable2* ht, int key) {
    int index = hash(key, ht->size); // Calcula o índice usando a função de hash
    Node* current = ht->table[index];
    Node* prev = NULL;

    // Procura o nó com a chave na lista encadeada
    while (current != NULL && current->key != key) {
        prev = current;
        current = current->next;
    }

    // Se o nó com a chave for encontrado, exclua-o
    if (current != NULL) {
        if (prev == NULL) {
            ht->table[index] = current->next; // Se for o primeiro nó na lista, atualiza o ponteiro da tabela de hash
        } else {
            prev->next = current->next; // Se não for o primeiro nó, ajusta os ponteiros
        }
        free(current);
        printf("OK\n");
    } else {
        printf("NO\n"); // Se a chave não for encontrada, imprime NO
    }
}

// Função para verificar se uma chave existe na tabela de hash
void checkKey(HashTable2* ht, int key) {
    int index = hash(key, ht->size); // Calcula o índice usando a função de hash
    Node* current = ht->table[index];

    // Procura o nó com a chave na lista encadeada
    while (current != NULL && current->key != key) {
        current = current->next;
    }

    // Se o nó com a chave for encontrado, imprime o índice
    if (current != NULL) {
        printf("%d\n", index);
    } else {
        printf("NO\n"); // Se a chave não for encontrada, imprime NO
    }
}

// Função para imprimir a tabela de hash com as chaves inseridas na cabeça da lista
void printHashTable2WithHead(HashTable2* ht2) {

    // Percorre a tabela de hash e imprime os elementos
    for (int i = 0; i < ht2->size; i++) {
        if (ht2->table[i] != NULL) {
            printf("%d", i);
            Node* current = ht2->table[i];
            while (current != NULL) {
                printf(" %d", current->key);
                current = current->next;
            }
            printf("\n");
        }
    }
}

//FIM DO LINK 

//CUCKOO 

// Função para verificar se a chave já existe na tabela de hash
int key_already_exists(int array[][2], int key, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < 2; j++) {
            if (array[i][j] == key) {
                return i * 2 + j;
            }
        }
    }
    return -1;
}

void cuckoo_resolution(int array[][2], int* last_positions, int key, int size, char resolution, int* coluna, int attempts) {
    int key_to_displace;
    int index; // Declaração da variável index fora do bloco if

    if (resolution == 'I') {
        int i = 0;
        while (i <= size) {
            if (attempts < size + 1) {
                index = hash(key, size); // Movido para dentro do while loop
                if (i % 2 == 0) {
                    if (array[index][0] == 0) {
                        array[index][0] = key;
                        last_positions[key] = index * 2;
                        *coluna = 0;
                        attempts++;
                        printf("0 %d -> %d\nOK\n", index, key);
                        return;
                    } else {
                        key_to_displace = array[index][0];
                        array[index][0] = key;
                        last_positions[key] = index * 2;
                        *coluna = 0;
                        attempts++;
                        printf("0 %d -> %d\n", index, key);
                        key = key_to_displace;
                        index = hash(key, size);
                    }
                } else {
                    index = hash(key / size, size); // Movido para dentro do bloco else
                    if (array[index][1] == 0) {
                        array[index][1] = key;
                        last_positions[key] = index * 2 + 1;
                        *coluna = 1;
                        attempts++;
                        printf("1 %d -> %d\nOK\n", index, key);
                        return;
                    } else {
                        if (attempts < size + 1) {
                            key_to_displace = array[index][1];
                            array[index][1] = key;
                            last_positions[key] = index * 2 + 1;
                            *coluna = 1;
                            printf("1 %d -> %d\n", index, key);
                            attempts++;
                            // Chamada recursiva para tentar inserir o elemento deslocado em uma nova posição
                            cuckoo_resolution(array, last_positions, key_to_displace, size, 'I', coluna, attempts);
                            return;
                        } else {
                            printf("GIVING UP!\n");
                            return;
                        }
                    }
                }
            }
            else{
                printf("GIVING UP!\n");
                return;
            }
            // Verifica se a posição do elemento inserido é (0, 1)
            if (index == 0 && i % 2 == 1) {
                printf("OK\n");
                return;
            }
            i++;
        }
        printf("GIVING UP!\n");
    } else if (resolution == 'C') {
        int x = key_already_exists(array, key, size);
        if (x != -1) {
            printf("%d\t%d\n", x / 2, x % 2);
        } else {
            printf("NO\n");
        }
    } else if (resolution == 'D') {
        int y = key_already_exists(array, key, size);
        if (y != -1) {
            array[y / 2][y % 2] = 0;
            printf("OK\n");
        } else {
            printf("NO\n");
        }
    }
}

void printhashCUCKOO(int array[][2], int size) {
    for (int j = 0; j < 2; j++) {
        for (int i = 0; i < size; i++) {
            if (array[i][j] != 0) {
                printf("%d\t%d\t%d\n", j, i, array[i][j]);
            }
        }
    }
}

//FIM DO CUCKOO 
void parseInputLINK(HashTable2* ht) {
    char op;
    int key;
    while (scanf(" %c", &op) == 1) {
        switch (op) {
            case 'I':
                assert(scanf("%d", &key) == 1);
                insertLinkedList(ht, key);
                printf("%d -> %d\n", hash(key, ht->size), key);
                printf("OK\n");
                break;
            case 'D':
                assert(scanf("%d", &key) == 1);
                deleteKeyLink(ht, key);
                break;
            case 'P':
                printHashTable2WithHead(ht);
                break;
            case 'C':
                assert(scanf("%d", &key) == 1);
                checkKey(ht, key);
                break;
        }
    }
}

void parseInputOPEN(HashTable* ht2) {
    char op;
    int key;
    while (scanf(" %c", &op) == 1) {
        switch (op) {
            case 'I':
                assert(scanf("%d", &key) == 1);
                InsertResult result = insertOpenAddressing(ht2, key);
                if (result.index != -1) {
                    printf("%d -> %d\n", result.index, result.value);
                    printf("OK\n");
                } else {
                    printf("%d EXISTS\n", key);
                }
                break;
            case 'D':
                assert(scanf("%d", &key) == 1);
                deleteKey(ht2, key);
                printf("OK\n");
                break;
            case 'P':
                printHashTable(ht2);
                break;
            case 'C':
                assert(scanf("%d", &key) == 1);;
                int index_found = -1; // Inicializa o índice encontrado como -1
                for (int i = 0; i < ht2->size; i++) {
                if (ht2->table[i] == key || ht2->table[i] == 0 || ht2->table[i] == -1) {
                deleteKey(ht2, key); // Remove o elemento, se existir
                insertNewKeySilently(ht2, key); // Insere novamente
                index_found = i; // Armazena o índice onde o elemento foi encontrado ou será inserido
                break;
                 }
                }
                if (index_found != -1) {
                    printf("%d\n", index_found); // Imprime o índice onde o elemento foi encontrado ou será inserido
                } else {
                    printf("NO\n");
                }
            break;
            }
    }
}

int main() {
    int size;
    char resolution[10];
    assert(scanf("%d %s", &size, resolution));
    char op;
    int key;
    int coluna = 0; // Inicialização de coluna

    int* last_positions = (int*)calloc(1000000, sizeof(int)); // Assumindo um máximo de 1000000 chaves

    int cuckoo_table[size][2];
    for (int i = 0; i < size; i++) {
        cuckoo_table[i][0] = 0;
        cuckoo_table[i][1] = 0;
    }

    
    HashTable* ht2 = newHashTable(size);
    HashTable2* ht = newHashTable2(size);
    
    if (strcmp(resolution , "LINK") == 0){
        parseInputLINK(ht);
    }
    else if (strcmp(resolution, "OPEN") == 0){
        parseInputOPEN(ht2);
    }
    else if (strcmp(resolution, "CUCKOO") == 0){
        while (scanf(" %c", &op) == 1) {
            switch (op) {
                case 'I':
                    assert(scanf("%d", &key) == 1);
                    cuckoo_resolution(cuckoo_table, last_positions, key, size, 'I', &coluna, 0); // Passando o endereço de coluna
                    break;
                case 'D':
                    assert(scanf("%d", &key) == 1);
                    cuckoo_resolution(cuckoo_table, last_positions, key, size, 'D', &coluna, 0); // Passando o endereço de coluna
                    break;
                case 'P':
                    printhashCUCKOO(cuckoo_table, size); // Adicionando o parâmetro coluna
                    break;
                case 'C':
                    assert(scanf("%d", &key) == 1);
                    cuckoo_resolution(cuckoo_table, last_positions, key, size, 'C', &coluna, 0); // Passando o endereço de coluna
                    break;
            }
        }
    }
    
    free(last_positions);
    
    for (int i = 0; i < ht->size; i++) {
        Node* current = ht->table[i];
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }

    free(ht2->table);
    free(ht2);

    free(ht->table);
    free(ht);

    return 0;
}
