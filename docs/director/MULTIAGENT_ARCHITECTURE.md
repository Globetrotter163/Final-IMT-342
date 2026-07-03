# MULTIAGENT_ARCHITECTURE.md — Arquitectura Operativa Multi-Agente

## 1. ¿Qué es crear un "Agente" en este entorno?

Dado que utilizas plataformas externas desconectadas entre sí (Codex, OpenCode, Antigravity), **"crear un agente"** no significa ejecutar un script automático que los conecte por API. 

Crear un agente significa **abrir una nueva sesión de chat en esa plataforma y dotarla de un contexto estricto**. El agente "nace" cuando le entregas su documento de inicialización (Persona/System Prompt).

Para que trabajen en paralelo sin destruir el código del otro, dependemos de una arquitectura basada en archivos `.md` como medio de comunicación.

---

## 2. Estructura de Archivos Propuesta

Tomando como base lo que ya has pre-implementado, propongo estandarizar el árbol de esta manera:

```text
docs/
├── director/
│   ├── PROJECT_OBJECTIVE_BASELINE.md
│   ├── TECHNICAL_REQUIREMENTS_AND_METRICS.md
│   └── MULTIAGENT_ARCHITECTURE.md          <-- Este documento
├── tasks/
│   ├── README.md
│   ├── TASKS_DIRECTOR.md                   <-- Tareas del Director
│   ├── TASKS_A.md                          <-- Tareas DeepSeek/OpenCode
│   ├── TASKS_B.md                          <-- Tareas GPT/Codex
│   └── TASKS_C.md                          <-- Tareas Gemini/Antigravity
└── agents/
    ├── persona/
    │   ├── CODEX_PERSONA.md                <-- System prompt: "Eres Codex, experto en FSM..."
    │   └── OPENCODE_PERSONA.md             <-- System prompt: "Eres OpenCode, experto en simulación..."
    └── reports/
        ├── CODEX_REPORT_TEMPLATE.md        <-- Plantilla de respuesta obligatoria
        └── OPENCODE_REPORT_TEMPLATE.md
```

### Sí, necesitas un `.md` por cada agente: El archivo `_PERSONA.md`
Este archivo es crucial. Cada vez que abras un chat nuevo en OpenCode o Codex, tu primer mensaje debe ser pegar el contenido de su respectivo `_PERSONA.md`. Este archivo le dice al modelo:
1. Quién es (su rol en el equipo).
2. Qué capas de ROS2 tiene permitido tocar y cuáles NO.
3. Qué formato de reporte debe generar al terminar.

---

## 3. Asignación de Dominios (Aislamiento de Código)

Para trabajar en paralelo en el mismo workspace, la regla de oro es el **Aislamiento por Paquetes**. Si dos agentes modifican el mismo nodo al mismo tiempo, habrá conflictos de Git y de compilación.

* **OpenCode (Gemini/DeepSeek):** `warehouse_gazebo`, `warehouse_robot_description`, `warehouse_perception`.
* **Codex (GPT 5.5):** `warehouse_task_manager` (FSM), `warehouse_navigation`, `warehouse_manipulation`.
* **Antigravity (Director):** Ninguna modificación directa de código sin avisar. Encargado de validación (`colcon build/test`), ROS2 CLI y actualización de estados.

---

## 4. El Protocolo de Trabajo (El Loop Multi-Agente)

Este es el ciclo de vida de un Sprint de trabajo:

### Paso 1: Planificación (Director)
Yo (Antigravity) reviso el `PROJECT_STATE.md` y escribo las tareas necesarias directamente en `docs/tasks/TASKS_A.md`, `docs/tasks/TASKS_B.md` y `docs/tasks/TASKS_C.md`. 

### Paso 2: Inicialización (Humano/PM)
Tú abres las ventanas en tu navegador:
1. **Ventana GPT/Codex:** Pegas el `CODEX.md` y luego el `TASKS_B.md`.
2. **Ventana Gemini/Antigravity:** Pegas el `GEMINI.md` y luego el `TASKS_C.md`.
3. **Ventana DeepSeek/OpenCode:** Pegas el `DEEPSEEK.md` y luego el `TASKS_A.md`.

### Paso 3: Ejecución Paralela (Agentes)
Ambos agentes generan código y lo guardan en tu workspace local (o te dan el código para que lo pegues, según cómo los tengas integrados). Ambos agentes **tienen estrictamente prohibido dar por terminada su respuesta sin antes llenar y guardar su `_REPORT_TEMPLATE.md`**.

### Paso 4: Cierre y Reporte (Agentes)
Los agentes escriben en `docs/agents/reports/` la evidencia de lo que hicieron (archivos tocados, comandos que recomiendan correr).

### Paso 5: Auditoría (Director)
Tú vuelves a mi chat y me dices: *"Los agentes terminaron"*.
Yo leo sus reportes, ejecuto `colcon build`, lanzo la simulación y extraigo las métricas. Si algo falla, escribo el error en sus `_TASKS.md` para que lo corrijan en la siguiente iteración. Si todo pasa, actualizo el `PROJECT_STATE.md`.
