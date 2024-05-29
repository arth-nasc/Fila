#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da lista
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Definição da estrutura da fila
typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

// Função para criar um novo nó
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Função para criar uma nova fila vazia
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

// Função para verificar se a fila está vazia
int isEmpty(Queue* queue) {
    return (queue->front == NULL);
}

// Função para enfileirar um elemento
void enqueue(Queue* queue, int data) {
    Node* newNode = createNode(data);
    if (isEmpty(queue)) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

// Função para desenfileirar um elemento
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("A fila está vazia.\n");
        return -1; // Valor inválido
    } else {
        int data = queue->front->data;
        Node* temp = queue->front;
        queue->front = queue->front->next;
        free(temp);
        return data;
    }
}

// Função para obter o elemento da frente da fila
int front(Queue* queue) {
    if (isEmpty(queue)) {
        printf("A fila está vazia.\n");
        return -1; // Valor inválido
    } else {
        return queue->front->data;
    }
}

// Função principal
int main() {
    Queue* queue = createQueue();

    // Enfileirar alguns elementos
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);

    // Imprimir o elemento da frente da fila
    printf("Elemento da frente da fila: %d\n", front(queue));

    // Desenfileirar um elemento e imprimir
    printf("Elemento desenfileirado: %d\n", dequeue(queue));

    // Imprimir o elemento da frente da fila novamente
    printf("Elemento da frente da fila: %d\n", front(queue));

    // Desenfileirar todos os elementos restantes
    while (!isEmpty(queue)) {
        printf("Elemento desenfileirado: %d\n", dequeue(queue));
    }

    return 0;
}
