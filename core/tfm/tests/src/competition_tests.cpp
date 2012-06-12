#include <competitionmanager.h>
#include <gtest/gtest.h>

TEST (CompetitionTests, number_of_classes_starts_as_zero)
{
    tfm::Competition competition;
    EXPECT_EQ (0, competition.number_of_classes ());
}

TEST (CompetitionTests, adding_one_age_class_makes_the_number_of_classes_two)
{
    tfm::Competition competition;
    competition.add_age_class (12);

    EXPECT_EQ (2, competition.number_of_classes ());
}

TEST (CompetitionTests, adding_two_age_classes_makes_number_of_classes_four)
{
    tfm::Competition competition;
    competition.add_age_class (12);
    competition.add_age_class (13);

    EXPECT_EQ (4, competition.number_of_classes ());
}

TEST (CompetitionTests, adding_the_same_age_twice_throws_age_already_added_exception)
{
    tfm::Competition competition;
    competition.add_age_class (12);

    EXPECT_THROW (competition.add_age_class (12), tfm::Competition::age_already_added_exception);
}
