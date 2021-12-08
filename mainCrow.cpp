//
// Created by shalomc on 08/12/2021.
//
#define CROW_MAIN
#include "crow_all.h"

void login(const crow::request& req, crow::response& response) {

}

int main()
{
    crow::SimpleApp app;
    CROW_ROUTE(app, "/")([](crow::response& response){response.set_static_file_info("../static/home.html"); response.end();});
    CROW_ROUTE(app, "login")(login);

    app.port(18080).multithreaded().run();
}
