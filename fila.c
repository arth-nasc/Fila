#include <stdio.h>
#include <stdlib.h>

// Defini��o da estrutura do n� da lista
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Defini��o da estrutura da fila
typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

// Fun��o para criar um novo n�
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Fun��o para criar uma nova fila vazia
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

// Fun��o para verificar se a fila est� vazia
int isEmpty(Queue* queue) {
    return (queue->front == NULL);
}

// Fun��o para enfileirar um elemento
void enqueue(Queue* queue, int data) {
    Node* newNode = createNode(data);
    if (isEmpty(queue)) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

// Fun��o para desenfileirar um elemento
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("A fila est� vazia.\n");
        return -1; // Valor inv�lido
    } else {
        int data = queue->front->data;
        Node* temp = queue->front;
        queue->front = queue->front->next;
        free(temp);
        return data;
    }
}

// Fun��o para obter o elemento da frente da fila
int front(Queue* queue) {
    if (isEmpty(queue)) {
        printf("A fila est� vazia.\n");
        return -1; // Valor inv�lido
    } else {
        return queue->front->data;
    }
}

// Fun��o principal
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
