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

### Mandatory entries

#### Camera

#### Ambiant Light

### Additional entries

#### Light source

#### Object


## Controls

```
tab
```
Display controls

```
escape
```
Close window

```
space
```
Select next object

```
return
```
Select camera

```
W A S D
```
Translate selected object

```
Q E
```
Change selected object elevation

```
arrows
```
Rotate selected object

```
- +
```
Resize selected object or change the Field of View is camera is selected

```
/ *
```
Change object height (cylinder or cone only)

```
M
```
Select next light source

```
I J K L
```
Translate selected light source

```
U O
```
Change selected light source elevation

```; P```
Dim selected light source down or up
