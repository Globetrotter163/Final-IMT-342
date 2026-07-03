# PROJECT_OBJECTIVE_BASELINE.md — Baseline estático del objetivo final

## Estado del documento

**Tipo:** documento estático de dirección técnica  
**Uso:** obligatorio para el chat Director del proyecto  
**Modificable:** no, salvo mediante ADR formal  
**Fuente académica base:** documento IEEE del proyecto: *Integración de Navegación, Manipulación e Inventario en una Arquitectura ROS2 para Almacenamiento Autónomo*

Este documento define la meta final del proyecto, su justificación desde el estado del arte, el gap que debe cerrar y el criterio conceptual de éxito.

No describe el estado actual del repositorio.  
No reemplaza `PROJECT_STATE.md`.  
No reemplaza `VALIDATION_PLAN.md`.

---

# 1. Título del proyecto

**Sistema Autónomo de Inventario y Almacenamiento para Centros Logísticos basado en ROS2**

Título académico asociado:

**Integración de Navegación, Manipulación e Inventario en una Arquitectura ROS2 para Almacenamiento Autónomo**

---

# 2. Problema general

La creciente complejidad de la intralogística en centros de distribución inteligentes, impulsada por la Industria 4.0 y el comercio electrónico, exige sistemas robóticos capaces de ejecutar flujos de almacenamiento autónomos completos.

Los centros logísticos modernos requieren:

- mayor precisión en inventario;
- trazabilidad digital;
- reducción de tiempos de operación;
- capacidad de navegación autónoma;
- interacción física con productos;
- actualización automática del estado digital del sistema.

Aunque los AMR, la visión artificial, la manipulación robótica y los sistemas ciberfísicos de inventario han avanzado de forma significativa, el problema central no está en la existencia aislada de estas tecnologías, sino en su **integración funcional dentro de un flujo logístico completo**.

---

# 3. Estado del arte resumido

## 3.1 AMR e intralogística

La literatura muestra una transición desde AGV hacia AMR en centros logísticos modernos. Los AMR han permitido mejorar el transporte interno, la planificación de rutas y la gestión operativa de flotas.

Limitación relevante:

> La mayoría de soluciones AMR no integran de manera completa percepción activa, manipulación física e inventario digital verificable dentro de una misma arquitectura operacional.

---

## 3.2 ROS2 como infraestructura robótica distribuida

ROS2 se consolida como middleware adecuado para sistemas robóticos distribuidos por su arquitectura basada en nodos, DDS, comunicación desacoplada y soporte para integración de múltiples subsistemas.

Limitación relevante:

> ROS2 proporciona la infraestructura, pero no garantiza por sí solo una arquitectura logística end-to-end con consistencia de estado entre percepción, navegación, manipulación e inventario.

---

## 3.3 Navegación autónoma

Nav2, SLAM Toolbox y AMCL representan soluciones maduras para navegación autónoma en ROS2.

Limitación relevante:

> La navegación autónoma madura como subsistema independiente, pero no resuelve por sí sola la coordinación con manipulación ni la actualización causal del inventario digital.

---

## 3.4 Visión artificial industrial

La familia YOLO, especialmente YOLOv8 y variantes recientes, se usa ampliamente en detección de objetos por su balance entre precisión y latencia. Los marcadores AprilTag/ArUco permiten identificación visual robusta y estimación de pose en escenarios controlados.

Limitación relevante:

> La visión artificial detecta e identifica objetos, pero no garantiza por sí sola que la detección se traduzca en una acción física ejecutada y en una actualización verificable del inventario.

---

## 3.5 Manipulación robótica

MoveIt2 y ros2_control permiten planificación cinemática, control articular y ejecución de trayectorias en manipuladores robóticos.

Limitación relevante:

> La manipulación robótica pierde robustez cuando se desacopla de percepción, navegación y consistencia de estado del sistema.

---

## 3.6 Inventario y sistemas ciberfísicos

Los sistemas ciberfísicos y gemelos digitales permiten representar digitalmente el estado de inventarios, activos y flujos físicos.

Limitación relevante:

> Muchos sistemas CPS observan o modelan inventario, pero no cierran causalmente el ciclo entre ejecución robótica física y actualización digital verificable.

---

# 4. Gap del estado del arte

El gap central identificado es:

> No se identifica una arquitectura ciberfísica basada en ROS2 que integre de forma unificada percepción activa, navegación autónoma, manipulación robótica e inventario digital en un flujo operacional end-to-end, donde la ejecución física de acciones robóticas se refleje de manera consistente y verificable en el estado digital del sistema.

Este proyecto existe para cerrar ese gap en un entorno simulado.

---

# 5. Contribución principal del proyecto

La contribución NO es proponer un nuevo algoritmo de navegación, visión o manipulación.

La contribución es diseñar, implementar y validar una **arquitectura integrada ROS2** que coordine:

