# warehouse_navigation

Scaffold for navigation integration.

Files:
- `launch/navigation_launch.py` — minimal launch that attempts to include `nav2_bringup` if available.
- `config/nav2_params.yaml` — placeholder parameters for Nav2 components (use_sim_time enabled).

Usage (when Nav2 is installed):

```bash
source install/setup.bash
ros2 launch warehouse_navigation navigation_launch.py
```
