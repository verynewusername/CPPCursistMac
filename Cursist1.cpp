#include "Cursist.h"

Cursist::Cursist()
:
    d_inStudents("admin/students"),
    d_inResults("admin/results"),
    d_outStudents("admin/students.out"),
    d_outResults("admin/results.out"),
    d_groups(),
    d_initialSkip(false),
    d_idBoxCounter(0),
    d_groupFlag(false),
    d_extranotesFlag(false),
    d_numberOfParticipants(0)
{

}
