# programacion-2

## DESCRIPCIÓN
Esta asignatura sirve de introducción al campo de la computación de alto
rendimiento, con énfasis en las principales metodologías de programación, lenguajes
y aplicaciones. Se enfoca en máquinas paralelas de memoria distribuida, también
conocidas como paso de mensajes.

### OBJETIVOS
* Conocer la historia de la Computación de Alto Rendimiento
* Aplicar métodos de diseño para algoritmos paralelos
* Comparar distintas arquitecturas paralelas de computadoras

### CONTENIDOS

#### Unidad I. Introducción a la Programación Paralela.
1. Arquitectura de Memoria Compartida.
2. Arquitectura de Memoria Distribuida.
3. Paso de mensajes.
   - SEND
   - RECEIVE
   - RECEIVE-FROM-ANY
   - Comunicación con bloqueo y sin bloqueo.
4. Aplicaciones: paralelizando algoritmos clásicos y análisis de rendimiento
   - Multiplicación de Matrices
   - Sobre-Relajación Sucesiva (SOR)
   - Floyd-Warshall
   - Eliminación Gausiana
   - Problema del Viajero Ambulante (TSP)
5. Diseño de Algoritmos Paralelos
   - Particionamiento
   - Comunicación
   - Aglomeración
   - Mapeo

#### Unidad II. Topologías de Redes para Procesamiento Paralelo.
1. Organización de Procesadores
2. Problemas principales en el diseño de redes
3. Topologías
   - Mesh
   - Árbol Binario
   - Hypertree
   - Fat Tree
   - Hypercube

#### Unidad III. Máquinas Paralelas.
1. Arreglos de procesadores
2. Multiprocesadores con memoria compartida
3. Multicomputadoras con memoria distribuida
4. Taxonomía de Flynn

#### Unidad IV. Métricas de Rendimiento
1. Speedup y Eficiencia.
2. Ley de Amdahl.
3. Medición del rendimiento.
   - Uso del reloj de pared.
   - Exclusión de la inicialización.

#### Unidad V. Paso de Mensajes.
1. Paso de Mensajes P2P
2. Identificación Directa (Direct Naming)
3. Identificación Indirecta (Indirect Naming)
4. Paso síncrono de mensajes
5. Paso asíncrono de mensajes
6. Buffering de mensajes
7. No-determinismo

#### Unidad VI. MPI
1. Modelo de programación MPI
2. Primitivos básicos en MPI
3. Modos de comunicación
4. Comunicación colectiva
5. Barreras
6. Reducción
