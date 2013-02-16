#ifndef TESTDOUBLES_H_INCLUDED
#define TESTDOUBLES_H_INCLUDED

class EmptyEvent : public tfm::Event
{
public:
    EmptyEvent()
        : name("Empty")
    {}

    const std::string & get_name() const
    {
        return name;
    }
private:
    std::string name;
};

class NamedEvent : public tfm::Event
{
public:
    NamedEvent(std::string name)
        : name(name)
    {}

    const std::string & get_name() const
    {
        return name;
    }
private:
    std::string name;
};

#endif // TESTDOUBLES_H_INCLUDED
