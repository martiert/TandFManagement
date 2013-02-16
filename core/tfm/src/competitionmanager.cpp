#include "competitionmanager.h"
#include "event.h"

#include <algorithm>
#include <iostream>

namespace tfm
{

Competition::Competition()
{ }

void Competition::add_age_class(const std::string & age)
{
    if (is_already_added(age))
        throw age_already_added_exception();

    age_groups.push_back(age);
}

void Competition::add_event(EventPtr event)
{
    std::pair<std::string, EventPtr> eventpair(event->get_name(), event);
    events.insert(eventpair);
}

uint32_t Competition::get_number_of_age_groups() const
{
    return age_groups.size();
}

uint32_t Competition::get_number_of_events() const
{
    return events.size();
}

const std::vector<std::string> & Competition::get_age_list() const
{
    return age_groups;
}

EventPtr & Competition::get_event(const std::string & name)
{
    return events[name];
}

std::vector<std::string> Competition::get_event_list() const
{
    std::vector<std::string> event_names;
    for (auto eventpair : events) {
        event_names.push_back(eventpair.first);
    }
    return event_names;
}

bool Competition::is_already_added(const std::string & age) const
{
    return (std::find(age_groups.begin(), age_groups.end(), age) != age_groups.end());
}

}
