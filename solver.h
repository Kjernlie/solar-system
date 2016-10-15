//#ifndef EULER_H
//#define EULER_H


//class Euler
//{
//public:
//    double m_dt;
//    Euler(double dt);
//    void integrateOneStep(class SolarSystem &system);
//};

//#endif // EULER_H

#pragma once

class Solver
{
public:
    double m_dt;
    Solver(double dt);
    void Euler(class SolarSystem &system);
    void Verlet(class SolarSystem &system);
};
