#ifndef SHAKESPEARE_H
#define	SHAKESPEARE_H

#include <string>
using namespace std;
namespace Shakespeare
{
    enum Priority {
        NOTICE,
        WARNING,
        DEBUG,
        ERROR,
        URGENT,
        CRITICAL
    };

    char *get_custom_time(string format);

    void log(FILE* lf, Priority ePriority, string process, string msg);

    int file_size_limit_reached(char *filepath, size_t write_size);

    bool directory_exists(const char* directory);
    string ensure_filepath(string folder);

    string get_filename(string folder, string prefix, string suffix);

    FILE * open_log(string folder,string process);
}
#endif	/* SHAKESPEARE_H */
