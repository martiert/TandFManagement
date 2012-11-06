#include "competitionmanager.h"

#include <algorithm>
#include <iostream>

namespace tfm
{

Competition::Competition()
  : events(0)
{ }

void Competition::add_age_class(const uint32_t& age)
{
  if (is_already_added(age))
    throw age_already_added_exception();

  age_groups.push_back(age);
}

void Competition::add_event(std::shared_ptr<Event> event)
{
  events.push_back(event);
}

uint32_t Competition::get_number_of_age_groups() const
{
  return age_groups.size();
}

uint32_t Competition::get_number_of_events() const
{
  return events.size();
}

const std::vector<uint32_t>& Competition::get_age_list() const
{
  return age_groups;
}

const std::vector<std::shared_ptr<Event>>& Competition::get_event_list() const
{
  return events;
}

bool Competition::is_already_added(const uint32_t& age) const
{
  return (std::find(age_groups.begin(), age_groups.end(), age) != age_groups.end());
}

}
