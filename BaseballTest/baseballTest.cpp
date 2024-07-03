#include <stdexcept>
#include <string>


using namespace std;

class Baseball {
public:
	void guess(const string& str) {
		throw length_error("Must be three letters.");
	}
};