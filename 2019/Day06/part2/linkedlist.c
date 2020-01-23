#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "readfile.h"
#include "linkedlist.h"
#include "hash.h"

struct planet *makePlanetList(s_planets *hashOfPlanets,char * startPlanet) {
        //get hash of start direct
        //go to start direct
        //add as planet
        //get planet - add as next
        //get hash of planet
        //go to next direct based on planet hash
        //stop at COM

        planet *tmpPlanet = malloc(sizeof(planet));
        planet *current = tmpPlanet;

        current->planet = startPlanet;
        current->next = NULL;

        while (strcmp(current->planet,"COM") != 0 )
        {
                int arrayLoc = hash(current->planet);
                while (strcmp(hashOfPlanets[arrayLoc].direct,current->planet) != 0) {
                        arrayLoc += 1;
                }
                current->next = malloc(sizeof(planet));
                current->next->planet = hashOfPlanets[arrayLoc].planet;
                current->next->next = NULL;
                current = current->next;
        }

        return tmpPlanet;
}