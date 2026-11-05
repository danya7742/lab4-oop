#include "Salon.h"
Client::Client() : Client("Unknown", "Classic", "none", 0, 0, 200) {}
Client::Client(string n, string h, string p, int id, int q, int price)
    : Person(n,p,"Khmelnytskyi",id,18,0,5,0), haircut(h), email("none"), note("new"),
      queue_(q), price_(price), paid_(0), visitsCount_(0), discount_(0) { if (lifecycleLog()) cout << "Client constructor\n"; }
Client::Client(const Client& o) : Person(o), haircut(o.haircut), email(o.email), note(o.note),
    queue_(o.queue_), price_(o.price_), paid_(o.paid_), visitsCount_(o.visitsCount_), discount_(o.discount_) { if (lifecycleLog()) cout << "Client copy constructor\n"; }
Client::~Client() { if (lifecycleLog()) cout << "Client destructor: " << name << '\n'; }
void Client::show() const { cout << "Client: " << name << ", haircut: " << haircut << ", price: " << price_ << '\n'; }
void Client::show(bool details) const { show(); if(details) cout << "Phone: " << phone << ", email: " << email << ", note: " << note << ", queue: " << queue_ << ", paid: " << paid_ << ", visits: " << visitsCount_ << ", discount: " << discount_ << '\n'; }
void Client::pay() { pay(price_ - discount_); }
void Client::pay(int amount) { if(amount >= price_ - discount_) { paid_ = amount; ++visitsCount_; } }
int Client::price() const { return price_; }
int Client::queue() const { return queue_; }
bool Client::isPaid() const { return paid_ >= price_ - discount_; }
void Client::setQueue(int v) { queue_ = v; }
bool Client::sameHaircut(const Client& o) const { return haircut == o.haircut; }
Client Client::copy() const { return Client(*this); }
void Client::save(const string& file) const { ofstream out(file); out << name << '\n' << haircut << '\n' << phone << '\n' << email << '\n' << note << '\n' << id_ << ' ' << queue_ << ' ' << price_ << ' ' << paid_ << ' ' << visitsCount_ << ' ' << discount_ << '\n'; }
void Client::load(const string& file) { ifstream in(file); if(!in) return; getline(in,name); getline(in,haircut); getline(in,phone); getline(in,email); getline(in,note); in >> id_ >> queue_ >> price_ >> paid_ >> visitsCount_ >> discount_; }
void calculate(const Client& c) { cout << "Price (object): " << c.price() << '\n'; }
void calculate(const Client* c) { if(c) cout << "Half price (pointer): " << c->price()/2.0 << '\n'; }
Client makeClient(const Client& c) { Client result(c); result.note = "copied"; return result; }
