#include <competitionmanager.h>
#include <eventgroup.h>

#include "testdoubles.h"

#include <string>
#include <algorithm>

#include <CppUTest/TestHarness.h>

#define CHECK_THROW(expr, result) \
    try { \
        (expr); \
        CHECK(false && "Expected expresssion to throw, but it did not"); \
    } catch (result) { \
        CHECK(true); \
    } catch (std::exception) { \
        CHECK(false && "Expected expresssion to throw something, but it threw something else"); \
    } \


TEST_GROUP(CompetitionTests)
{
public:
    void setup()
    {
        run_event = std::make_shared<NamedEvent>("run");
        jump_event = std::make_shared<NamedEvent>("jump");
        throw_event = std::make_shared<NamedEvent>("throw");
    }

    void teardown()
    {
    }

protected:
    tfm::Competition competition;
    std::shared_ptr<NamedEvent> run_event;
    std::shared_ptr<NamedEvent> jump_event;
    std::shared_ptr<NamedEvent> throw_event;
};

TEST(CompetitionTests, number_of_classes_starts_as_zero)
{
    LONGS_EQUAL(0, competition.get_number_of_age_groups());
}

TEST(CompetitionTests, initialy_a_competition_have_zero_eventgroups)
{
    LONGS_EQUAL(0, competition.get_number_of_eventgroups());
}

TEST(CompetitionTests, adding_one_age_class_makes_the_number_age_groups_one)
{
    competition.add_age_class("12");

    LONGS_EQUAL(1, competition.get_number_of_age_groups());
}

TEST(CompetitionTests, adding_one_eventgroup_makes_the_number_of_eventgroups_one)
{
    std::shared_ptr<EmptyEvent> group(std::make_shared<EmptyEvent>());
    competition.add_eventgroup(group);

    LONGS_EQUAL(1, competition.get_number_of_eventgroups());
}

TEST(CompetitionTests, querying_for_ages_gives_a_list_of_ages)
{
    competition.add_age_class("12");
    competition.add_age_class("13");
    competition.add_age_class("14");

    auto agelist = competition.get_age_list();
    CHECK_EQUAL("12", agelist[0]);
    CHECK_EQUAL("13", agelist[1]);
    CHECK_EQUAL("14", agelist[2]);
}

TEST(CompetitionTests, querying_for_an_event_gives_a_shared_pointer_to_that_event)
{
    competition.add_eventgroup(run_event);
    competition.add_eventgroup(jump_event);
    competition.add_eventgroup(throw_event);

    LONGS_EQUAL(3, competition.get_number_of_eventgroups());
    CHECK_EQUAL(competition.get_eventgroup("run").get(), run_event.get());
    CHECK_EQUAL(competition.get_eventgroup("jump").get(), jump_event.get());
    CHECK_EQUAL(competition.get_eventgroup("throw").get(), throw_event.get());
}

TEST(CompetitionTests, adding_two_age_classes_and_a_event_gives_the_event_two_age_groups)
{
    competition.add_eventgroup(run_event);
    competition.add_age_class("12");
    competition.add_age_class("13");

    LONGS_EQUAL(2, competition.get_eventgroup("run")->get_number_of_age_classes());
}

TEST(CompetitionTests, querying_for_a_list_of_events_returns_a_list_of_the_added_events)
{
    competition.add_eventgroup(run_event);
    competition.add_eventgroup(jump_event);
    competition.add_eventgroup(throw_event);

    auto events = competition.get_eventgroup_list();
    LONGS_EQUAL(3, events.size());
    CHECK(std::find(events.begin(), events.end(), "run") != events.end());
    CHECK(std::find(events.begin(), events.end(), "jump") != events.end());
    CHECK(std::find(events.begin(), events.end(), "throw") != events.end());
}

TEST(CompetitionTests, adding_the_same_age_class_twice_throws_age_already_added_exception)
{
    competition.add_age_class("12");
    CHECK_THROW(competition.add_age_class("12"), tfm::Competition::age_already_added_exception);
}

TEST(CompetitionTests, adding_group_with_same_name_twice_throws_group_already_added_exception)
{
    std::shared_ptr<NamedEvent> run_event2(std::make_shared<NamedEvent>("run"));
    competition.add_eventgroup(run_event);
    CHECK_THROW(competition.add_eventgroup(run_event2), tfm::Competition::group_already_added_exception);
}

TEST(CompetitionTests, adding_three_age_classes_and_a_event_gives_the_event_two_age_groups)
{
    competition.add_eventgroup(run_event);
    competition.add_age_class("12");
    competition.add_age_class("13");
    competition.add_age_class("14");

    LONGS_EQUAL(3, competition.get_eventgroup("run")->get_number_of_age_classes());
}

TEST(CompetitionTests, adding_an_eventgroup_after_the_adding_three_age_classes_gives_three_age_classes)
{
    competition.add_age_class("12");
    competition.add_age_class("13");
    competition.add_age_class("14");
    competition.add_eventgroup(run_event);

    LONGS_EQUAL(3, competition.get_eventgroup("run")->get_number_of_age_classes());
}
