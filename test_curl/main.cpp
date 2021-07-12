#include <iostream>
#include <string>
#include <curl/curl.h>

size_t writeCallback(char *contents, size_t size, size_t nmemb, void *userp)
{
  ((std::string *)userp)->append((char *)contents, size * nmemb);
  return size * nmemb;
}

int main(int argc, char **argv)
{
  curl_global_init(CURL_GLOBAL_ALL);

  CURL *curl = curl_easy_init();
  if (curl)
  {
    std::string str;

    curl_easy_setopt(curl, CURLOPT_URL, "https://randomuser.me/api/?results=5");
    // curl_easy_setopt(curl, CURLOPT_POSTFIELDS, "name=daniel&project=curl");
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &str);
    // curl_easy_setopt(curl, CURLOPT_HEADER, 1L);

    CURLcode res = curl_easy_perform(curl);
    if (res != CURLE_OK)
    {
      std::cout << "error: curl_easy_perform" << std::endl;
    }

    curl_easy_cleanup(curl);

    std::cout << str << std::endl;
  }

  curl_global_cleanup();

  return EXIT_SUCCESS;
}
