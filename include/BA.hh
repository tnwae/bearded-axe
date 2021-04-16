#include <BA/Platform.hh>
#include <BA/Common.hh>

#if ! defined _BA_HH
#define _BA_HH
using namespace std;

#if ! defined __cplusplus
#error "C++ supported only."
#endif

/* Procedural functions we'll need to talk to the standard bits */
void error(string, ...);
void message(string, ...);

namespace BA {
  const int DEBUG_LOG = 2;
  const int INFO_LOG  = 1;
  const int NOLOG_MSG = 0;
  const int SILENT_LOG = -1;

  void ConsoleMessage(std::string fmt, ...);
  void LogMessage(std::string fmt, ...);
  void DebugMessage(std::string fmt, ...);
}

#endif /* defined _BA_HH */
