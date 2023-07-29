#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <iostream>
#include "Registro.h"

template <typename T>
class Node {
public:
    T data;
    Node* next;
    Node* prev;

    Node(T data) : data(data), next(nullptr), prev(nullptr) {}
};

template <typename T>
class DoublyLinkedList {
public:
    Node<T>* head;
    Node<T>* tail;
    size_t _size;

    DoublyLinkedList() : head(nullptr), tail(nullptr), _size(0) {}

    ~DoublyLinkedList() {
        clear();
    }

    void clear() {
        while (head != nullptr) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
            temp = nullptr;  // Ensure the pointer is null after deleting
        }
        tail = nullptr;
        _size = 0;
    }

    void push_back(T data) {
        Node<T>* newNode = new Node<T>(data);
        if (newNode == nullptr) {
            throw std::runtime_error("No se pudo asignar memoria para un nuevo nodo");
        }

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        _size++;
    }

    T& operator[](size_t index) {
        return at(index);
    }

    T& at(size_t index) {
        if (index >= _size) {
            throw std::out_of_range("El índice está fuera del rango de la lista");
        }

        Node<T>* current = head;
        for (size_t i = 0; i < index; i++) {
            current = current->next;
        }
        return current->data;
    }

    void display() {
        Node<T>* temp = head;

        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    void split(Node<T>* source, Node<T>** frontRef, Node<T>** backRef) {
        Node<T>* fast;
        Node<T>* slow;
        slow = source;
        fast = source->next;
    
        while (fast != NULL) {
            fast = fast->next;
            if (fast != NULL) {
                slow = slow->next;
                fast = fast->next;
            }
        }

        if(slow != nullptr) {
            *frontRef = source;
            *backRef = slow->next;
            slow->next = nullptr;
        }
    }

void mergeSort(Node<T>** headRef) {
    Node<T>* head = *headRef;
    Node<T>* a = nullptr;
    Node<T>* b = nullptr;

    if ((head == NULL) || (head->next == NULL))
        return;

    split(head, &a, &b);

    mergeSort(&a);
    mergeSort(&b);

    *headRef = sortedMerge(a, b);
}

Node<T>* sortedMerge(Node<T>* a, Node<T>* b) {
    Node<T>* result = NULL;
    
    if (a == NULL)
        return b;
    else if (b == NULL)
        return a;

    if (a->data <= b->data) {
        result = a;
        result->next = sortedMerge(a->next, b);
        if(result->next) {
            result->next->prev = result;
        }
    }
    else {
        result = b;
        result->next = sortedMerge(a, b->next);
        if(result->next) {
            result->next->prev = result;
        }
    }
    return result;
}

    
    void sort() {
        mergeSort(&head);
    }

    size_t size() const {
        return _size;
    }
class Iterator {
    Node<T>* current;
public:
    Iterator(Node<T>* node) : current(node) {}
    typedef Registro value_type;
    typedef std::ptrdiff_t difference_type;
    typedef Registro* pointer;
    typedef Registro& reference;
    typedef std::bidirectional_iterator_tag iterator_category;

    Iterator& operator++() { 
        if (current) current = current->next; 
        return *this; 
    }

    Iterator operator++(int) { 
        Iterator temp = *this;
        ++(*this);
        return temp;
    }

          // Operador de decremento prefijo.
    Iterator& operator--() {
        // Aquí va tu código para retroceder el iterador...
        return *this;
    }

    // Operador de decremento postfijo.
    Iterator operator--(int) {
        Iterator temp = *this;
        // Aquí va tu código para retroceder el iterador...
        return temp;
    }

    bool operator!=(const Iterator& other) const { 
        return current != other.current; 
    }

    T& operator*() { 
        return current->data; 
    }

    bool operator<=(const Iterator& other) const {
        Node<T>* temp = current;
        while (temp != nullptr) {
            if (temp == other.current)
                return true;
            temp = temp->next;
        }
        return false;
    }
};


    Iterator begin() { 
        return Iterator(head); 
    }

    Iterator end() { 
        return Iterator(nullptr); 
    }

    Iterator begin() const { 
        return Iterator(head); 
    }

    Iterator end() const { 
        return Iterator(nullptr); 
    }
};
#endif
