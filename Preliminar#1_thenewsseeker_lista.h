//Pablo Ramirez Lopez 2019246933
//fecha: 25/08/23

#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H
#include <string>

//METODOS DEL TAD

//Estrucutura de una noticia que incluye: Titulo, fecha, tema y su relevancia
struct NewsHeadline {
    std::string title;
    std::string topic;
    std::string date;
    int relevance;
};

//Clase encargada de la lista doble enlazada
class DoubleLinkedList {
private:
    struct Node {
        NewsHeadline data;
        Node* prev;
        Node* next;
        Node(const NewsHeadline& item) : data(item), prev(nullptr), next(nullptr) {}
    };
    Node* head;
    Node* tail;
}
