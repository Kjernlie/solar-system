#include <iostream>
#include <cmath>
#include <stdlib.h>
#include "solarsystem.h"
#include "solver.h"
using namespace std;

void twobody()
{
    int numTimesteps = 13000;
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

    double max_kin = 0;
    double max_pot = 0;
    double max_tot = 0;

    double min_kin = 1;
    double min_pot = 1;
    double min_tot = 1;

    double dt = 0.01;
    Solver integrator(dt);
    for(int timestep=0; timestep<numTimesteps; timestep++) {
        integrator.Verlet(solarSystem);
        if (abs(solarSystem.kineticEnergy()) > max_kin ){
            max_kin = solarSystem.kineticEnergy();
        }
        if (abs(solarSystem.potentialEnergy()) > max_pot){
            max_pot = solarSystem.potentialEnergy();
        }
        if (abs(solarSystem.totalEnergy()) > max_tot){
            max_tot = solarSystem.totalEnergy();
        }

        if (abs(solarSystem.kineticEnergy()) < min_kin ){
            min_kin = solarSystem.kineticEnergy();
        }
        if (abs(solarSystem.potentialEnergy()) < min_pot){
            min_pot = solarSystem.potentialEnergy();
        }
        if (abs(solarSystem.totalEnergy()) < min_tot){
            min_tot = solarSystem.totalEnergy();
        }
        solarSystem.writeToFile("../solar-system/jupiter_stab_13000_01sdf.txt",timestep);
    }

    //cout << "I just created my first solar system that has " << solarSystem.bodies().size() << " objects." << endl;

    cout << "The kinetic energy is " << solarSystem.kineticEnergy() << endl;
    cout << "The potential energy is " << solarSystem.potentialEnergy() << endl;
    cout << "The total energy is " << solarSystem.totalEnergy() << endl;
    cout << "The angular momementum is " << solarSystem.angularMomentum() << endl;

    double rel_err_kin = abs(max_kin - min_kin)/abs(max_kin);
    double rel_err_pot = abs(max_pot - min_pot)/abs(max_pot);
    double rel_err_tot = abs(max_tot - min_tot)/abs(max_tot);

    cout << "The maximum error for total energy conservation is " << rel_err_tot << endl;
    cout << "The maximum error for kinetic energy conservation is " << rel_err_kin << endl;
    cout << "The maximum error for potential energy conservation is " << rel_err_pot << endl;


}

