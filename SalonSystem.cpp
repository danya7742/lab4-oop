#include "Salon.h"
SalonSystem::SalonSystem() : SalonSystem("Salon7", "Central street") {}
SalonSystem::SalonSystem(string b, string a) : branch(b), address(a), status("Open"),
  client_("DemoClient","Classic","111",1,1,200),
  barber_("DemoBarber","Classic","Morning",2,150),
  manager_("DemoManager",3,170,"Main"),
  assistant_("DemoAssistant",4), senior_("DemoSenior",5,200) { if (lifecycleLog()) cout << "SalonSystem constructor\n"; }
SalonSystem::SalonSystem(const SalonSystem& o) : branch(o.branch),address(o.address),status(o.status),
  client_(o.client_),barber_(o.barber_),manager_(o.manager_),assistant_(o.assistant_),senior_(o.senior_) { if (lifecycleLog()) cout << "SalonSystem copy constructor\n"; }
SalonSystem::~SalonSystem() { if (lifecycleLog()) cout << "SalonSystem destructor\n"; }
void SalonSystem::show() const { cout << "Salon: " << branch << ", " << address << ", status: " << status << '\n'; }
void SalonSystem::show(bool detail) const { show(); if(detail){client_.show();barber_.show();manager_.show();assistant_.show();senior_.show();} }
void SalonSystem::run() { run(200); }
void SalonSystem::run(int amount) { client_.pay(amount);manager_.assign(client_,barber_);barber_.serve(client_);manager_.approve(amount);assistant_.help(client_);senior_.HairSkill::train();status="Busy"; }
bool SalonSystem::sameBranch(const SalonSystem& o) const { return branch==o.branch; }
SalonSystem SalonSystem::copy() const { return SalonSystem(*this); }
void SalonSystem::save(const string& f) const { ofstream out(f);out<<branch<<'\n'<<address<<'\n'<<status<<'\n'; }
void SalonSystem::load(const string& f) { ifstream in(f);if(!in)return;getline(in,branch);getline(in,address);getline(in,status); }
