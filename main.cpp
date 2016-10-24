#ifndef CATCH_CONFIG_MAIN
#include <iostream>
#include <cmath>
#include <stdlib.h>
#include "solarsystem.h"
#include "solver.h"
#include "perihelion.h"
#include "twobody.h"
#include "threebody.h"
#include "milkyway.h"
#include "armadillo"
#include "milkyway.h"
using namespace std;

int main(int numArguments, char **arguments)
{
    perihelion();
    //milkyway();
    //threebody();
    //twobody();

    return 0;

}


#endif

