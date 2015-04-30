/// Logs in to rackspace

#include <string>
#include <functional>
#include <Wt/Json/Object>

namespace rackspace {

/**
* @brief Logs you in to rackspace's API
*
* @param username Your rackspace api username
* @param apiKey Your rackspace api key
* @param whenDone Function to call back once we have all the json
*/
void login(const std::string &username, const std::string &apiKey);
}
