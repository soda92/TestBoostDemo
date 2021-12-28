
#include <boost/process.hpp>
#include <boost/process/start_dir.hpp>

int main() {
	namespace bp = boost::process;

	int result = bp::system("D:/src/TaiYuan/py/core/python.exe", "copy_file.py", bp::start_dir("D:/src/TaiYuan/py/"));

}
