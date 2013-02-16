#include <competitionmanager.h>
#include <eventgroup.h>

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

TEST_F(CompetitionTests, initialy_a_competition_have_zero_eventgroups)
{
    EXPECT_EQ(0, competition.get_number_of_eventgroups());
}

TEST_F(CompetitionTests, adding_one_age_class_makes_the_number_age_groups_one)
{
    competition.add_age_class("12");

    EXPECT_EQ(1, competition.get_number_of_age_groups());
}

TEST_F(CompetitionTests, adding_one_eventgroup_makes_the_number_of_eventgroups_one)
{
    std::shared_ptr<EmptyEvent> group(std::make_shared<EmptyEvent>());
    competition.add_eventgroup(group);

    EXPECT_EQ(1, competition.get_number_of_eventgroups());
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
    competition.add_eventgroup(run_event);
    competition.add_eventgroup(jump_event);
    competition.add_eventgroup(throw_event);

    EXPECT_EQ(3, competition.get_number_of_eventgroups());
    EXPECT_EQ(run_event, competition.get_eventgroup("run"));
    EXPECT_EQ(jump_event, competition.get_eventgroup("jump"));
    EXPECT_EQ(throw_event, competition.get_eventgroup("throw"));
}

TEST_F(CompetitionTests, adding_two_age_classes_and_a_event_gives_the_event_two_age_groups)
{
    competition.add_eventgroup(run_event);
    competition.add_age_class("12");
    competition.add_age_class("13");

    EXPECT_EQ(2, competition.get_eventgroup("run")->get_number_of_age_classes());
}

TEST_F(CompetitionTests, querying_for_a_list_of_events_returns_a_list_of_the_added_events)
{
    competition.add_eventgroup(run_event);
    competition.add_eventgroup(jump_event);
    competition.add_eventgroup(throw_event);

    auto events = competition.get_eventgroup_list();
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

TEST_F(CompetitionTests, adding_group_with_same_name_twice_throws_group_already_added_exception)
{
    std::shared_ptr<NamedEvent> run_event2(std::make_shared<NamedEvent>("run"));
    competition.add_eventgroup(run_event);
    EXPECT_THROW(competition.add_eventgroup(run_event2), tfm::Competition::group_already_added_exception);
}

TEST_F(CompetitionTests, adding_three_age_classes_and_a_event_gives_the_event_two_age_groups)
{
    competition.add_eventgroup(run_event);
    competition.add_age_class("12");
    competition.add_age_class("13");
    competition.add_age_class("14");

    EXPECT_EQ(3, competition.get_eventgroup("run")->get_number_of_age_classes());
}

TEST_F(CompetitionTests, adding_an_eventgroup_after_the_adding_three_age_classes_gives_three_age_classes)
{
    competition.add_age_class("12");
    competition.add_age_class("13");
    competition.add_age_class("14");
    competition.add_eventgroup(run_event);

    EXPECT_EQ(3, competition.get_eventgroup("run")->get_number_of_age_classes());
}
