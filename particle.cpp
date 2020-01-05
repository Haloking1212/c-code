//Vincent Perez
//nov 2019
//particle

#include <iostream>
#include <cmath>
#include <math.h>
using namespace std;

//gives coordinate in 3d plane or creates coordinate on 3d plane
class Coord3D
{
public:
	double x;
	double y;
	double z;

};
//class for new particle object
class Particle
{
public:
    double x, y ,z;
    double vx, vy, vz;
};
//creates new particle object with 3 velocity vectors and 3 coordinates
Particle *createParticle(double x, double y, double z, double vx, double vy, double vz)
{
    Particle *newObject = new Particle;
    *newObject = {x,y,z,vx,vy,vz};
    return newObject;
}
//changes the velocity to velocity given
void setVelocity(Particle *p, double vx, double vy, double vz)
{
    p->vx = vx;
    p->vy = vy;
    p->vz = vz;
}
//gets the position of x y and z values in 3d plane
Coord3D getPosition(Particle *p)
{
    Coord3D pos = {p->x, p->y, p->z};
    return pos;
}
//moves according to vector
void move(Particle *p, double dt)
{
    p->x = p->x + p->vx * dt;
    p->y = p->y + p->vy * dt;
    p->z = p->z + p->vz * dt;
}
//deletes the memory particle is stored in
void deleteParticle(Particle *p)
{
    delete[] p;
}

int main()
{
    // make new particle
    Particle *p = createParticle(1.0, 1.5, 2.0, 0.1, 0.2, 0.3);
    double time = 0.0;
    double dt = 0.1;
    while(time < 2.0) {
        // update its velocity
        setVelocity(p, 10.0 * time, 1.3, 5.1);

        // move the particle
        move(p, dt);
        time += dt;

        // reporting its coordinates
        cout << "Time: " << time << " \t";
        cout << "Position: "
             << getPosition(p).x << ", "
             << getPosition(p).y << ", "
             << getPosition(p).z << endl;
    }
    // remove the particle, deallocating its memory
    deleteParticle(p);
}