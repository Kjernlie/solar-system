#include "solver.h"
#include "solarsystem.h"

Solver::Solver(double dt) :
    m_dt(dt)
{

}

void Solver::Euler(SolarSystem &system)
{
    system.calculateForcesAndEnergy();

    for(CelestialBody &body : system.bodies()) {
        body.position += body.velocity*m_dt;
        body.velocity += body.force / body.mass * m_dt;
    }
}

void Solver::Verlet(SolarSystem &system)
{
    system.calculateForcesAndEnergy();

    for (CelestialBody &body : system.bodies()) {

        body.velocity += body.force / body.mass * m_dt*0.5;
        body.position += body.velocity*m_dt;
    }

    // Need the new forces for the updated velocity
    system.calculateForcesAndEnergy();

    for (CelestialBody &body : system.bodies()){
        body.velocity += body.force / body.mass * m_dt*0.5;  // final velocity
    }
}

