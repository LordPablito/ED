# Utiliza una imagen de Ubuntu como base
FROM ubuntu:latest

# Actualiza el sistema y instala las herramientas de compilación de C++
RUN apt-get update && apt-get install -y g++ make

# Crea un directorio de trabajo
WORKDIR /app

# Copia los archivos de código fuente al contenedor
COPY . /app

# Compila el programa
RUN g++ -o mi_programa_cpp main.cpp

# Establece el comando por defecto para ejecutar el programa
CMD ["./mi_programa_cpp"]
