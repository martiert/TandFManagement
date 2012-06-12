#include "competitionmanager.h"

#include <algorithm>
#include <iostream>

tfm::Competition::Competition ()
{ }

void tfm::Competition::add_age_class (const uint ageclass)
{
    if (std::find (classes.begin (), classes.end (), ageclass) != classes.end ())
        throw age_already_added_exception ();

    classes.push_back (ageclass);
}

uint tfm::Competition::number_of_classes () const
{
    return classes.size () * 2;
}
