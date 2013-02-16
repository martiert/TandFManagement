#ifndef TANDFEVENTGROUP_H_INCLUDED
#define TANDFEVENTGROUP_H_INCLUDED

#include <memory>
#include <string>
#include <vector>

namespace tfm
{

class EventGroup
{
public:
    virtual ~EventGroup() {}
    virtual const std::string & get_name() const = 0;

    int get_number_of_age_classes() const;

    void add_age_class(const std::string & age);
    void add_age_classes(const std::vector<std::string> & age_classes);

protected:
    std::vector<std::string> age_classes;
};

typedef std::shared_ptr<EventGroup> EventGroupPtr;

}

#endif
