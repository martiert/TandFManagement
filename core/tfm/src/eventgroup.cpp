#include "eventgroup.h"

namespace tfm
{

void EventGroup::add_age_class(const std::string & age)
{
    age_classes.push_back(age);
}

void EventGroup::add_age_classes(const std::vector<std::string> & ages)
{
    age_classes = ages;
}

int EventGroup::get_number_of_age_classes() const
{
    return age_classes.size();
}

}
