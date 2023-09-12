#include "Cursist.h"

size_t Cursist::ghostParticipants()
{
    size_t totalPeopleonGroups = 0;

    for (auto &group : d_groups)
        totalPeopleonGroups += group.students.size();

    return d_numberOfParticipants - totalPeopleonGroups;
}