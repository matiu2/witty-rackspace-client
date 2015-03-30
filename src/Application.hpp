#pragma once

#include <Wt/WApplication>

namespace WtRS {

class Application : public Wt::WApplication {
public:
  Application(const Wt::WEnvironment& env) : Wt::WApplication(env) {

  }
};


}
