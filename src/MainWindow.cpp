#include "MainWindow.hpp"

#include <Wt/WLineEdit>
#include <Wt/WLabel>

#include <Wt/Http/Client>
#include <Wt/WLineEdit>
#include <Wt/WLabel>
#include <Wt/WTemplateFormView>
#include <Wt/WFormModel>
#include <Wt/WLengthValidator>
#include <Wt/WPushButton>

namespace wtrs {

namespace loginFormFields {
Wt::WFormModel::Field username = "username";
Wt::WFormModel::Field apiKey = "api-key";
}

MainWindow::MainWindow(Wt::WContainerWidget *parent)
    : Wt::WTemplateFormView(parent) {
  using namespace loginFormFields;
  setTemplateText(tr("login-form"));
  auto model = new Wt::WFormModel(this);
  // Username
  model->addField(username);
  model->setValidator(username, new Wt::WValidator());
  setFormWidget(username, new Wt::WLineEdit());
  // API Key
  model->addField(apiKey);
  auto apiKeyField = new Wt::WLineEdit();
  apiKeyField->setEchoMode(Wt::WLineEdit::Password);
  setFormWidget(apiKey, apiKeyField);
  model->setValidator(apiKey, new Wt::WLengthValidator(32, 32));
  // Login button
  auto btn = new Wt::WPushButton("Login");
  bindWidget("login", btn);
}

}
