#include "Application.hpp"

int main(int argc, char** argv)
{
  return Wt::WRun(argc, argv, [](const Wt::WEnvironment &env) {
    return new wtrs::Application(env);
  });
  return 0;
}
