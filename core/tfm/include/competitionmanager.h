#ifndef TANDFCOMPETITIONMANAGER_H_INCLUDED
#define TANDFCOMPETITIONMANAGER_H_INCLUDED

#include <vector>
#include <map>
#include <memory>
#include <stdexcept>

#include <stdint.h>

namespace tfm
{

class EventGroup;

class Competition
{
public:
    Competition();

    void add_age_class(const std::string & age);
    void add_eventgroup(std::shared_ptr<EventGroup> eventgroup);

    uint32_t get_number_of_age_groups() const;
    uint32_t get_number_of_eventgroups() const;

    const std::vector<std::string> & get_age_list() const;

    std::shared_ptr<EventGroup> & get_eventgroup(const std::string & name);
    std::vector<std::string> get_eventgroup_list() const;

private:
    typedef std::map<std::string, std::shared_ptr<EventGroup>> EventGroupMap;

    std::vector<std::string> age_groups;
    EventGroupMap eventgroups;

    bool age_is_already_added(const std::string & age) const;
    bool event_is_already_added(const std::string & eventname) const;

public:
    class age_already_added_exception : public std::exception
    {};

    class group_already_added_exception : public std::exception
    {};
};

}

#endif // TANDFCOMPETITIONMANAGER_H_INCLUDED
