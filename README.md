particleparty
=============

Learning how vector math works.

Projection Update(v0.1)
---------------
Features:
-Particles projected onto orthographic camera plane
-Camera always points at origin, moves in circle
-Circle sprites replaced with squares for some reason.
Issues:
-Depth sort may not be working correctly
-Center of screen is not center of world, despite the math
-No perspective projection yet, need distortion on projection math.

Initial Commit (v0.0)
---------------
-3D worldspace
-Vector full of brownian particles
-Camera locked to (0,0,-1)
-Screenspace based on x,y worldspace of particles
