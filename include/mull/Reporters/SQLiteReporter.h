#include "Reporter.h"

#include <memory>
#include <string>
#include <vector>

namespace mull {

class Result;
class RawConfig;
class Metrics;

class SQLiteReporter : public Reporter {

private:
  std::string databasePath;

public:
  SQLiteReporter(const std::string &projectName = std::string(""));

  void reportResults(const Result &result, const RawConfig &config,
                     const Metrics &metrics) override;

  std::string getDatabasePath();
};

} // namespace mull
