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

void add(Queue &queue, int x);

bool next(Queue &queue, int &x);

int first(Queue queue);

bool isEmpty(Queue queue);

void displayQueue(Queue &queue);

/*
 * Typical name for this function is enqueue();
 * Function adds the new element to the queue.
 * Please note, that only positive integers can be added to the queue.
 */
void add(Queue &queue, int x) {
    if (x < 0) {
        cout << "Only positive integers can be added to the queue." << endl;
        cout << "   Value x = " << x << " has not been added." << endl;
        return;
    }
    QueueNode *newNode = new QueueNode;
    newNode->next = nullptr;
    newNode->value = x;

    if (isEmpty(queue)) {
        queue.front = newNode;
        queue.rear = newNode;
    } else {
        queue.rear->next = newNode;
        queue.rear = newNode;
    }
    queue.size++;
}

/*
 * Typical name for this function is dequeue();
 * Function retrieving value of the first element from the queue.
 * It does delete the first element from the queue.
 * Returns value -1 if the queue is empty.
 */
bool next(Queue &queue, int &x) {
    if (isEmpty(queue)) {
        x = -1;
        return false;
    }
    if (queue.front == queue.rear) {
        x = queue.front->value;
        QueueNode *ptr = queue.front;
        queue.front = nullptr;
        queue.rear = nullptr;
        delete ptr;
    } else {
        x = queue.front->value;
        QueueNode *ptr = queue.front;
        queue.front = queue.front->next;
        delete ptr;
    }
    queue.size--;
    return true;
}

/* Function retrieving value of the first element from the queue.
 * It does not delete the first element from the queue.
 * Returns value -1 if the queue is empty.
 */
int first(Queue queue) {
    if (isEmpty(queue)) {
        return -1;
    }
    return queue.front->value;
}

/* Function checking if the queue is empty.
 * It does not delete the first element from the queue.
 */
bool isEmpty(Queue queue) {
    if (queue.front == nullptr) {
        return true;
    }
    return false;
}

/*
 * Function created for testing.
 * Prints the whole Queue.
 * It is not the part of the queue flow
 * (moving from node to node is typical for linked lists).
 */
void displayQueue(Queue &queue) {
    if (isEmpty(queue)) {
        cout << "Queue is empty." << endl;
        return;
    }
    cout << "Queue view:" << endl;
    QueueNode *node = queue.front;
    while (node != nullptr) {
        cout << node->value << endl;
        node = node->next;
    }
}

/*
 * main() created for testing
 */
int main() {

    bool success;   // boolean that will keep the result of the function next(Queue &queue, int &x)
    int x = 0;      // integer that will keep the value retrieved from function next(Queue *queue, int &x)

    cout << "===================================================================================" << endl;

    cout << "Initializing new queue: " << endl;
    auto *queue = new Queue;
    cout << "Size of a new queue: " << queue->size << endl << endl;

    cout << "Adding a few integers to the queue: " << endl;
    add(*queue, -7);
    add(*queue, 7);
    add(*queue, 4);
    add(*queue, 2);
    add(*queue, 3);
    add(*queue, 5);

    displayQueue(*queue);
    cout << "New size of a queue: " << queue->size << endl << endl;

    cout << "===================================================================================" << endl;

    cout << "First element of the queue: " << first(*queue) << endl;
    cout << "Taking first element from the queue using next(Queue &queue, int &x)" << endl;
    success = next(*queue, x);
    cout << "Operation next(Queue &queue, int &x) was "
         << (success ? "successful" : "unsuccessful, because queue is empty")
         << endl;
    cout << "x = " << x << endl;
    cout << "Size of a queue: " << queue->size << endl << endl;

    displayQueue(*queue);
    cout << "===================================================================================" << endl;

    cout << "Current first element of the queue: " << first(*queue) << endl;
    cout << "Taking first element from the queue using next(Queue &queue, int &x)" << endl;
    success = next(*queue, x);
    cout << "Operation next(Queue &queue, int &x) was "
         << (success ? "successful" : "unsuccessful, because queue is empty")
         << endl;
    cout << "x = " << x << endl;
    cout << "Size of a queue: " << queue->size << endl << endl;

    displayQueue(*queue);
    cout << "===================================================================================" << endl;

    cout << "Adding two new elements to the queue: " << endl;
    add(*queue, 10);
    add(*queue, 13);
    cout << "Size of a queue: " << queue->size << endl << endl;

    displayQueue(*queue);
    cout << "===================================================================================" << endl;

    cout << "Current first element of the queue: " << first(*queue) << endl;
    cout << "Taking first element from the queue using next(Queue &queue, int &x)" << endl;
    success = next(*queue, x);
    cout << "Operation next(Queue &queue, int &x) was "
         << (success ? "successful" : "unsuccessful, because queue is empty")
         << endl;
    cout << "x = " << x << endl;
    cout << "Size of a queue: " << queue->size << endl << endl;

    displayQueue(*queue);
    cout << "===================================================================================" << endl;

    cout << "Taking all remaining elements using next(Queue &queue, int &x) to clean the queue" << endl;
    do {
        success = next(*queue, x);
        cout << "Operation next(Queue &queue, int &x) was "
             << (success ? "successful. " : "unsuccessful, because queue is empty. ");
        cout << "x = " << x << endl;
    } while (success);
    cout << "Size of a queue: " << queue->size << endl << endl;

    displayQueue(*queue);
    cout << "===================================================================================" << endl;

    cout << "Current first element of the queue: " << first(*queue) << endl;
    cout << "Taking first element from the queue using next(Queue &queue, int &x)" << endl;
    success = next(*queue, x);
    cout << "x = " << x << endl;
    cout << "Operation next(Queue &queue, int &x) was "
         << (success ? "successful" : "unsuccessful, because queue is empty")
         << endl;

    cout << "===================================================================================" << endl;
    cout << endl << "End of tests." << endl;
    return 0;
}
