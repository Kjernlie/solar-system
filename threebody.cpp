#include <iostream>
#include <cmath>
#include <stdlib.h>
#include "solarsystem.h"
#include "solver.h"
#include "threebody.h"
using namespace std;

void threebody()
{
    int numTimesteps = 13000;
    //if(numArguments >= 2) numTimesteps = atoi(arguments[1]);

    SolarSystem solarSystem;



    // Declere the planet's coordinates.
    vec3 r_sun_suncenter = vec3(0,0,0);
    vec3 r_earth_suncenter = vec3(1,0,0);
    vec3 r_jupiter_suncenter = vec3(5.20,0,0);
    vec3 r_sun = vec3(3.569552387089993E-03, 3.395883113303513E-03, -1.598805663679657E-04);
    vec3 r_earth = vec3(9.419288875250327E-01, 3.422743349115224E-01, -1.774653038679687E-04);
    vec3 r_jupiter = vec3(-5.429616996509673E+00, -4.392482185767863E-01, 1.232526518227290E-01);


    // Declare the masses
    double mSun = 1.0;
    double mEarth = 3e-6;
    double mJupiter = 1e-3;
    double M_three = mSun + mEarth + mJupiter;

    // Calculate the center of mass
    vec3 R_three = (r_sun_suncenter*mSun + r_earth_suncenter*mEarth + r_jupiter_suncenter*mJupiter)/M_three;


    // Declare the velocities
    vec3 v_sun = vec3(-1.978871917569178E-06, 6.843726881579374E-06, 4.032140462891743E-08)*365;
    vec3 v_earth = vec3(-6.128263831462272E-03, 1.611761267097599E-02, 1.349643765318894E-07)*365;
    vec3 v_jupiter = vec3(5.206515353907882E-04, -7.164038754622682E-03, 1.814205403145239E-05)*365;

    // Find the total momomentum...You can make a function of this...
    vec3 p_three =  v_sun*mSun + v_earth*mEarth + v_jupiter*mJupiter;


    // Total velocity
    vec3 v_total_three = p_three/M_three;


    // Adding celastial bodies


    // Three body system
    // ----------------------------------------------------------------------------

    // Sun
    //solarSystem.createCelestialBody( vec3(0,0,0) - R_three, vec3(0,0,0) - v_total_three, mSun);
    solarSystem.createCelestialBody(r_sun, v_sun, mSun);
    //solarSystem.createCelestialBody( r_sun - R_three, v_sun - v_total_three, mSun);

    // Earth
    //solarSystem.createCelestialBody( vec3(1,0,0) - R_three, v_earth - v_total_three, mEarth);
    //solarSystem.createCelestialBody( r_earth - R_three, v_earth - v_total_three, mEarth);
    solarSystem.createCelestialBody( r_earth, v_earth, mEarth);

    // Jupiter
    //solarSystem.createCelestialBody( vec3(5.20, 0, 0) - R_three, v_jupiter - v_total_three, mJupiter);
    //solarSystem.createCelestialBody( r_jupiter - R_three, v_jupiter - v_total_three, mJupiter);
    solarSystem.createCelestialBody( r_jupiter, v_jupiter, mJupiter);







//    // To get a list (a reference, not copy) of all the bodies in the solar system, we use the .bodies() function
//    vector<CelestialBody> &bodies = solarSystem.bodies();

//    for(int i = 0; i<bodies.size(); i++) {
//        CelestialBody &body = bodies[i]; // Reference to this body
//        cout << "The position of this object is " << body.position << " with velocity " << body.velocity << endl;
//    }


    double dt = 0.01;
    Solver integrator(dt);
    for(int timestep=0; timestep<numTimesteps; timestep++) {
        integrator.Verlet(solarSystem);
        solarSystem.writeToFile("../solar-system/jupiter_stab_13000_01sdf.txt",timestep);
    }

    //cout << "I just created my first solar system that has " << solarSystem.bodies().size() << " objects." << endl;

    cout << "The kinetic energy is " << solarSystem.kineticEnergy() << endl;
    cout << "The potential energy is " << solarSystem.potentialEnergy() << endl;
    cout << "The total energy is " << solarSystem.totalEnergy() << endl;
    cout << "The angular momementum is " << solarSystem.angularMomentum() << endl;



}

