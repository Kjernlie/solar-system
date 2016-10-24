#include <iostream>
#include <cmath>
#include <stdlib.h>
#include "solarsystem.h"
#include "solver.h"
#include <armadillo>
#include <iomanip>
using namespace std;

void twobody()
{
    int numTimesteps = 1500;
    //if(numArguments >= 2) numTimesteps = atoi(arguments[1]);

    SolarSystem solarSystem;




    // Adding celastial bodies

    // Two body system
    // -----------------------------------------------------------------------------

    // Sun
    CelestialBody &sun = solarSystem.createCelestialBody( vec3(0,0,0), vec3(0,0,0), 1.0 );

    solarSystem.createCelestialBody( vec3(1, 0, 0), vec3(0, 2*M_PI, 0), 3e-6 );

    // Escape velocity...
    //solarSystem.createCelestialBody( vec3(1,0,0), vec3(0,8.89,0), 3e-6);




//    // To get a list (a reference, not copy) of all the bodies in the solar system, we use the .bodies() function
//    vector<CelestialBody> &bodies = solarSystem.bodies();

//    for(int i = 0; i<bodies.size(); i++) {
//        CelestialBody &body = bodies[i]; // Reference to this body
//        cout << "The position of this object is " << body.position << " with velocity " << body.velocity << endl;
//    }

    clock_t start, finish;
    start = clock();

    double dt = 0.001;
    Solver integrator(dt);
    for(int timestep=0; timestep<numTimesteps; timestep++) {
        integrator.Euler(solarSystem);


        solarSystem.writeToFile("../solar-system/jupiter_stab_13000_01sdf.txt",timestep);
    }

    finish = clock();
    double timeused = (double) (finish - start)/(CLOCKS_PER_SEC );
    cout << "Time used is  = " << timeused << " s" << endl;

    //cout << "I just created my first solar system that has " << solarSystem.bodies().size() << " objects." << endl;

    cout << "The kinetic energy is " << solarSystem.kineticEnergy() << endl;
    cout << "The potential energy is " << solarSystem.potentialEnergy() << endl;
    cout << "The total energy is " << solarSystem.totalEnergy() << endl;
    cout << "The angular momementum is " << solarSystem.angularMomentum()[2] << endl;

}

