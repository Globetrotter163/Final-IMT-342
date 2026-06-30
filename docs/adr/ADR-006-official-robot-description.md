# ADR-006 - Paquete oficial de descripción robótica

## Estado

Aceptada provisionalmente

## Contexto

Las auditorías detectaron dos paquetes de descripción robótica:

```text
warehouse_robot_description
robot_amr_description
```

`warehouse_robot_description` contiene el URDF/Xacro modular oficial y es usado por Gazebo, MoveIt2 y RViz. `robot_amr_description` contiene una descripción anterior o prototipo legacy.

## Decisión

Declarar como paquete oficial:

```text
warehouse_robot_description
```

Marcar como legacy/duplicado:

```text
robot_amr_description
```

## Justificación

Mantener dos modelos activos puede romper TF, Gazebo, MoveIt2, Nav2, documentación y validación Nivel 2.

## Acción requerida

Antes de eliminar:

```bash
grep -R "robot_amr_description" -n src/ *.md docs || true
```

Si no hay dependencias oficiales, mover a archivo histórico o eliminar en rama separada.
