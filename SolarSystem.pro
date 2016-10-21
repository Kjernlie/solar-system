TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
#DEFINES += CATCH_CONFIG_MAIN

SOURCES += main.cpp \
    celestialbody.cpp \
    solarsystem.cpp \
    vec3.cpp \
    solver.cpp \
    test.cpp \
    perihelion.cpp \
    twobody.cpp \
    threebody.cpp \
    milkyway.cpp

HEADERS += \
    celestialbody.h \
    solarsystem.h \
    vec3.h \
    catch.hpp \
    solver.h \
    perihelion.h \
    twobody.h \
    threebody.h \
    milkyway.h

