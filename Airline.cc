#include <iostream>
#include "Airline.h"



//constructor/destructors------------------------------------------------------
Airline::Airline(const std::string& name){
    this->name = name;
}



Airline::~Airline(){
    for(int i = 0; i < aircraftArray.getSize(); i++){
        delete aircraftArray[i];
    }
    for(int i = 0; i < partArray.getSize(); i++){
        delete partArray[i];
    }
}



//getters----------------------------------------------------------------------
Aircraft* Airline::getAircraft(std::string& registration){
    for(int i = 0; i < aircraftArray.getSize(); i++){
        if(aircraftArray[i]->getRegistration() == registration){
            return aircraftArray[i];
        }
    }
    return NULL;
}


Part* Airline::getPart(std::string& name){
    for(int i = 0; i < partArray.getSize(); i++){
        if(partArray[i]->getName() == name){
            return partArray[i];
        }
    }
    return NULL;
}



//member functions----------------------------------------------------------------
void Airline::addAircraft(const std::string& type, const std::string& registration){
    Aircraft* newAircraft = new Aircraft(type, registration);
    aircraftArray.add(newAircraft);
}



void Airline::addPart(const string& part, int fh_inspect, int it_inspect){
    if(fh_inspect != 0 && it_inspect != 0){
      FHIT_Part* newPart = new FHIT_Part(part, fh_inspect, it_inspect);
      partArray.add(newPart);

    }else if(fh_inspect == 0){
        IT_Part* newPart = new IT_Part(part, it_inspect);
        partArray.add(newPart);

    }else if(it_inspect == 0){
        FH_Part* newPart = new FH_Part(part, fh_inspect);
        partArray.add(newPart);
    }
}



void Airline::takeFlight(const std::string& reg, int hours){
    for(int i = 0; i < aircraftArray.getSize(); i++){
        if(aircraftArray[i]->getRegistration() == reg){
            aircraftArray[i]->takeFlight(hours);
            return;
        }
    }
    std::cout<< "Error with taking flight" << endl;
}



void Airline::printAircraft(){
    for(int i = 0; i < aircraftArray.getSize(); i++){
        aircraftArray[i]->print(cout);
    }
}



void Airline::printParts(){
    for(int i = 0; i < partArray.getSize(); i++){
        partArray[i]->print(cout);
    }
}



void Airline::inspectionReport(const std::string& reg, Date& date){
    Array<Part*> partArrayInspect;
    bool notFound = true;

    //find aircraft
    for(int i = 0; i < aircraftArray.getSize(); i++){
        if(aircraftArray[i]->getRegistration() == reg){
            notFound = false;
            aircraftArray[i]->inspectionReport(date, partArrayInspect);
            std::cout<< "The following parts from "<< aircraftArray[i]->getRegistration() << " require inspection: " << std::endl;
        }
    }

    if(notFound){
        std::cout << "aircraft not found" << endl;
        return;
    }

    //print out list of parts need inspection
    for(int i = 0; i < partArrayInspect.getSize(); i++){
        std::cout << "Part: " << endl;
        partArrayInspect[i]->print(cout);
    }
}



bool Airline::install(const std::string& registration, const std::string& name, Date& date){

  //find aircraft, then find part
    for(int i = 0; i < aircraftArray.getSize(); i++){
        if(aircraftArray[i]->getRegistration() == registration){
            for(int j = 0; j < partArray.getSize(); j++){
                if(partArray[j]->getName() == name){

                  //if both found install it
                    aircraftArray[i]->install(partArray[j], date);
                    return true;
                }
            }
            std::cout << "Error no part" << std::endl;
            return false;
        }
    }
    std::cout << "Error no aircraft" << std::endl;
    return false;
}

