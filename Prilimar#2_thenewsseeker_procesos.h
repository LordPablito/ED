//Pablo Ramirez Lopez 2019246933
//fecha: 25/08/23

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