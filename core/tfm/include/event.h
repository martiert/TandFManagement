#ifndef TANDFEVENT_H_INCLUDED
#define TANDFEVENT_H_INCLUDED

#include <memory>
#include <string>

namespace tfm
{

class Event
{
public:
    virtual ~Event() {}
    virtual const std::string & get_name() const = 0;
};

typedef std::shared_ptr<Event> EventPtr;

}

#endif // TANDFEVENT_H_INCLUDED
