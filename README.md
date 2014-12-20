5-Layered-Chess-Board
=====================

This isn't so much of a game than just an example of what a 5 layered chess board would look like. I have all the possible moves/directions for a knight, rook, bishop and queen.  I wanted to keep this simulation very simple, so their movements are chosen at random, moving only one space.

GLUT setup
==========

Include your GLUT files in your project properties.
C/C++ -> General -> Additional Include Directories: add the folder where the GLUT include file is located.
Linkers -> General -> Additional Lirbary Directories: add the folder where the GLUT library file is located.
Linkers -> Input -> add the following:
opengl32.lib
glu32.lib
freeglut.lib
glut32.lib

Models
======

I used the same pawn model as in my Snakes and Ladders project.
Add the .mtl and the .obj files in the project's folder.
If you create your own, the scaling might need some tweaking.
