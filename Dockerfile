FROM japeto/so-tools:v64

# Directorio de trabajo dentro del contenedor
WORKDIR /app

# Copiar toda la carpeta testFiles al contenedor
COPY testFiles/ ./testFiles/

# Compilar manualmente
RUN g++ -std=c++20 -O2 -static -static-libgcc -static-libstdc++ \
    SchedulingSim.cpp queue.cpp table.cpp scheduler.cpp \
    -o SchedulingSimSO