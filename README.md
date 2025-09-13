# miniRT

MiniRT is a basic Raytracer with implementation of geometric primitives (sphere, plan, cylinder, cone), Phong reflection model, texture and bump map.


## Installation

Use make to build miniRT executable binary.

```bash
make
```


## Launch

Execute the miniRT binary with a scene configuration file (.rt) entered as argument.

```bash
miniRT <confFile>
```

## Configuration File

Configuration files are identified by the '.rt' filename extension. Sample files are included in the 'scenes' and 'test' directories of the repository.

Each line in the configuration file define an element in the generated scene. A line must start with the element identifier followed by its parameters.

### Mandatory entries

A valid configuration file must contain strictly one of the following elements.

#### Camera

```
C <coordinates> <orientation> <FOV>
```
The camera is defined by identifier `C` then the following parameters:

`<coordinates>` A trio of floating point numbers formated as `x,y,z` defining the original position of the camera.

#### Ambiant Light

### Additional entries

#### Light source

#### Object


## Controls

`tab` Display controls

`escape` Close window

`space` Select next object

`return` Select camera

`w a s d` Translate selected object

`q e` Change selected object elevation

`arrows` Rotate selected object

`- +` Resize selected object or change the Field of View is camera is selected

`/ *` Change object height (cylinder or cone only)

`m` Select next light source

`i j k l` Translate selected light source

`u o` Change selected light source elevation

`; p` Dim selected light source down or up
