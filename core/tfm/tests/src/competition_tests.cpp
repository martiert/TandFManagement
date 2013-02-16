#include <competitionmanager.h>
#include <event.h>

#include "testdoubles.h"

#include <string>
#include <algorithm>
#include <gtest/gtest.h>

class CompetitionTests : public ::testing::Test
{
public:
    CompetitionTests()
        : run_event(std::make_shared<NamedEvent>("run")),
          jump_event(std::make_shared<NamedEvent>("jump")),
          throw_event(std::make_shared<NamedEvent>("throw"))
    {}

protected:
    tfm::Competition competition;
    std::shared_ptr<NamedEvent> run_event;
    std::shared_ptr<NamedEvent> jump_event;
    std::shared_ptr<NamedEvent> throw_event;
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
    competition.add_age_class("12");

    EXPECT_EQ(1, competition.get_number_of_age_groups());
}

TEST_F(CompetitionTests, adding_one_event_make_the_number_of_events_one)
{
    std::shared_ptr<EmptyEvent> event(std::make_shared<EmptyEvent>());
    competition.add_event(event);

    EXPECT_EQ(1, competition.get_number_of_events());
}

TEST_F(CompetitionTests, querying_for_ages_gives_a_list_of_ages)
{
    competition.add_age_class("12");
    competition.add_age_class("13");
    competition.add_age_class("14");

    auto agelist = competition.get_age_list();
    EXPECT_EQ("12", agelist[0]);
    EXPECT_EQ("13", agelist[1]);
    EXPECT_EQ("14", agelist[2]);
}

TEST_F(CompetitionTests, querying_for_an_event_gives_a_shared_pointer_to_that_event)
{
    competition.add_event(run_event);
    competition.add_event(jump_event);
    competition.add_event(throw_event);

    EXPECT_EQ(3, competition.get_number_of_events());
    EXPECT_EQ(run_event, competition.get_event("run"));
    EXPECT_EQ(jump_event, competition.get_event("jump"));
    EXPECT_EQ(throw_event, competition.get_event("throw"));
}

TEST_F(CompetitionTests, querying_for_a_list_of_events_returns_a_list_of_the_added_events)
{
    competition.add_event(run_event);
    competition.add_event(jump_event);
    competition.add_event(throw_event);

    auto events = competition.get_event_list();
    EXPECT_EQ(3, events.size());
    EXPECT_NE(events.end(), std::find(events.begin(), events.end(), "run"));
    EXPECT_NE(events.end(), std::find(events.begin(), events.end(), "jump"));
    EXPECT_NE(events.end(), std::find(events.begin(), events.end(), "throw"));
}

TEST_F(CompetitionTests, adding_the_same_age_class_twice_throws_age_already_added_exception)
{
    competition.add_age_class("12");
    EXPECT_THROW(competition.add_age_class("12"), tfm::Competition::age_already_added_exception);
}
