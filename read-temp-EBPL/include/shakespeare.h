#ifndef SHAKESPEARE_H
#define	SHAKESPEARE_H

#include <string>
using namespace std;

enum Priority {
    NOTICE,
    WARNING,
    DEBUG,
    ERROR,
    URGENT,
    CRITICAL
};

void Log(FILE* lf, Priority ePriority, string process, string msg);
string get_filename(string folder, string prefix, string suffix);


#endif	/* SHAKESPEARE_H */
