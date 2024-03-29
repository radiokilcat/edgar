#include <iostream>
#include "settings.hpp"

settings::settings(int argc, char** argv)
: argc_(argc)
, argv_(argv)
{
    using namespace boost::program_options;
    auto desc = create_description(argc_, argv_);
    store(parse_command_line(argc_, argv_, desc), vm_);
    notify(vm_);
    if (vm_.count("help"))
    {
        std::cout << desc << std::endl;
        throw std::logic_error("help is printed.");
    }
    if (!vm_.count("file"))
    {
        throw std::logic_error("Specify settings file");
    }
}

boost::program_options::options_description settings::create_description(int argc, char **argv) {
    using namespace boost::program_options;

    options_description desc;

    desc.add_options()
            ("help,h", "print usage message")
            ("file,f", value<std::string>(), "settings file")
            ;
    return desc;
}
void settings::read_file_settings()
{

}
