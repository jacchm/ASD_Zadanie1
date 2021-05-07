#include <iostream>

using namespace std;

struct QueueNode {
    int value;
    QueueNode *next;
};

struct QueueImpl {
    QueueNode *front;
    QueueNode *rear;
    int size;
};

void add(QueueImpl *queue, int x);

bool next(QueueImpl *queue);

int first(QueueImpl *queue);

bool isEmpty(QueueImpl *queue);

void displayQueue(QueueImpl *queue);

/*
 * main() created for testing
 */
int main() {

    auto *queue = new QueueImpl;
    queue->front = nullptr;
    queue->rear = nullptr;

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
void add(QueueImpl *queue, int x) {
    QueueNode *newNode = new QueueNode;
    newNode->next = nullptr;
    newNode->value = x;
//    cout << "newnode.next = " << newNode->next << " newnode.value = " << newNode->value << endl;

    if (queue->front == nullptr && queue->rear == nullptr) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    queue->size++;
}

/*
 * Typical name for this function is dequeue();
 */
bool next(QueueImpl *queue) {
    if (isEmpty(queue)) {
        cout << "Queue is empty." << endl;
        return false;
    }
    if (queue->front == queue->rear) {
        free(queue->front);
        queue->front = nullptr;
        queue->rear = nullptr;
    } else {
        QueueNode *front = queue->front;
        queue->front = queue->front->next;
        delete front;
    }
    queue->size--;
    return true;
}

int first(QueueImpl *queue) {
    if (isEmpty(queue)) {
        cout << "Queue is empty." << endl;
        return -1;
    }
    return queue->front->value;
}

bool isEmpty(QueueImpl *queue) {
    if (queue->front == nullptr && queue->rear == nullptr) {
        return true;
    }
    return false;
}

/*
 * Function created for testing.
 * Prints the whole Queue.
 */
void displayQueue(QueueImpl *queue) {
    if (isEmpty(queue)) {
        cout << "Queue is empty." << endl;
    }
    QueueNode *node = queue->front;
    while (node != nullptr) {
        cout << node->value << endl;
        node = node->next;
    }
}
