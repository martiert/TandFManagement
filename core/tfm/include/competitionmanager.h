#ifndef TANDFCOMPETITIONMANAGER_H_INCLUDED
#define TANDFCOMPETITIONMANAGER_H_INCLUDED

#include <stdexcept>
#include <vector>

typedef unsigned int uint;

namespace tfm
{
    class Competition
    {
public:
        Competition ();

        void add_age_class (const uint ageclass);

        uint number_of_classes () const;

private:
        std::vector<uint> classes;

public:
        class age_already_added_exception : public std::exception
        {};
    };
}

#endif // TANDFCOMPETITIONMANAGER_H_INCLUDED
