#include <iostream>

#include <companion/ingest/ingest_controller.h>
#include <companion/logging/logger.h>

int main()
{
  std::cout << "Hello, World!" << std::endl;

  companion::ingest::IngestController ctl;
  std::cout << "Created the ingest controller!" << std::endl;

  companion::logging::Logger logger("Ingest", companion::logging::LogLevel::Information);
  logger.LogInformation("Hello logger world!");

  return 0;
}
