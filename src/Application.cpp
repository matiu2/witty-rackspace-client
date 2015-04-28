#include "Application.hpp"

#include "MainWindow.hpp"

#include <Wt/WBootstrapTheme>

namespace wtrs {

Application::Application(const Wt::WEnvironment& env) : Wt::WApplication(env) {
  setTheme(new Wt::WBootstrapTheme());
  messageResourceBundle().use(appRoot() + "MainWindow");
  new MainWindow(root());
}

}
