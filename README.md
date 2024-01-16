# StatsOfIndia_3DVisualization

## Overview

The StatsOfIndia Visualization Project is a C++ project that utilizes Qt and OpenGL to create a graphical representation of statistical data related to the population, education, and area of various states in India. The project consists of a dynamic DLL for data reading, a GUI application for visualization, and an OpenGL window for rendering the graphical representation.

## Contents

- **StatsDataReader:** Dynamic Link Library (DLL) responsible for reading statistical data and providing it to the GUI application.
- **StatsOfIndia:** GUI application developed using Qt for visualizing statistical data.
- **OpenGLWindow:** Custom OpenGL widget for rendering the graphical representation of data.
- **Shaders:** Vertex and fragment shader files for OpenGL rendering.

## Software Used

- Qt
- C++ Compiler
- OpenGL

## Building and Running

1. **Build the DLL:**
   - Open the `StatsDataReader` project in your preferred C++ development environment.
   - Build the project to generate the DLL file.

2. **Build the GUI Application:**
   - Open the `StatsOfIndia` project in Qt Creator or your preferred Qt development environment.
   - Build the project to generate the executable file.

3. **Run the Application:**
   - Run the generated executable from the `StatsOfIndia` project.

## Usage

- Upon running the application, you will be presented with a GUI window displaying statistical data related to Indian states.
- Choose a parameter (Population, Education, or Area) from the dropdown menu.
- The OpenGL window will display a graphical representation of the chosen parameter for each state.
- Use the mouse to interact with the 3D visualization, and the mouse wheel to zoom in and out.

## Class Diagram
![StatsOfIndia](https://github.com/ashishkamblecctech/StatsOfIndia_3DVisualization/assets/149309502/3254e36b-003d-445d-aed4-329362ac960c)

## Output Video
https://github.com/ashishkamblecctech/StatsOfIndia_3DVisualization/assets/149309502/95d70a95-10ca-4da3-be13-4ecc637a2102

## Doxygen Files:
![geometry_doxygen](https://github.com/ashishkamblecctech/StatsOfIndia_3DVisualization/assets/149309502/47fd21a5-1373-4e31-b102-00aabad81850)

![StatsDataReader_doxygen](https://github.com/ashishkamblecctech/StatsOfIndia_3DVisualization/assets/149309502/13095d9c-0298-4d31-b648-11c63541911a)

![OpenGL_doxygen](https://github.com/ashishkamblecctech/StatsOfIndia_3DVisualization/assets/149309502/52d222d6-7130-491a-ab53-07b5eaed2e13)

![StatsOfIndia_doxygen](https://github.com/ashishkamblecctech/StatsOfIndia_3DVisualization/assets/149309502/2b6cd7c2-06e1-4e07-bccf-86054fa0332b)
