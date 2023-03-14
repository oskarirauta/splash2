#pragma once

namespace cmdline {

	enum State {
		OK = 0,
		ERROR_UNKNOOWN
	};

	State parse(int argc, char **argv);

}
