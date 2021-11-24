#include "Unicode.h"

#include <iostream>

namespace dgt {
	void UnicodePrintTest() {
#ifdef _WIN32
		fflush(stdout);
		_setmode(_fileno(stdout), _O_U16TEXT);
		std::wcout << L'\x2502' << "\n";
		fflush(stdout);
		_setmode(_fileno(stdout), _O_TEXT);
#endif

#ifdef __linux__
		std::cout << "│\n";
		std::cout << "\u2502" << "\n";
#endif
	}
}

int main() {
	dgt::UnicodePrintTest();
	std::cout << "Test everything keeps working\n";
	return 0;
}
