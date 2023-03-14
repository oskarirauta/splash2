#include <iostream>
#include <vector>
#include <string>
#include <libgen.h>

#include "app.hpp"
#include "common.hpp"
#include "cmdline.hpp"

cmdline::State cmdline::parse(int argc, char **argv) {

	std::vector<std::string> args;

	for ( size_t i = 1; i < (size_t)argc; i++ )
		args.push_back(std::string(argv[i]));

	std::cout << "exe: " << common::selfexe() << std::endl;

	for ( size_t i = 0; i < args.size(); i++ )
		std::cout << "#" << i << ": \"" << args[i] << "\"" << std::endl;

	return cmdline::State::OK;
}
