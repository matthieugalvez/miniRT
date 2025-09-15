# miniRT

![title]('/assets/readme_pictures/title.png')

MiniRT is a basic Raytracer with implementation of geometric primitives (sphere, plan, cylinder, cone), Phong reflection model, texture and bump map.


## Installation

Use make to build miniRT executable binary.

```
make
```


## Launch

Execute the miniRT binary with a scene configuration file (.rt) entered as argument.

```
miniRT <confFile>
```

## Configuration File

Configuration files are identified by the `.rt` filename extension. Sample files are included in the 'scenes' and 'test' directories of the repository.

Each line in the configuration file define an element in the generated scene. A line must start with the element identifier followed by its parameters.

### Mandatory entries

A valid configuration file must contain strictly one of the following elements.

#### Camera

```
C <coordinates> <orientation> <FOV>
```
The camera is defined by identifier `C` then the following parameters:

`<coordinates>` A trio of floating point numbers formated as `x,y,z` defining the original position of the camera.

`<orientation>` A normalized orientation vector formated as `x,y,z` defining the original orientation of the camera. Numbers must be in range `[-1,1]`.

`<FOV>` A integer in range `[0,180]` defining the original horizontal field of view of the camera.

#### Ambiant Light

```
A <ratio> <color>
```
The ambiant light is defined by identifier `A` then the following parameters:

`<ratio>` A floating point number in range `[0.0,1.0]` defining the brightness ratio of the ambiant light.

`<color>` A trio of integers in range `[0,255]` formated as `r,g,b` defining the color of the ambiant light.

### Additional entries

A valid configuration file can contain any number of the following elements.

#### Light source

```
L <coordinates> <ratio> <color>
```
A light source is defined by identifier `L` then the following parameters:

`<coordinates>` A trio of floating point numbers formated as `x,y,z` defining the original position of the light source.

`<ratio>` A floating point number in range `[0.0,1.0]` defining the intensity ratio of the light source.

`<color>` A trio of integers in range `[0,255]` formated as `r,g,b` defining the color of the light source.

#### Object

##### Sphere

```
sp <coordinates> <diameter> <color> { [secondaryColor] || [textureFile] [bumpMapFile] }
```

##### Plane

```
pl <coordinates> <axis> <color> { [secondaryColor] || [textureFile] }
```

##### Cylinder

```
cy <coordinates> <axis> <diameter> <height> <color> { [secondaryColor] || [textureFile] }
```

##### Cone

```
co <coordinates> <axis> <diameter> <height> <color> { [secondaryColor] || [textureFile] }
```

`<coordinates>` A trio of floating point numbers formated as `x,y,z` defining the object center original position.

`<axis>` A normalized orientation vector formated as `x,y,z` defining the original axis of the object. Numbers must be in range `[-1,1]`.

`<diameter>` A floating point number defining the original diameter of the object.

`<height>` A floating point number defining the original height of the object.

`<color>` A trio of integers in range `[0,255]` formated as `r,g,b` defining the color of the object.

`[secondaryColor]` A trio of integers in range `[0,255]` formated as `r,g,b` defining the secondary color of the object. The presence of this second color will draw a checkerboard as the object texture.

`[textureFile]` The path toward an xpm file that will be applied to the object as its texture.

`[bumpMapFile]` The path toward an xpm file that will be applied to the object as its bump map texture.


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
