# StarletMath
A lightweight header-only math library for **Starlet** projects designed with OpenGL engines in mind.

⚠️ **Note**
This is **NOT** intended to be a complete math library!
It's minimal and straightforward to make the math operations easier to understand and extend.
This makes it perfect for learning, experimentation, but not a drop-in replacement for full-fledged math libraries.

## Features

- Basic vector types: `Vec2`, `Vec3`, `Vec4`
- `Transform` struct for position, rotation, scale
- `Mat4` 4x4 matrix with:
    - Identity, transpose, inverse
    - Translation, rotation, scaling
    - `lookAt` and `perspective` helpers
    - Composition with `Transform`
- Constants and helpers:
    `pi`, `radians()`, `degrees()`
- **Starlet** Project Constants

## Using as a Dependency

```cmake
include(FetchContent)

FetchContent_Declare(StarletMath GIT_REPOSITORY https://github.com/Masonlet/StarletMath.git GIT_TAG main)
FetchContent_MakeAvailable(StarletMath)

target_link_libraries(YourAppName PRIVATE StarletMath)
```

