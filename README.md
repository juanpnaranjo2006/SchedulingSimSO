# SchedulingSimSO

Simulador de planificación de procesos desarrollado en C++.

---

## 🔹 Instrucciones para ejecutar

1. **Clonar el repositorio**  
   ```bash
   git clone <URL_DEL_REPOSITORIO>
   cd <NOMBRE_DEL_REPOSITORIO>

Crear la imagen de Docker

docker build -t scheduling-sim .

Crear un contenedor interactivo

docker run -it --rm scheduling-sim bash

Dentro del contenedor, para conocer cómo usar el ejecutable:

./SchedulingSimSO -h
⚡ Notas

La imagen de Docker incluye todos los archivos fuente y compila el ejecutable SchedulingSimSO.

Puedes ejecutar tus pruebas directamente dentro del contenedor.

Cualquier cambio en los archivos fuente requiere reconstruir la imagen con docker build.

📂 Estructura del proyecto
.
├── SchedulingSim.cpp
├── queue.cpp
├── queue.h
├── table.cpp
├── table.h
├── scheduler.cpp
├── scheduler.h
├── testFiles/      # Archivos de prueba
├── Dockerfile
└── README.md
