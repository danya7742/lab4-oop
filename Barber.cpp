#include "Salon.h"
Barber::Barber() : Barber("Unknown","Classic","Morning",0,150) {}
Barber::Barber(string n,string s,string sh,int id,int rate)
    : Person(n,"none","Khmelnytskyi",id,25,3,5,0), specialty(s),shift(sh),chair("A1"),
      rate_(rate),earned_(0),served_(0),bonus_(0),tips_(0) { if (lifecycleLog()) cout << "Barber constructor\n"; }
Barber::Barber(const Barber& o) : Person(o),specialty(o.specialty),shift(o.shift),chair(o.chair),
      rate_(o.rate_),earned_(o.earned_),served_(o.served_),bonus_(o.bonus_),tips_(o.tips_) { if (lifecycleLog()) cout << "Barber copy constructor\n"; }
Barber::~Barber() { if (lifecycleLog()) cout << "Barber destructor: " << name << '\n'; }
void Barber::show() const { cout << "Barber: " << name << ", specialty: " << specialty << ", served: " << served_ << '\n'; }
void Barber::show(bool d) const { show(); if(d) cout << "Shift: " << shift << ", chair: " << chair << ", rate: " << rate_ << ", earned: " << earned_ << ", bonus: " << bonus_ << ", tips: " << tips_ << '\n'; }
void Barber::catalog() const { cout << "Catalog: Classic 200, Fade 250, Crop 300\n"; }
void Barber::serve(Client& client) { serve(client,0); }
void Barber::serve(Client& client,int extra) { if(client.isPaid()) { ++served_; earned_ += rate_; bonus_ += 20; tips_ += extra; cout << name << " served " << client.name << '\n'; } else cout << "Client must pay first\n"; }
int Barber::rate() const { return rate_; }
int Barber::earned() const { return earned_ + bonus_ + tips_; }
int Barber::served() const { return served_; }
Barber Barber::copy() const { return Barber(*this); }
void Barber::save(const string& file) const { ofstream out(file); out << name << '\n' << specialty << '\n' << shift << '\n' << chair << '\n' << id_ << ' ' << rate_ << ' ' << earned_ << ' ' << served_ << ' ' << bonus_ << ' ' << tips_ << '\n'; }
void Barber::load(const string& file) { ifstream in(file); if(!in) return; getline(in,name); getline(in,specialty); getline(in,shift); getline(in,chair); in >> id_ >> rate_ >> earned_ >> served_ >> bonus_ >> tips_; }
