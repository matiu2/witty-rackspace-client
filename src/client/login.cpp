#include "login.hpp"

#include <Wt/Http/Client>
#include <Wt/Json/Array>
#include <Wt/Json/Object>
#include <Wt/Json/Parser>
#include <Wt/Json/Serializer>
#include <Wt/Json/Value>

#include <stdexcept>

namespace rackspace {

void login(const std::string &username, const std::string &apiKey,
           std::function<void(Wt::Json::Object)> whenDone) {
  using namespace Wt::Json;
  // json should be { "auth":{ "RAX-KSKEY:apiKeyCredentials":{ "username":"${USER}", "apiKey":"${KEY}" } } }
  Object creds;
  creds.insert({"username", {username}});
  creds.insert({"apiKey", {apiKey}});
  Object auth;
  auth.insert({"RAX-KSKEY:apiKeyCredentials", creds});
  Object json;
  json.insert({"auth", auth});
  // Send the request - POST https://auth.api.rackspacecloud.com/v2.0/tokens
  Wt::Http::Client client;
  client.done().connect(std::bind(
      [&whenDone](boost::system::error_code code,
                  Wt::Http::Message msg) { std::err << msg << std::endl; },
      std::placeholders::_1, std::placeholders::_2));
  bool didPost = client.post("https://auth.api.rackspacecloud.com/v2.0/tokens", serialize(json));
  if (!didPost)
    throw std::runtime_error("Couldn't POST to login");
}

}
