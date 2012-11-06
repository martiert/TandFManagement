#ifndef TESTDOUBLES_H_INCLUDED
#define TESTDOUBLES_H_INCLUDED

class EmptyEvent : public tfm::Event
{
};

class NamedEvent : public tfm::Event
{
  public:
    NamedEvent(std::string name)
      : name(name)
    {}

    std::string get_name()
    {
      return name;
    }
  private:
    std::string name;
};

#endif // TESTDOUBLES_H_INCLUDED
