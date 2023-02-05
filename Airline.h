#ifndef AIRLINE_H
#define AIRLINE_H

#include <string>
#include "defs.h"
#include "Part.h"
#include "Array.h"
#include "Aircraft.h"



class Airline{
    friend ostream& operator<<(ostream&, const Airline&);

    private:
        std::string name;
        Array<Part*> partArray;
        Array<Aircraft*> aircraftArray;

        //getter
		Aircraft* getAircraft(std::string& registration);
        Part* getPart(std::string& name);

	public:

        //constructor
        Airline(const std::string& name);
        ~Airline();


        //member functions
        void addAircraft(const std::string& type, const std::string& registration);
        void addPart(const string& part, int fh_inspect, int it_inspect);
        void takeFlight(const std::string& reg, int hours);
        void printAircraft();
        void printParts();
        void inspectionReport(const std::string& reg, Date& date);
        bool install(const std::string& registration, const std::string& name, Date& date);
};



#endif

