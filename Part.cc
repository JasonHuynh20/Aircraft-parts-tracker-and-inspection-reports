

#include <iostream>

#include "Part.h"



//----------------------------------------------------------------------PART----------------------------------------------------------------------------------
//getters
std::string Part::getName() const{
    return name;
}


//constructor/destructors-------------------------------------------
Part::Part(const std::string& name){
    this->name = name;
    this->flighthours = 0;
}

Part::~Part(){
}



//member functions-------------------------------------------------
void Part::addFlightHours(int hours){
    this->flighthours += hours;
}

void Part::install(Date& date){
    this->installationDate = date;
}


void Part::print(std::ostream& stream){
    stream << "Name: " << name  << std::endl;
    stream << "InstallationDate: " << installationDate  << std::endl;
    stream << "Flighthours: " << flighthours  << std::endl;
}


ostream& operator<<(ostream& output, Part& part){
    part.print(output);
    return output;
}


//----------------------------------------------------------------------FH_PART----------------------------------------------------------------------------------
//constructor/destructors-------------------------------------------
FH_Part::FH_Part(const std::string& name, int inspect):Part(name){
    this->fh_inspect = inspect;
}

FH_Part::~FH_Part(){
}



//virtual function
bool FH_Part::inspection(Date& date){
    // std::cout<< "FH_part" << std::endl;
    return (flighthours >= fh_inspect);

}


void FH_Part::print(std::ostream& stream){
    stream << "Name: " << name << endl;
    stream << "Flighthours: " << flighthours << endl;
    stream << "Installation date: " << installationDate;
    stream << "inspect every: " << fh_inspect << " Flight hours" << endl << endl;
}



//----------------------------------------------------------------------IT_PART----------------------------------------------------------------------------------



//constructor/destructors-------------------------------------------
IT_Part::IT_Part(const std::string& name, int inspect): Part(name){
    this->it_inspect = inspect;
}


IT_Part::~IT_Part(){
}

//member functions-----------------------------------

bool IT_Part::inspection(Date& date){
  // std::cout<< "IT_part" << std::endl;
    int days = date.toDays();
    int days2 = installationDate.toDays();
    int daysBetween = days - days2;
    return  (daysBetween >= it_inspect);
}



void IT_Part::print(std::ostream& stream){
    stream << "Name: " << name << endl;
    stream << "Flighthours: " << flighthours << endl;
    stream << "Installation date: " << installationDate;
    stream << "inspect every: " << it_inspect << " Days installed" << endl << endl;
}



//----------------------------------------------------------------------FHIT_PART----------------------------------------------------------------------------------
//constructor/destructors-------------------------------------------
FHIT_Part::FHIT_Part(const std::string& name, int fh_inspect, int it_inspect):FH_Part(name, fh_inspect), IT_Part(name, it_inspect), Part(name){
}

FHIT_Part::~FHIT_Part(){
}



//virtual function
bool FHIT_Part::inspection(Date& date){
  // std::cout<< "FHIT_part" << std::endl;
    return (FH_Part::inspection(date) || IT_Part::inspection(date));
}



void FHIT_Part::print(std::ostream& stream){
    stream << "Name: " << name << endl;
    stream << "Flighthours: " << flighthours << endl;
    stream << "Installation date: " << installationDate;
    stream << "inspect every: " << fh_inspect << " Flight hours" << endl;
    stream << "inspect every: " << it_inspect << " Days installed" << endl << endl;
}

