#pragma once

#include <Wt/WApplication>

namespace wtrs {

class Application : public Wt::WApplication {
public:
  Application(const Wt::WEnvironment& env);
};


}
