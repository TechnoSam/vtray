NOTES:

On Linux, correct operation is RANDOM. I cannot figure out why this is.
Most of the time it works, but sometimes it just doesn't.

The camera clipping felt exceptionally sneaky. Caused a lot of problems
and fundamentally doesn't make sense.

Modules:

-Scene-
Contains a camera, vector of lights, vector of planes, and a vector of
spheres. I wanted to do a single unified vector of objects instead of
breaking it up into planes and spheres, but I kept running into issues
that should have been simple to fix but I just couldn't for some reason.

The scene contains all the information about what to draw, so it is in
charge of returning pixel color values using ray tracing.

-Camera-
Contains all the attributes as given in the JSON.
Supplies a method to generate rays to a given pixel from the focus.

-Light-
This probably could have been a struct, it's just a container for the JSON
data.

-Object-
Contains a color and lambert, which all objects must have.
Also has a method that returns the distance to intersection from a given
ray. This distance is infinity if there is no intersection. Arithmitic
will give us the actual intersection location if we want it.

This allows all objects to be known to have certain behavior. The benefits
did not pan out due to complications.

-Sphere: Object-
Inherits from Object and adds a center and radius.

-Plane: Object-
Inherits from Object and adds a center and normal.

-Ray-
Contains two geometric vectors, origin and destination. From these, the
direction can be easily computed.

-Vec3-
A 3D geometric vector. Defines dot/cross product as well as overloaded
operators to make math easy. 

-Color-
Contains RGB values with overloaded operators to make math easy. Also supports
scaling.

Putting them together:

Ultimately, the Scene is responsible for everything. Colors, Vec3s and Rays
form the base operations, following the Ray Tracing algorithm. This algorithm
got quite tricky once I had to account for clipping and roundoff. I'm not too
happy with the current state of the algorithm. 

Sources:

https://www.scratchapixel.com/lessons/3d-basic-rendering/introduction-to-ray-tracing/how-does-it-work

This site provided most of the high level algorithms I used like object
intersection.

I used Dr. Wyatt's help for camera rotation.
