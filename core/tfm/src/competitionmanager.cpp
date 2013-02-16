#include "competitionmanager.h"
#include "eventgroup.h"

#include <algorithm>
#include <iostream>

namespace tfm
{

Competition::Competition()
{ }

void Competition::add_age_class(const std::string & age)
{
    if (age_is_already_added(age)) {
        throw age_already_added_exception();
    }

    age_groups.push_back(age);
    for (auto & eventgrouppairs : eventgroups) {
        eventgrouppairs.second->add_age_class(age);
    }
}

void Competition::add_eventgroup(EventGroupPtr eventgroup)
{
    if (event_is_already_added(eventgroup->get_name())) {
        throw group_already_added_exception();
    }

    eventgroup->add_age_classes(age_groups);
    std::pair<std::string, EventGroupPtr> grouppair(eventgroup->get_name(), eventgroup);
    eventgroups.insert(grouppair);
}

uint32_t Competition::get_number_of_age_groups() const
{
    return age_groups.size();
}

uint32_t Competition::get_number_of_eventgroups() const
{
    return eventgroups.size();
}

const std::vector<std::string> & Competition::get_age_list() const
{
    return age_groups;
}

EventGroupPtr & Competition::get_eventgroup(const std::string & name)
{
    return eventgroups[name];
}

std::vector<std::string> Competition::get_eventgroup_list() const
{
    std::vector<std::string> event_names;
    for (auto eventpair : eventgroups) {
        event_names.push_back(eventpair.first);
    }
    return event_names;
}

bool Competition::age_is_already_added(const std::string & age) const
{
    return (std::find(age_groups.begin(), age_groups.end(), age) != age_groups.end());
}

bool Competition::event_is_already_added(const std::string & eventname) const
{
    for (auto eventpair : eventgroups) {
        if (eventpair.first == eventname) {
            return true;
        }
    }
    return false;
}

}
