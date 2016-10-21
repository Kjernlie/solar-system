#ifdef CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "solarsystem.h"
#include "vec3.h"
#include "celestialbody.h"
#include "solver.h"
#include <cmath>
#include <iostream>
using namespace std;

// Idiot! Put in a circular orbit, then we'll see!!!!

TEST_CASE( "Conservation of angular momemtum" ){
    SolarSystem solarSystem;
    solarSystem.createCelestialBody( vec3(0,0,0), vec3(0,0,0), 1.0 );
    solarSystem.createCelestialBody( vec3(1, 0, 0), vec3(0, 2*M_PI, 0), 3e-6 );

    double dt = 0.001;

    Solver integrator(dt);
    for(int timestep=0; timestep<100; timestep++) {
        integrator.Verlet(solarSystem);
    }
    vec3 angVec100 = solarSystem.angularMomentum();

    for (int timestep = 0; timestep<500; timestep++){
        integrator.Verlet(solarSystem);
    }
    vec3 angVec500 = solarSystem.angularMomentum();

    double tolerance = 1e-4;

    REQUIRE( abs(angVec100.length() - angVec500.length()) < tolerance );
}

// So, it passes for a tolerance of 1e-4, nothing more. Can that be correct....

TEST_CASE( "Conservation of kinetic energy" ){
    SolarSystem solarSystem;
    solarSystem.createCelestialBody( vec3(0,0,0), vec3(0,0,0), 1.0 );
    solarSystem.createCelestialBody( vec3(1, 0, 0), vec3(0, 2*M_PI, 0), 3e-6 );
    double dt = 0.001;
    Solver integrator(dt);
    for (int timestep = 0; timestep < 100; timestep++){
        integrator.Verlet(solarSystem);
    }
    double kinEn100 = solarSystem.kineticEnergy();

    for (int timestep = 0; timestep < 100; timestep++){
        integrator.Verlet(solarSystem);
    }
    double kinEn500 = solarSystem.kineticEnergy();

    double tolerance = 1e-6;
    REQUIRE( abs(kinEn100 - kinEn500) < tolerance );
}

TEST_CASE( "Conservation of potential Energy" ){
    SolarSystem solarSystem;
    solarSystem.createCelestialBody( vec3(0,0,0), vec3(0,0,0), 1.0 );
    solarSystem.createCelestialBody( vec3(1, 0, 0), vec3(0, 2*M_PI, 0), 3e-6 );
    double dt = 0.001;
    Solver integrator(dt);
    for (int timestep = 0; timestep < 100; timestep++){
        integrator.Verlet(solarSystem);
    }
    double potEn100 = solarSystem.potentialEnergy();

    for (int timestep = 0; timestep < 100; timestep++){
        integrator.Verlet(solarSystem);
    }
    double potEn500 = solarSystem.potentialEnergy();

    double tolerance = 1e-6;
    REQUIRE( abs(potEn100 - potEn500) < tolerance );
}


#endif
