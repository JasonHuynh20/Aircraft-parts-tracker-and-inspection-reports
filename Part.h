#ifndef PART_H
#define PART_H

#include <string>
#include "defs.h"
#include "Date.h"
// using namespace std;

class Part{
    friend ostream& operator<<(ostream&, const Part&);

    protected:
        std::string name;
        Date installationDate;
        int flighthours;

        public:
        //getter-------------------------------
	std::string getName() const;


        //constructor--------------------------
        Part(const std::string& name);
        virtual ~Part();


        //member functions--------------------
        void addFlightHours(int);
        void install(Date&);

        //virtual function-------------------
        virtual bool inspection(Date&) = 0;
        virtual void print(std:: ostream& stream);
};


class FH_Part: virtual public Part{

    protected:
        int fh_inspect;

	public:

        //constructor-------------------------------------------
        FH_Part(const std::string& name, int inspect);

        virtual ~FH_Part();

        //virtual function---------------------------------------
        bool inspection(Date&);
        void print(std::ostream& stream);

};


class IT_Part: virtual public Part{

    protected:
        int it_inspect;

	public:

        //constructor---------------------------------------
        IT_Part(const std::string& name, int inspect);

        virtual ~IT_Part();

        //virtual function----------------------------------
        bool inspection(Date&);
        void print(std::ostream& stream);
};



class FHIT_Part: public FH_Part, IT_Part{

	public:

        //constructor-----------------------------------------
        FHIT_Part(const std::string& name, int fh_inspect, int it_inspect);

        virtual ~FHIT_Part();

        //virtual function-------------------------------------------
        bool inspection(Date&);
        void print(std::ostream& stream);
};


#endif

