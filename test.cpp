#ifdef CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE( "Conservation of angular momemtum" ){
    int numTimesteps = 1000;
    SolarSystem solarSystem;
    solarSystem.createCelestialBody( vec3(0,0,0), vec3(0,0,0), 1.0 );
    solarSystem.createCelestialBody( vec3(9.419288875250327E-01,3.422743349115224E-01,-1.774653038679687E-04), vec3(-6.128263831462272E-03,1.611761267097599E-02,1.349643765318894E-07)*365, 3e-6);
    vector<CelestialBody> &bodies = solarSystem.bodies();

    double dt = 0.001;
    vec3 angular_momentum =
    Solver integrator(dt);
    for(int timestep=0; timestep<numTimesteps; timestep++) {
        integrator.Verlet(solarSystem);
    }

#solarSystem.angularMomentum();
    REQUIRED()
}

# Not finished

TEST_CASE( "Conservation of total energy" ){

}

#endif
