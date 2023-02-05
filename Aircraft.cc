#include <iostream>
#include "Aircraft.h"



//constructor/destructors
Aircraft::Aircraft(const std::string& type, const std::string& registration){
    this->type = type;
    this->registration = registration;
    this->flighthours = 0;
}


Aircraft::~Aircraft(){
}


//getters------------------------------------------------------------------------------
std::string Aircraft::getRegistration() const{
    return registration;
}


//member functions-----------------------------------------------------------------------------------------
void Aircraft::install(Part* part, Date& date){
    part->install(date);
    pointerArray.add(part);
}



void Aircraft::takeFlight(int hours){
    flighthours += hours;
    for(int i = 0; i < pointerArray.getSize(); i++){
        pointerArray[i]->addFlightHours(hours);
    }
}



void Aircraft::inspectionReport(Date& date, Array<Part*>& partArray){
    for(int i = 0; i < pointerArray.getSize(); i++){
        if(pointerArray[i]->inspection(date)){
            partArray.add(pointerArray[i]);
        }
    }
}


void Aircraft::print(std::ostream& stream){
  stream << "Type: " << type  << std::endl;
  stream << "Registration: " << registration  << std::endl;
  stream << "Flighthours: " << flighthours  << std::endl << std::endl;
}


ostream& operator<<(ostream& output, Aircraft& a){
    a.print(output);
    return output;

}

