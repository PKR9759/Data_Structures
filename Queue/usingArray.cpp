#include <iostream>

class Queue {
private:
    int front, rear, maxSize;
    int* array;

public:
    Queue(int size) {
        maxSize = size;
        array = new int[maxSize];
        front = -1;
        rear = -1;
    }

    ~Queue() {
        delete[] array;
    }

    bool isEmpty() {
        return front == -1 && rear == -1;
    }

    bool isFull() {
        return (rear + 1) % maxSize == front;
    }

    void enqueue(int item) {
        if (isFull()) {
            std::cout << "Queue is full. Cannot enqueue element." << std::endl;
        } else {
            if (isEmpty()) {
                front = rear = 0;
            } else {
                rear = (rear + 1) % maxSize;
            }
            array[rear] = item;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty. Cannot dequeue element." << std::endl;
        } else {
            if (front == rear) {
                front = rear = -1;
            } else {
                front = (front + 1) % maxSize;
            }
        }
    }

    int peek() {
        if (isEmpty()) {
            std::cout << "Queue is empty." << std::endl;
            return -1;
        } else {
            return array[front];
        }
    }
};

int main() {
    Queue queue(5);

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    queue.enqueue(5);

    std::cout << "Front element: " << queue.peek() << std::endl;

    queue.dequeue();
    queue.dequeue();

    std::cout << "Front element after dequeue: " << queue.peek() << std::endl;

    return 0;
}
