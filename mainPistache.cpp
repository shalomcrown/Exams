#include <iostream>

#include <pistache/endpoint.h>
#include <pistache/router.h>

struct HelloHandler : public Pistache::Http::Handler {
    HTTP_PROTOTYPE(HelloHandler)
    void onRequest(const Pistache::Http::Request&, Pistache::Http::ResponseWriter writer) override {
        writer.send(Pistache::Http::Code::Ok, "Hello, World!");
    }
};



int main() {
    Pistache::Rest::Router router;
    Pistache::Address addr(Pistache::Ipv4::any(), Pistache::Port(9080));

    auto opts = Pistache::Http::Endpoint::options().threads(1);
    Pistache::Http::Endpoint server(addr);
    server.init(opts);
    server.setHandler(Pistache::Http::make_handler<HelloHandler>());
    server.serve();
    return 0;
}
