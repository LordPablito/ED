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


//METODOS DE OPERACION
public:
    DoubleLinkedList(); // Constructor

    // Insertara el nuevo elemento al final de la lista, necesita Lista de Titulos y el item que quiera agregar
    void insert(const NewsHeadline& item);

    // Elimina el elemento dado de la lista, necesita la lista de Titulares y Titulo a eliminar
    void remove(const NewsHeadline& item);

    // Reordena la lista en base a la relevancia de los titulares, necestira la lista de Titulos
    void reorder();

    // Busca un titular por título y retorna un puntero al nodo si se encuentra
    Node* searchByTitle(const std::string& title);
}
