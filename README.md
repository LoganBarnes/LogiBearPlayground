Logi Bear Playground
====================


Unix
----

```bash
cd run
./unixConfigureAndBuild.sh
./bin/run<Project>
```


Windows
-------

Use the Developer Command Prompt for VS to ensure the *MSBuild.exe* path is set.

```bash
cd run
winConfigureAndBuild.cmd
bin/run<Project>
```


Projects
--------
### Common:
Simple update loop and project setup files used by most other projects

### Graphics:
OpenGL based render pipeline used by graphical projects

### OPGraphics (soon):
Vulkan based experimental project

### DX (soon):
DirectX 12 based experimental project
