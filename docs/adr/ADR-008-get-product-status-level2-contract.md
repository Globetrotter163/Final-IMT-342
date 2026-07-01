# ADR-008 - Retiro de `/get_product_status` del contrato Nivel 2

## Estado

Aceptada provisionalmente

## Contexto

Las auditorias de Nivel 2 registraban `/get_product_status` como brecha porque el servicio no existe en `warehouse_interfaces` ni en `warehouse_inventory`.

El flujo requerido para Nivel 2 es:

```text
Detectar -> Identificar -> Registrar -> Asignar ubicacion -> Navegar -> Depositar -> Actualizar inventario
```

Ese flujo queda cubierto por:

- `/register_product`
- `/assign_storage_location`
- `/update_inventory`
- `/execute_storage_mission`

La evidencia de estado final de inventario durante validacion controlada puede obtenerse desde una DB SQLite temporal, sin ampliar el contrato ROS de Nivel 2.

## Decision

Retirar `/get_product_status` del contrato obligatorio de Nivel 2.

No se implementa en este sprint de validacion controlada.

## Justificacion

- No forma parte del flujo operativo minimo exigido para Nivel 2.
- Implementarlo agregaria superficie nueva de interfaz en un sprint cuyo objetivo es estabilizar integracion existente.
- La validacion de inventario ya queda cubierta por servicios existentes y consulta directa a la DB temporal de prueba.

## Consecuencias

Positivas:

- Reduce cambios funcionales fuera del alcance inmediato.
- Mantiene el contrato Nivel 2 enfocado en registro, asignacion y actualizacion.
- Evita bloquear cierre de evidencia software por un servicio consultivo no usado por el FSM.

Negativas:

- No existe endpoint ROS para consultar estado de producto desde otros nodos.
- Si una UI, dashboard, auditor externo o recuperacion futura lo requiere, debera definirse una nueva interfaz y prueba dedicada.

## Accion futura

Si Nivel 3 o integracion final requiere consulta por producto, crear un ADR nuevo e implementar un servicio explicitamente versionado, por ejemplo `GetProductStatus.srv`, con pruebas de contrato y tests de DB.
