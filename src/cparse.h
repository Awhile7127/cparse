#include <iostream>
#include <string>
#include <vector>
#include <map>


using namespace std;


// DECLARE PUBLIC CLASS FOR PARSING ARGUMENTS
class Argument {
    public:
        string arg_long;
        char arg_short;

        int init(string long_arg, char short_arg) {
            arg_long = long_arg;
            arg_short = short_arg;
            return 0;
        }
};


// PARSE COMMAND LINE ARGUMENTS BY COMPARING THEM TO EXPECTED, BUILT ARGUMENTS
map<string, string> parse_arguments(vector<Argument> blt, int argc, char **argv) {

    // DECLARE TABLE CONTAINING FOUND ARGUMENTS
    map<string, string> arguments;

    // ITERATE THROUGH PASSED ARGUMENTS
    for (int i = 0; i < argc; i++) {

        // ITERATE THROUGH BUILT ARGUMENTS
        for (int j = 0; j < blt.size(); j++) {

            // CHECK FOR:
            // LONG ARGUMENT FORM (--arg)
            // SHORT ARGUMENT FORM (-a)
            // i IN RANGE OF argv
            if (((argv[i] == string("--") + blt[j].arg_long) ||
               (argv[i] == string("-") + blt[j].arg_short)) &&
               (i + 1 < argc)) {

                // DECLARE HUMAN READABLE VARIABLES
                string key = blt[j].arg_long;

                // CHECK THAT THE EXPECTED ARGUMENT HASN'T ALREADY BEEN
                // SATISFIED
                if (arguments[key] != "") {
                    cout << "Argument " << argv[i] << " already satisfied\n";
                    continue;
                }

                // APPEND TO TABLE
                string value = argv[i + 1];
                arguments[key] = value;
            }
        }
    }
    return arguments;
}
