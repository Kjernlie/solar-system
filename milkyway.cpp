#include <iostream>
#include <cmath>
#include <stdlib.h>
#include "solarsystem.h"
#include "solver.h"
#include "milkyway.h"
using namespace std;

void milkyway()
{
    int numTimesteps = 13000;

    SolarSystem solarSystem;



    // Declere the planet's coordinates.
    vec3 r_sun_suncenter = vec3(0,0,0);
    vec3 r_earth_suncenter = vec3(1,0,0);
    vec3 r_jupiter_suncenter = vec3(5.20,0,0);
    vec3 r_sun = vec3(3.569552387089993E-03, 3.395883113303513E-03, -1.598805663679657E-04);
    vec3 r_earth = vec3(9.419288875250327E-01, 3.422743349115224E-01, -1.774653038679687E-04);
    vec3 r_jupiter = vec3(-5.429616996509673E+00, -4.392482185767863E-01, 1.232526518227290E-01);
    vec3 r_mercury = vec3(-3.299771220462327E-01,  1.314596035268270E-01,  4.090462570196151E-02);
    vec3 r_venus = vec3(1.619559463687653E-01, -7.064885525743501E-01, -1.903349841875333E-02);
    vec3 r_mars = vec3(1.145481237413500E+00, -7.759469057667274E-01, -4.451643705572472E-02);
    vec3 r_saturn = vec3(-2.277305999381926E+00, -9.772253310113138E+00, 2.605465118509321E-01);
    vec3 r_uranus = vec3(1.846626259319022E+01, 7.554511790954641E+00, -2.111764845597773E-01);
    vec3 r_neptune = vec3(2.825889439040351E+01, -9.928255088021324E+00, -4.468016759479966E-01);
    vec3 r_pluto = vec3(9.417687691553871E+00, -3.181872837345281E+01,  6.806467814675531E-01);

    // Declare the masses
    double mSun = 1.0;
    double mEarth = 3e-6;
    double mJupiter = 1e-3;
    double mMars = 3e-7;
    double mVenus = 2.5e-6;
    double mSaturn = 3e-4;
    double mMercury = 1e-7;
    double mUranus = 4e-5;
    double mNeptune = 5e-5;
    double mPluto = 7e-9;
    double M = (mSun + mEarth + mJupiter + mMars + mVenus + mSaturn + mMercury + mUranus + mNeptune + mPluto);

    // Calculate the center of mass
    vec3 R = (r_sun*mSun + r_earth*mEarth + r_jupiter*mJupiter + r_mercury*mMercury +
               r_venus*mVenus + r_mars*mMars + r_saturn*mSaturn + r_uranus*mUranus +
               r_neptune*mNeptune + r_pluto*mNeptune)/M;


    // Declare the velocities
    vec3 v_sun = vec3(-1.978871917569178E-06, 6.843726881579374E-06, 4.032140462891743E-08)*365;
    vec3 v_earth = vec3(-6.128263831462272E-03, 1.611761267097599E-02, 1.349643765318894E-07)*365;
    vec3 v_jupiter = vec3(5.206515353907882E-04, -7.164038754622682E-03, 1.814205403145239E-05)*365;
    vec3 v_mercury = vec3(-1.589188578333726E-02, -2.505974994975800E-02, -5.904299543073971E-04)*365;
    vec3 v_venus = vec3(1.960339728192615E-02, 4.341740156278193E-03, -1.071874641156530E-03)*365;
    vec3 v_mars = vec3(8.418288645937397E-03, 1.276419831984888E-02, 6.072729084019031E-05)*365;
    vec3 v_saturn = vec3(5.126703359538530E-03, -1.283735869751270E-03, -1.816227490732958E-04)*365;
    vec3 v_uranus = vec3(-1.517937917646755E-03, 3.456908604164539E-03, 3.251073912887524E-05)*365;
    vec3 v_neptune = vec3(1.019309416815733E-03, 2.979917067133604E-03, -8.498151187073363E-05)*365;
    vec3 v_pluto = vec3(3.073735631085241E-03, 2.467755912654963E-04, -9.027657565305481E-04)*365;

    // Find the total momomentum...You can make a function of this...
    vec3 p = (v_sun*mSun + v_earth*mEarth + v_jupiter*mJupiter + v_mercury*mMercury +
               v_venus*mVenus + v_mars*mMars + v_saturn*mSaturn + v_uranus*mUranus +
               v_neptune*mNeptune + v_pluto*mNeptune);

    // Total velocity
    vec3 v_total = p/M;


    // Adding celastial bodies


    // Solar System
    // ---------------------------------------------------------------------------

    // Sun
    solarSystem.createCelestialBody( r_sun -  R, v_sun - v_total, mSun);

    // Earth
    solarSystem.createCelestialBody( r_earth, v_earth, mEarth);

    // Jupyter
    solarSystem.createCelestialBody( r_jupiter-R, v_jupiter-v_total, mJupiter);

    // Mercury
    solarSystem.createCelestialBody( r_mercury-R, v_mercury-v_total, mMercury);

    // Venus
    solarSystem.createCelestialBody( r_venus-R, v_venus-v_total, mVenus);

    // Mars
    solarSystem.createCelestialBody( r_mars-R, v_mars-v_total, mMars);

    // Saturn
    solarSystem.createCelestialBody( r_saturn-R, v_saturn-v_total, mSaturn);

    // Uranus
    solarSystem.createCelestialBody( r_uranus-R, v_uranus-v_total, mUranus);

    // Neptune
    solarSystem.createCelestialBody( r_neptune-R, v_neptune-v_total, mNeptune);

    // Pluto
    solarSystem.createCelestialBody( r_pluto-R, v_pluto-v_total, mPluto);





    double dt = 0.01;
    Solver integrator(dt);
    for(int timestep=0; timestep<numTimesteps; timestep++) {
        integrator.Verlet(solarSystem);
        solarSystem.writeToFile("../solar-system/jupiter_stab_13000_01sdf.txt",timestep);
    }


    cout << "The kinetic energy is " << solarSystem.kineticEnergy() << endl;
    cout << "The potential energy is " << solarSystem.potentialEnergy() << endl;
    cout << "The total energy is " << solarSystem.totalEnergy() << endl;
    cout << "The angular momementum is " << solarSystem.angularMomentum() << endl;



}

