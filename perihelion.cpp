#include <iostream>
#include <cmath>
#include <stdlib.h>
#include "solarsystem.h"
#include "solver.h"
#include "perihelion.h"
using namespace std;

void perihelion()
{
    int years = 20;
    long double dt = 1e-8;
    long double numTimesteps = years/dt;

    SolarSystem solarSystem;

    solarSystem.createCelestialBody( vec3(0,0,0), vec3(0,0,0), 1.0);
    solarSystem.createCelestialBody( vec3(0.3075, 0, 0), vec3(0, 12.44, 0), 1e-7);

    vector<CelestialBody> &bodies = solarSystem.bodies();
    CelestialBody &sun = bodies[0];
    CelestialBody &mercury = bodies[1];

    //double thetaPrevious = 0;
    //double thetaCurrent = 0;

    double rPreviousPrevious = 0;
    double rPrevious = 0;

    vec3 previousPosition(0,0,0);


    Solver integrator(dt);
    for(int timestep=0; timestep<numTimesteps; timestep++) {
        integrator.Verlet(solarSystem);


        double rCurrent = (mercury.position - sun.position).length();

        if ( rCurrent > rPrevious && rPrevious < rPreviousPrevious){

            double x = previousPosition.x();
            double y = previousPosition.y();
            cout << "Perihelion angle: " << atan2(y,x) << endl;
            solarSystem.writeToPerihelionFile("../solar-system/perihelion20_8Newton.txt", atan2(y,x));
        }

        //solarSystem.writeToFile("../solar-system/jupiter_stab_13000_01sdf.txt",timestep);

        rPreviousPrevious = rPrevious;
        rPrevious = rCurrent;
        previousPosition = mercury.position - sun.position;
    }

}


