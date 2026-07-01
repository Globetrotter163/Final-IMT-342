# PLATAFORMA_A.md — Estado vivo de Plataforma A

## Estado

Sprint S5 en progreso. Interfaces, percepcion e inventario compilan y pasan
validacion, pero la deteccion ArUco real no quedo cerrada dentro de una mision
end-to-end porque Nav2 aborto antes del flujo completo.

## Ultimo trabajo

Reporte S5:
`docs/agents/reports/plataforma_a/ITERATION_2026-07-01_010_sprint_s5_percepcion_inventario.md`

## Evidencia S5

| Area | Estado | Evidencia |
|---|:---:|---|
| Interfaces | OK | `./scripts/sprint_validator.sh` valida 10 interfaces, incluyendo `PickProduct` y `SpawnProduct` |
| Build/test | OK | Build completo 11 paquetes; tests 9/9 sin fallos |
| ArUco | OK parcial | `aruco_detector` arranca en launch integrado cuando `use_mock_perception:=false` |
| Product ID | OK | Contrato S5 usa `mock_product_1` para ArUco 1 |
| SQLite | Bloqueado | DB S5 queda vacia porque la mision aborta por Nav2 antes del registro final |

## Bloqueos

- Falta evidencia runtime de `/detected_products` publicando `mock_product_1`
  durante una mision que llegue a completar el flujo.
- SQLite final no puede validarse hasta que Nav2 permita completar
  `/execute_storage_mission`.

## Proxima tarea

Cuando Plataforma C active Nav2, repetir la mision sin mocks y consultar:

```sql
select product_id,status,storage_location,quantity from products;
select location_id,occupied,product_id from storage_locations where product_id is not null;
```