- percepción;
- identificación;
- registro digital;
- asignación de ubicación;
- navegación autónoma;
- manipulación física;
- actualización del inventario.

La arquitectura debe demostrar que los subsistemas funcionan como una cadena operacional unificada, no como demos aisladas.

---

# 6. Objetivo general

Diseñar, implementar y validar en simulación una arquitectura ciberfísica basada en ROS2 para automatizar el proceso de inventario y almacenamiento en centros logísticos, integrando percepción visual, navegación autónoma, manipulación robótica y gestión digital de inventario.

---

# 7. Objetivos específicos

1. Diseñar una plataforma AMR diferencial con manipulador serial de 5 GDL y gripper paralelo.
2. Implementar la descripción robótica mediante URDF/Xacro.
3. Simular el sistema en Gazebo Sim y visualizarlo en RViz2.
4. Integrar navegación autónoma mediante Nav2, SLAM Toolbox y AMCL.
5. Integrar manipulación robótica mediante MoveIt2 y ros2_control.
6. Implementar percepción de productos mediante YOLOv8 y marcadores AprilTag/ArUco.
7. Gestionar inventario mediante SQLite.
8. Coordinar el flujo completo mediante un Task Manager/FSM.
9. Validar el flujo end-to-end: detectar, identificar, registrar, asignar ubicación, navegar, depositar y actualizar inventario.
10. Registrar métricas de navegación, percepción, manipulación, inventario y misión.

---

# 8. Flujo operacional obligatorio

```text
Detectar producto
        ↓
Identificar producto
        ↓
Registrar producto en inventario
        ↓
Asignar ubicación disponible
        ↓
Navegar hacia ubicación de almacenamiento
        ↓
Alinear robot / preparar manipulación
        ↓
Depositar producto en estantería
        ↓
Actualizar inventario digital
        ↓
Reportar misión completada
```

Forma compacta:

```text
Detectar → Identificar → Registrar → Asignar → Navegar → Depositar → Actualizar
```

---

# 9. Alcance obligatorio

El sistema final debe incluir:

- ROS2 Jazzy;
- Gazebo Sim;
- RViz2;
- AMR diferencial;
- brazo serial de 5 GDL;
- gripper paralelo;
- LiDAR 2D;
- cámara RGB;
- IMU;
- encoders;
- URDF/Xacro;
- TF2;
- ros2_control;
- Nav2;
- SLAM Toolbox;
- AMCL;
- MoveIt2;
- YOLOv8 o detector equivalente para clase/categoría;
- AprilTag/ArUco para identificación y/o pose;
- SQLite;
- FSM o Task Manager de misión;
- validación por métricas.

---

# 10. Fuera de alcance

No pertenece al proyecto final de Nivel 2:

- hardware real;
- multirobot;
- fleet management;
- Open-RMF;
- aprendizaje por refuerzo;
- ERP/WMS real;
- nube;
- gemelo digital avanzado;
- optimización logística avanzada;
- recuperación de productos;
- manipulación de múltiples productos simultáneos;
- seguridad industrial certificada;
- despliegue en producción.

---

# 11. Definición de éxito conceptual

El proyecto se considera conceptualmente exitoso si demuestra que un AMR con manipulador puede ejecutar en simulación una misión completa de almacenamiento y que el estado digital del inventario cambia como consecuencia directa de la acción robótica ejecutada.

No basta con:

- mostrar el robot en Gazebo;
- compilar el workspace;
- mover la base;
- detectar un marcador;
- planificar una trayectoria del brazo;
- registrar datos en SQLite de forma aislada.

Debe existir integración funcional verificable.

---

# 12. Criterio final de Nivel 2

Nivel 2 queda cerrado únicamente si se demuestra el flujo:

```text
Detectar → Identificar → Registrar → Asignar → Navegar → Depositar → Actualizar
```

con evidencia reproducible de:

- percepción;
- navegación;
- manipulación;
- inventario;
- coordinación del FSM;
- actualización final del estado digital.

---

# 13. Rol del Director Técnico

El Director Técnico debe:

1. preservar el objetivo y gap del proyecto;
2. evitar desviaciones fuera del Nivel 2;
3. exigir evidencia antes de aceptar avances;
4. coordinar Codex y Antigravity;
5. resolver contradicciones entre implementación y documentación;
6. exigir ADR para cambios de arquitectura;
7. mantener `PROJECT_STATE.md` como estado vivo;
8. verificar que las métricas se registren;
9. no declarar completado el proyecto sin validación end-to-end.

---

# 14. Regla de oro

Toda decisión técnica debe responder a esta pregunta:

> ¿Ayuda a demostrar que el sistema puede detectar, identificar, registrar, asignar, navegar, depositar y actualizar inventario de forma integrada?

Si la respuesta es no, la tarea debe posponerse.
