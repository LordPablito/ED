#include "news.cpp"
#include "metodos.cpp"
#include <iostream>
#include <string>


int main() {
    ListaNoticias lista(5); // Capacidad inicial de la lista

    // Agregar varias noticias de ejemplo
    lista.AgregarNoticia(News("Autor1", "Título1", "Descripción1"));
    lista.AgregarNoticia(News("Autor2", "Título2", "Descripción2"));
    lista.AgregarNoticia(News("Autor3", "Título3", "Descripción3"));

    // Mostrar todas las noticias
    std::cout << "Todas las noticias:" << std::endl;
    lista.MostrarNoticias();

    // Buscar noticias con una palabra clave
    std::cout << "Noticias con la palabra clave 'Título':" << std::endl;
    lista.MostrarNoticiasPorPalabrasClave("Título");

    // Eliminar una noticia
    std::cout << "Eliminando la noticia en la posición 1:" << std::endl;
    lista.EliminarNoticiasPorIndice(1);

    // Reorganizar una noticia
    std::cout << "Reorganizando la noticia en la posición 0:" << std::endl;
    lista.ReorganizarNoticia(0, 2);

    // Mostrar noticias después de las operaciones
    std::cout << "Noticias después de las operaciones:" << std::endl;
    lista.MostrarNoticias();

    return 0;
}
