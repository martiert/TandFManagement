#ifndef TANDFCOMPETITIONMANAGER_H_INCLUDED
#define TANDFCOMPETITIONMANAGER_H_INCLUDED

#include <vector>
#include <map>
#include <memory>
#include <stdexcept>

#include <stdint.h>

namespace tfm
{

class Event;

class Competition
{
public:
    Competition();

    void add_age_class(const uint32_t & age);
    void add_event(std::shared_ptr<Event> event);

    uint32_t get_number_of_age_groups() const;
    uint32_t get_number_of_events() const;

    const std::vector<uint32_t> & get_age_list() const;

    std::shared_ptr<Event> & get_event(const std::string & name);
    std::vector<std::string> get_event_list() const;

private:
    std::vector<uint32_t> age_groups;
    std::map<std::string, std::shared_ptr<Event>> events;

    bool is_already_added(const uint32_t & age) const;

public:
    class age_already_added_exception : public std::exception
    {};
};

}

#endif // TANDFCOMPETITIONMANAGER_H_INCLUDED
