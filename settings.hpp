//
// Created by alex on 3/21/22.
//

#ifndef EDGAR_SETTINGS_HPP
#define EDGAR_SETTINGS_HPP

#include <boost/program_options.hpp>


class settings {
public:
  settings(int argc, char **argv);

private:
    int argc_;
    char** argv_;
    boost::program_options::option_description desc_;
    boost::program_options::options_description create_description(int argc, char** argv);
    boost::program_options::variables_map vm_;
};



#endif //EDGAR_SETTINGS_HPP
