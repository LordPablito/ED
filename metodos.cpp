#include <iostream>
#include <string>
#include "news.cpp"

// Se encarga de las clase de cada noticia individual
class News {
private:
    std::string author;
    std::string title;
    std::string description;

public:
    News(std::string pAuthor, std::string pTitle, std::string pDescription)
        : author(pAuthor), title(pTitle), description(pDescription) {}

    std::string getAuthor() const { return author; }
    std::string getTitle() const { return title; }
    std::string getDescription() const { return description; }
};


//se encarga de las noticas en colectivo y sus metodos de modificacion
class ListaNoticias {
private:
    News** noticias;
    size_t numNoticias;
    size_t capacidad;

public:
    ListaNoticias(size_t capacidadInicial)
        : noticias(new News*[capacidadInicial]), numNoticias(0), capacidad(capacidadInicial) {}

    ~ListaNoticias() {
        for (size_t i = 0; i < numNoticias; ++i) {
            delete noticias[i];
        }
        delete[] noticias;
    }

    void AgregarNoticia(const News& noticia) {
        if (numNoticias < capacidad) {
            noticias[numNoticias] = new News(noticia);
            ++numNoticias;
        } else {
            std::cout << "La lista de noticias está llena." << std::endl;
        }
    }

    void MostrarNoticias() const {
        for (size_t i = 0; i < numNoticias; ++i) {
            std::cout << "Noticia " << i + 1 << ":" << std::endl;
            std::cout << "Autor: " << noticias[i]->getAuthor() << std::endl;
            std::cout << "Título: " << noticias[i]->getTitle() << std::endl;
            std::cout << "Descripción: " << noticias[i]->getDescription() << std::endl;
            std::cout << std::endl;
        }
    }

    void MostrarNoticiasPorPalabrasClave(const std::string& palabrasClave) const {
        std::vector<std::string> palabras;
        size_t start = 0, end = palabrasClave.find(',');

        // Separar las palabras clave por comas y almacenarlas
        while (end != std::string::npos) {
            palabras.push_back(palabrasClave.substr(start, end - start));
            start = end + 1;
            end = palabrasClave.find(',', start);
        }
        palabras.push_back(palabrasClave.substr(start, end));

        // Mostrar noticias que contengan al menos una palabra clave en el título o descripción
        for (size_t i = 0; i < numNoticias; ++i) {
            for (const std::string& palabra : palabras) {
                if (noticias[i]->getTitle().find(palabra) != std::string::npos ||
                    noticias[i]->getDescription().find(palabra) != std::string::npos) {
                    std::cout << "Noticia " << i + 1 << ":" << std::endl;
                    std::cout << "Autor: " << noticias[i]->getAuthor() << std::endl;
                    std::cout << "Título: " << noticias[i]->getTitle() << std::endl;
                    std::cout << "Descripción: " << noticias[i]->getDescription() << std::endl;
                    std::cout << std::endl;
                    break;  // Mostrar la noticia y pasar a la siguiente
                }
            }
        }
    }


    void EliminarNoticiasPorPalabrasClave(const std::string& palabrasClave) {
        std::vector<std::string> palabras;
        size_t start = 0, end = palabrasClave.find(',');

        // Separar las palabras clave por comas y almacenarlas
        while (end != std::string::npos) {
            palabras.push_back(palabrasClave.substr(start, end - start));
            start = end + 1;
            end = palabrasClave.find(',', start);
        }
        palabras.push_back(palabrasClave.substr(start, end));

        // Eliminar noticias que contengan al menos una palabra clave
        size_t i = 0;
        while (i < numNoticias) {
            bool eliminar = false;
            for (const std::string& palabra : palabras) {
                if (noticias[i]->getTitle().find(palabra) != std::string::npos ||
                    noticias[i]->getDescription().find(palabra) != std::string::npos) {
                    eliminar = true;
                    break;  // La noticia contiene una palabra clave, marcar para eliminación
                }
            }

            if (eliminar) {
                delete noticias[i];
                for (size_t j = i; j < numNoticias - 1; ++j) {
                    noticias[j] = noticias[j + 1];
                }
                --numNoticias;
            } else {
                ++i;
            }
        }
    }   


    void ReorganizarNoticia(int indice, int desplazamiento) {
        if (indice >= 0 && indice < numNoticias) {
            int nuevaPosicion = indice + desplazamiento;

            if (nuevaPosicion < 0) {
                nuevaPosicion = 0;
            } else if (nuevaPosicion >= numNoticias) {
                nuevaPosicion = numNoticias - 1;
            }

            News* noticia = noticias[indice];
            for (int i = indice; i != nuevaPosicion; i += (desplazamiento > 0) ? 1 : -1) {
                noticias[i] = noticias[i + ((desplazamiento > 0) ? 1 : -1)];
            }
            noticias[nuevaPosicion] = noticia;
        }
    }
}