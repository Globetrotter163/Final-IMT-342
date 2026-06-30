# ADR-005 - Uso de ROS2 Jazzy y Gazebo Sim

## Estado

Aceptada provisionalmente

## Contexto

El baseline original mencionaba ROS2 Humble. Las auditorías muestran que el workspace actual trabaja sobre ROS2 Jazzy, Gazebo Sim / ros_gz y adaptaciones específicas como `TwistStamped` para la ruta de control de la base.

## Decisión

Formalizar ROS2 Jazzy + Gazebo Sim / ros_gz como stack real actual del repositorio.

## Justificación

- El estado real del repositorio ya está implementado en Jazzy.
- Gazebo Sim / ros_gz ya se encuentra integrado.
- Nav2, MoveIt2 y ros2_control están configurados en ese entorno.
- Revertir a Humble introduciría regresiones innecesarias.

## Consecuencias

Positivas:

- conserva avance funcional;
- reduce ambigüedad;
- evita mezclar instrucciones Humble con ejecución Jazzy.

Negativas:

- rompe el baseline inicial;
- obliga a actualizar documentación;
- cualquier reporte académico debe explicar claramente el entorno usado.
