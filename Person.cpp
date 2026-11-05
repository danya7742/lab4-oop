#include "Salon.h"
int Person::alive_ = 0;
bool& lifecycleLog() { static bool enabled = false; return enabled; }
Person::Person() : Person("Unknown", "none", "Khmelnytskyi", 0, 18, 0, 0, 0) {}
Person::Person(string n, string p, string c, int id, int age, int ex, int rating, int visits)
    : name(n), phone(p), city(c), id_(id), experience_(ex),
      age_(age), rating_(rating), visits_(visits) { ++alive_; if (lifecycleLog()) cout << "Person constructor: " << name << '\n'; }
Person::Person(const Person& o) : Person(o.name, o.phone, o.city, o.id_, o.age_, o.experience_, o.rating_, o.visits_) {}
Person::~Person() { --alive_; if (lifecycleLog()) cout << "Person destructor: " << name << '\n'; }
void Person::show() const { cout << "Person: " << name << ", id: " << id_ << ", phone: " << phone << '\n'; }
void Person::show(bool details) const { show(); if(details) cout << "City: " << city << ", age: " << age_ << ", experience: " << experience_ << ", rating: " << rating_ << ", visits: " << visits_ << '\n'; }
void Person::setName(string value) { name = value; }
void Person::setPhone(string value) { phone = value; }
int Person::getId() const { return id_; }
int Person::getAge() const { return age_; }
int Person::getRating() const { return rating_; }
void Person::save(const string& file) const { ofstream out(file); out << name << '\n' << phone << '\n' << city << '\n' << id_ << ' ' << age_ << ' ' << experience_ << ' ' << rating_ << ' ' << visits_ << '\n'; }
void Person::load(const string& file) { ifstream in(file); if (!in) return; getline(in,name); getline(in,phone); getline(in,city); in >> id_ >> age_ >> experience_ >> rating_ >> visits_; }
int Person::alive() { return alive_; }
void Auditor::check(const Person& p) const { cout << "Friend class: age=" << p.age_ << ", rating=" << p.rating_ << '\n'; }
void inspectPerson(const Person& p) { cout << "Friend function: " << p.name << ", visits=" << p.visits_ << '\n'; }
