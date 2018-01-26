#include <boost/log/trivial.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/console.hpp>
// add CFLAG -DBOOST_LOG_DYN_LINK
void set_log_level(const std::string& level)
{
    //default log level
    boost::log::core::get()->set_filter(boost::log::trivial::severity >= boost::log::trivial::info);
    boost::log::core::get()->set_filter(boost::log::trivial::severity >= boost::log::trivial::info);
  if(level == "fatal"){
    boost::log::core::get()->set_filter(boost::log::trivial::severity >= boost::log::trivial::fatal);
  }else if(level == "error"){
    boost::log::core::get()->set_filter(boost::log::trivial::severity >= boost::log::trivial::error);
  }else if(level == "warning"){
    boost::log::core::get()->set_filter(boost::log::trivial::severity >= boost::log::trivial::warning);
  }else if(level == "info"){
    boost::log::core::get()->set_filter(boost::log::trivial::severity >= boost::log::trivial::info);
  }else if(level == "debug"){
    boost::log::core::get()->set_filter(boost::log::trivial::severity >= boost::log::trivial::debug);
  }else if(level == "trace"){
    boost::log::core::get()->set_filter(boost::log::trivial::severity >= boost::log::trivial::trace);
  }
}

int main(int argc, char** argv){
	if(argc >= 2){
		set_log_level(*(argv+1));
	}
  boost::log::add_console_log(std::cout, boost::log::keywords::format = ">> %Message%");
	//boost::log::add_file_log("log.txt");
	BOOST_LOG_TRIVIAL(fatal) << "fatal";
	BOOST_LOG_TRIVIAL(error) << "error";
	BOOST_LOG_TRIVIAL(warning) << "warning";
	BOOST_LOG_TRIVIAL(info) << "info";
	BOOST_LOG_TRIVIAL(debug) << "debug";
	BOOST_LOG_TRIVIAL(trace) << "trace";
	return 0;
}
