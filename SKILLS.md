# SKILLS.md — Matched skills necesarios para cerrar Nivel 2

## Skills obligatorios actuales

| Skill | Responsable sugerido | Uso inmediato |
|---|---|---|
| ROS2 Workspace & Build | Codex | estabilizar build, tests y paquetes no trackeados |
| ROS2 Interfaces | Codex | validar msg/srv/action y resolver `/get_product_status` |
| FSM / Action Server | Codex | asegurar `/execute_storage_mission` visible y funcional |
| SQLite / Inventory | Codex | garantizar registro, asignación, actualización y consulta final |
| Gazebo Sim / ros_gz | Antigravity | validar mundo, bridges, cámara, ArUco, sensores |
| URDF/Xacro & TF2 | Antigravity | consolidar `warehouse_robot_description` como modelo oficial |
| ros2_control | Antigravity | validar controladores base, brazo y gripper |
| MoveIt2 | Antigravity | validar `move_group`, `/place_product` y planificación |
| Nav2 / SLAM Toolbox | Ambos | validar navegación con mapa listo y goal válido |
| Documentación / ADR | Codex + Director Técnico | cerrar fuente de verdad y decisiones técnicas |

## Skills críticos para la próxima iteración

### Depuración de grafo ROS

Problema: procesos vivos, pero services/actions no siempre aparecen.

Necesario:

- limpiar daemon;
- aislar launches;
- revisar namespaces;
- revisar logs;
- validar lifecycle;
- verificar delays.

### Validación incremental mock → real

No activar todo real de una vez. Validar progresivamente percepción y manipulación.

### Gestión de DB runtime

Usar DB temporal en pruebas para evitar contaminación de ubicaciones asignadas.

### Consolidación documental

Archivar documentos antiguos y usar `PROJECT_STATE.md` como estado vivo.

## Skills pospuestos

- multirobot;
- aprendizaje por refuerzo;
- ERP/WMS;
- hardware real;
- nube;
- gemelo digital avanzado;
- optimización logística;
- recuperación de productos.
