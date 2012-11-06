#include <competitionmanager.h>
#include <event.h>

#include "testdoubles.h"

#include <string>
#include <gtest/gtest.h>

class CompetitionTests : public ::testing::Test
{
  public:
    tfm::Competition competition;
};

TEST_F(CompetitionTests, number_of_classes_starts_as_zero)
{
  EXPECT_EQ(0, competition.get_number_of_age_groups());
}

TEST_F(CompetitionTests, initialy_a_competition_have_zero_events)
{
  EXPECT_EQ(0, competition.get_number_of_events());
}

TEST_F(CompetitionTests, adding_one_age_class_makes_the_number_age_groups_one)
{
  competition.add_age_class(12);

  EXPECT_EQ(1, competition.get_number_of_age_groups());
}

TEST_F(CompetitionTests, adding_one_event_make_the_number_of_events_one)
{
  std::shared_ptr<EmptyEvent> event;
  competition.add_event(event);

  EXPECT_EQ(1, competition.get_number_of_events());
}

TEST_F(CompetitionTests, adding_the_same_age_class_twice_throws_age_already_added_exception)
{
  competition.add_age_class(12);
  EXPECT_THROW(competition.add_age_class(12), tfm::Competition::age_already_added_exception);
}

TEST_F(CompetitionTests, querying_for_ages_gives_a_list_of_ages)
{
  competition.add_age_class(12);
  competition.add_age_class(13);
  competition.add_age_class(14);

  auto agelist = competition.get_age_list();
  EXPECT_EQ(12, agelist[0]);
  EXPECT_EQ(13, agelist[1]);
  EXPECT_EQ(14, agelist[2]);
}

TEST_F(CompetitionTests, querying_for_events_gives_a_list_of_the_added_events)
{
  std::shared_ptr<NamedEvent> run_event(new NamedEvent("run"));
  std::shared_ptr<NamedEvent> jump_event(new NamedEvent("jump"));
  std::shared_ptr<NamedEvent> throw_event(new NamedEvent("throw"));

  competition.add_event(run_event);
  competition.add_event(jump_event);
  competition.add_event(throw_event);

  auto eventlist = competition.get_event_list();
  EXPECT_EQ("run", std::dynamic_pointer_cast<NamedEvent>(eventlist[0])->get_name());
  EXPECT_EQ("jump", std::dynamic_pointer_cast<NamedEvent>(eventlist[1])->get_name());
  EXPECT_EQ("throw", std::dynamic_pointer_cast<NamedEvent>(eventlist[2])->get_name());
}
