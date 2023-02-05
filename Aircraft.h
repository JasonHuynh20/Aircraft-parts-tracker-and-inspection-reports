#ifndef AIRCRAFT_H

#define AIRCRAFT_H





#include <string>

#include "defs.h"

#include "Part.h"

#include "Array.h"





class Aircraft{

    friend ostream& operator<<(ostream&, const Aircraft&);



    private:

        std::string type;

        std::string registration;

        Array<Part*> pointerArray;

        int flighthours;



	public:

        //getter

		std::string getRegistration() const;



        //constructor

        Aircraft(const std::string& type, const std::string& registration);

        ~Aircraft();



        //member functions

        void install(Part*, Date&);

        void takeFlight(int hours);



        void inspectionReport(Date& date, Array<Part*>&);



        void print(std:: ostream& stream);





};











#endif

