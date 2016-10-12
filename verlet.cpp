#include "verlet.h"
#include "solarsystem.h"

Verlet::Verlet(double dt) :
    m_dt(dt)
{

}

void Verlet::integrateOneStep(SolarSystem &system)
{
    system.calculateForcesAndEnergy();

    for (CelestialBody &body : system.bodies()) {
        body.position += body.velocity*m_dt + body.force / body.mass *m_dt*m_dt*0.5;
        body.velocity += body.force / body.mass * m_dt*0.5;
    }

    // Need the new forces for the updated position
    system.calculateForcesAndEnergy();

    for (CelestialBody &body : system.bodies()){
        body.velocity += body.force / body.mass * m_dt*0.5;  // final velocity
    }
}
