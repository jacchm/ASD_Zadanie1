#include <iostream>

using namespace std;

struct QueueNode {
    int value;
    QueueNode *next;
};

struct Queue {
    QueueNode *front = nullptr;
    QueueNode *rear = nullptr;
    int size = 0;
};

void add(Queue *queue, int x);

bool next(Queue *queue);

int first(Queue *queue);

bool isEmpty(Queue *queue);

void displayQueue(Queue *queue);

/*
 * main() created for testing
 */
int main() {

    auto *queue = new Queue;

    cout << "Size of a queue: " << queue->size << endl;
    cout << "queue.front = " << queue->front << " queue.rear = " << queue->rear << endl;

    add(queue, 1);
    add(queue, 2);
    add(queue, 3);
    add(queue, 4);
    add(queue, 5);

    displayQueue(queue);

    cout << "Size of a queue: " << queue->size << endl;

    next(queue);
    cout << "Size of a queue: " << queue->size << endl;
    next(queue);
    next(queue);
    next(queue);
    cout << "Size of a queue: " << queue->size << endl;
    next(queue);
    next(queue);
    cout << "Size of a queue: " << queue->size << endl;

    cout << "First: " << first(queue) << endl;

    cout << "End of tests." << endl;
    return 0;
}

/*
 * Typical name for this function is enqueue();
 */
void add(Queue *queue, int x) {
    QueueNode *newNode = new QueueNode;
    newNode->next = nullptr;
    newNode->value = x;
//    cout << "newnode.next = " << newNode->next << " newnode.value = " << newNode->value << endl;

    if (queue->front == nullptr && queue->rear == nullptr) {    // kolejka jest pusta
        queue->front = newNode;
        queue->rear = newNode;
    } else {                                                    // kolejka nie jest pusta
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    queue->size++;
}

/*
 * Typical name for this function is dequeue();
 */
bool next(Queue *queue) {
    if (isEmpty(queue)) {
        cout << "Queue is empty." << endl;
        return false;
    }
    if (queue->front == queue->rear) {
        QueueNode *ptr = queue->front;
        queue->front = nullptr;
        queue->rear = nullptr;
        delete ptr;
    } else {
        QueueNode *ptr = queue->front;
        queue->front = queue->front->next;
        delete ptr;
    }
    queue->size--;
    return true;
}

int first(Queue *queue) {
    if (isEmpty(queue)) {
        cout << "Queue is empty." << endl;
        // co wpisać jako wartość
        return -1;
    }
    return queue->front->value;
}

bool isEmpty(Queue *queue) {
    if (queue->front == nullptr) {
        return true;
    }
    return false;
}

/*
 * Function created for testing.
 * Prints the whole Queue.
 */
void displayQueue(Queue *queue) {
    if (isEmpty(queue)) {
        cout << "Queue is empty." << endl;
    }
    QueueNode *node = queue->front;
    while (node != nullptr) {
        cout << node->value << endl;
        node = node->next;
    }
}
