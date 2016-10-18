#ifndef CATCH_CONFIG_MAIN
#include <iostream>
#include <cmath>
#include <stdlib.h>
#include "solarsystem.h"
#include "solver.h"
using namespace std;

int main(int numArguments, char **arguments)
{
    int numTimesteps = 1000;
    if(numArguments >= 2) numTimesteps = atoi(arguments[1]);

    SolarSystem solarSystem;
    // We create new bodies like this. Note that the createCelestialBody function returns a reference to the newly created body
    // This can then be used to modify properties or print properties of the body if desired
    // Use with: solarSystem.createCelestialBody( position, velocity, mass );

    CelestialBody &sun = solarSystem.createCelestialBody( vec3(0,0,0), vec3(0,0,0), 1.0 );

    // We don't need to store the reference, but just call the function without a left hand side
    solarSystem.createCelestialBody( vec3(1, 0, 0), vec3(0, 2*M_PI, 0), 3e-6 );
    //solarSystem.createCelestialBody( vec3(9.419288875250327E-01,3.422743349115224E-01,-1.774653038679687E-04), vec3(-6.128263831462272E-03,1.611761267097599E-02,1.349643765318894E-07)*365, 3e-6);

    // Escape velocity...
    //solarSystem.createCelestialBody( vec3(1,0,0), vec3(0,8.89,0), 3e-6);

    // Jupyter
    //solarSystem.createCelestialBody( vec3(-5.429616996509673E+00,-4.392482185767863E-01,1.232526518227290E-01), vec3(5.206515353907882E-04,-7.164038754622682E-03,1.814205403145239E-05)*365, 1e-3);

    // To get a list (a reference, not copy) of all the bodies in the solar system, we use the .bodies() function
    vector<CelestialBody> &bodies = solarSystem.bodies();

    for(int i = 0; i<bodies.size(); i++) {
        CelestialBody &body = bodies[i]; // Reference to this body
        cout << "The position of this object is " << body.position << " with velocity " << body.velocity << endl;
    }

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
        solarSystem.writeToFile("../solar-system/positions_veloutorbit.txt",timestep);
    }

    cout << "I just created my first solar system that has " << solarSystem.bodies().size() << " objects." << endl;

    //cout << "The kinetic energy is " << solarSystem.kineticEnergy() << endl;
    //cout << "The potential energy is " << solarSystem.potentialEnergy() << endl;
    //cout << "The total energy is " << solarSystem.totalEnergy() << endl;
    //cout << "The angular momementum is " << solarSystem.angularMomentum() << endl;
    cout << min_kin << endl;

    double rel_err_kin = abs(max_kin - min_kin)/abs(max_kin);
    double rel_err_pot = abs(max_pot - min_pot)/abs(max_pot);
    double rel_err_tot = abs(max_tot - min_tot)/abs(max_tot);

    cout << "The maximum error for total energy conservation is " << rel_err_tot << endl;
    cout << "The maximum error for kinetic energy conservation is " << rel_err_kin << endl;
    cout << "The maximum error for potential energy conservation is " << rel_err_pot << endl;
    return 0;

}

#endif

// Skriv #ifdef #endif i fila catch klasse fila

