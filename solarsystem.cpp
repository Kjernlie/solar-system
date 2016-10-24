#include "solarsystem.h"
#include <iostream>
#include <cmath>
using namespace std;

SolarSystem::SolarSystem() :
    m_kineticEnergy(0),
    m_potentialEnergy(0),
    m_G(4*M_PI*M_PI),
    m_c(63072)
{
}

CelestialBody& SolarSystem::createCelestialBody(vec3 position, vec3 velocity, double mass) {
    m_bodies.push_back( CelestialBody(position, velocity, mass) );
    return m_bodies.back(); // Return reference to the newest added celstial body
}

void SolarSystem::calculateForcesAndEnergy()
{
    m_kineticEnergy = 0;
    m_potentialEnergy = 0;
    m_angularMomentum.zeros();

    for(CelestialBody &body : m_bodies) {
        // Reset forces on all bodies
        body.force.zeros();
    }

    for(int i=0; i<numberOfBodies(); i++) {
        CelestialBody &body1 = m_bodies[i];
        for(int j=i+1; j<numberOfBodies(); j++) {
            CelestialBody &body2 = m_bodies[j];

            // Make the code faster...Don't use vec3
            //double dx = body1.position[0] - body2.position[0];
            //double dy = body1.position[1] - body2.position[1];
            //double dz = body1.position[2] - body2.position[2];
            //double dr2 = dx*dx + dy*dy + dz*dz;
            //double dr = sqrt(dr2);

            vec3 deltaRVector = body1.position - body2.position;
            vec3 deltaRvelocity = body1.velocity - body2.velocity;
            double dr = deltaRVector.length();

            // Calculate the forces
            body1.force -= m_G*body1.mass*body2.mass*deltaRVector / (dr*dr*dr);
            body2.force += m_G*body1.mass*body2.mass*deltaRVector / (dr*dr*dr);

            // For perihelion precession use this force instead
            //double l = (deltaRVector.cross(deltaRvelocity)).length();
            //body1.force -= m_G*body1.mass*body2.mass*deltaRVector / (dr*dr*dr)*(1 + 3*l*l/(dr*dr*m_c*m_c));
            //body2.force += m_G*body1.mass*body2.mass*deltaRVector / (dr*dr*dr)*(1 + 3*l*l/(dr*dr*m_c*m_c));

            // Calculate potential energy and angular momentum
            m_potentialEnergy += - m_G*body1.mass*body2.mass / dr;
            m_angularMomentum += body2.mass*body2.position.cross(body2.velocity);
        }

        m_kineticEnergy += 0.5*body1.mass*body1.velocity.lengthSquared();
        //m_angularMomentum += body1.mass*body1.position.cross(body1.velocity);
    }
}

int SolarSystem::numberOfBodies() const
{
    return m_bodies.size();
}

double SolarSystem::totalEnergy() const
{
    return m_kineticEnergy + m_potentialEnergy;
}

double SolarSystem::potentialEnergy() const
{
    return m_potentialEnergy;
}

double SolarSystem::kineticEnergy() const
{
    return m_kineticEnergy;
}

void SolarSystem::writeToFile(string filename, int timestep)
{
    if(!m_file.good()) {
        m_file.open(filename.c_str(), ofstream::out);
        if(!m_file.good()) {
            cout << "Error opening file " << filename << ". Aborting!" << endl;
            terminate();
        }
    }

    m_file << "The number of planets is: " << numberOfBodies() << endl;
    m_file << "This is timestep: " << timestep << endl;
    for(CelestialBody &body : m_bodies) {
        m_file << "1 " << body.position.x() << " " << body.position.y() << " " << body.position.z() << "\n";
    }
}

void SolarSystem::writeToPerihelionFile(string filename, double angle)
{
    if(!m_file.good()) {
        m_file.open(filename.c_str(), ofstream::out);
        if(!m_file.good()) {
            cout << "Error opening file " << filename << ". Aborting!" << endl;
            terminate();
        }
    }

    m_file << angle << "\n";
}

vec3 SolarSystem::angularMomentum() const
{
    return m_angularMomentum;
}

std::vector<CelestialBody> &SolarSystem::bodies()
{
    return m_bodies;
}
