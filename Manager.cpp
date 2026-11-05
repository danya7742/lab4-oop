#include "Salon.h"
namespace { const int kSalonBranch = 7; }
Manager::Manager() : Manager("Unknown",0,150,"Salon") {}
Manager::Manager(string n,int id,int rate,string d)
    : Barber(n,"Management","Morning",id,rate), department(d),schedule("9-18"),position("Manager"),
      target_(1000),total_(0),orders_(0),level_(1),commission_(10),branchCode_(7),branchReference_(kSalonBranch) { if (lifecycleLog()) cout << "Manager constructor\n"; }
Manager::Manager(const Manager& o) : Barber(o),department(o.department),schedule(o.schedule),position(o.position),
    target_(o.target_),total_(o.total_),orders_(o.orders_),level_(o.level_),commission_(o.commission_),branchCode_(o.branchCode_),branchReference_(kSalonBranch) { if (lifecycleLog()) cout << "Manager copy constructor\n"; }
Manager::~Manager() { if (lifecycleLog()) cout << "Manager destructor\n"; }
void Manager::show() const { cout << "Manager: " << name << ", department: " << department << ", orders: " << orders_ << '\n'; }
void Manager::show(bool d) const { show(); if(d) cout << "Schedule: " << schedule << ", position: " << position << ", target: " << target_ << ", total: " << total_ << ", level: " << level_ << ", commission: " << commission_ << ", branch=" << branchCode_ << ", ref=" << branchReference_ << '\n'; }
void Manager::showQueue(const Client clients[],int count) const { for(int i=0;i<count;i++) cout << i+1 << ". " << clients[i].name << " - " << clients[i].haircut << '\n'; }
void Manager::assign(Client& client,Barber& barber) const { cout << "Manager assigned " << client.name << " to " << barber.name << '\n'; }
void Manager::approve(int amount) { approve(amount,0); }
void Manager::approve(int amount,int bonus) { total_ += amount + bonus; ++orders_; }
int Manager::dailyTotal() const { return total_; }
Manager Manager::copy() const { return Manager(*this); }
void Manager::save(const string& file) const { ofstream out(file); out << name << '\n' << department << '\n' << schedule << '\n' << position << '\n' << id_ << ' ' << target_ << ' ' << total_ << ' ' << orders_ << ' ' << level_ << ' ' << commission_ << ", branch=" << branchCode_ << ", ref=" << branchReference_ << '\n'; }
void Manager::load(const string& file) { ifstream in(file); if(!in) return; getline(in,name); getline(in,department); getline(in,schedule); getline(in,position); in >> id_ >> target_ >> total_ >> orders_ >> level_ >> commission_; }
