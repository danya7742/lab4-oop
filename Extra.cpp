#include "Salon.h"
Assistant::Assistant() : Assistant("Unknown",0) {}
Assistant::Assistant(string n,int id) : Barber(n,"Assistant","Morning",id,100),
 salary_(100),tasks_(0),bonus_(0),days_(1),level_(1),tool_("Comb"),area_("Hall"),status_("Free") { if (lifecycleLog()) cout << "Assistant constructor\n"; }
Assistant::Assistant(const Assistant& o) : Barber(o),salary_(o.salary_),tasks_(o.tasks_),bonus_(o.bonus_),days_(o.days_),level_(o.level_),tool_(o.tool_),area_(o.area_),status_(o.status_) {}
Assistant::~Assistant() { if (lifecycleLog()) cout << "Assistant destructor\n"; }
void Assistant::show() const { cout << "Assistant: " << name << ", salary: " << salary_ << ", tasks: " << tasks_ << '\n'; }
void Assistant::show(bool d) const { show(); if(d) cout << "Tool: " << tool_ << ", area: " << area_ << ", status: " << status_ << ", days: " << days_ << ", level: " << level_ << ", bonus: " << bonus_ << '\n'; }
void Assistant::help(Client& c) { ++tasks_; status_="Busy"; cout << "Assistant helps " << c.name << '\n'; }
int Assistant::salary() const { return salary_ + bonus_; }
Assistant Assistant::copy() const { return Assistant(*this); }
void Assistant::save(const string& f) const { ofstream o(f); o << name << '\n' << tool_ << '\n' << area_ << '\n' << status_ << '\n' << salary_ << ' ' << tasks_ << ' ' << bonus_ << ' ' << days_ << ' ' << level_ << '\n'; }
void Assistant::load(const string& f) { ifstream i(f); if(!i)return; getline(i,name);getline(i,tool_);getline(i,area_);getline(i,status_);i>>salary_>>tasks_>>bonus_>>days_>>level_; }
void Assistant::raise(int v) { if(v>0) bonus_+=v; }

HairSkill::HairSkill() : HairSkill("Classic","Scissors","Basic",1) {}
HairSkill::HairSkill(string s,string t,string c,int l) : style(s),tool(t),certificate(c),level_(l),hours_(0),courses_(1),clients_(0),score_(5) { if (lifecycleLog()) cout << "HairSkill constructor\n"; }
HairSkill::HairSkill(const HairSkill& o) : style(o.style),tool(o.tool),certificate(o.certificate),level_(o.level_),hours_(o.hours_),courses_(o.courses_),clients_(o.clients_),score_(o.score_) {}
HairSkill::~HairSkill() { if (lifecycleLog()) cout << "HairSkill destructor\n"; }
void HairSkill::show() const { cout << "Hair skill: " << style << ", level: " << level_ << '\n'; }
void HairSkill::show(bool d) const { show(); if(d) cout << tool << ' ' << certificate << " hours=" << hours_ << " courses=" << courses_ << " clients=" << clients_ << " score=" << score_ << '\n'; }
void HairSkill::train() { train(1); }
void HairSkill::train(int h) { if(h>0) { hours_+=h; ++courses_; ++level_; ++clients_; ++score_; } }
int HairSkill::level() const { return level_; }
HairSkill HairSkill::copy() const { return HairSkill(*this); }
void HairSkill::save(const string& f) const { ofstream o(f);o<<style<<'\n'<<tool<<'\n'<<certificate<<'\n'<<level_<<' '<<hours_<<' '<<courses_<<' '<<clients_<<' '<<score_<<'\n'; }
void HairSkill::load(const string& f) { ifstream i(f);if(!i)return;getline(i,style);getline(i,tool);getline(i,certificate);i>>level_>>hours_>>courses_>>clients_>>score_; }

SalesSkill::SalesSkill() : SalesSkill("Shampoo","Brand","Hair",100) {}
SalesSkill::SalesSkill(string p,string b,string s,int plan) : product(p),brand(b),section(s),plan_(plan),total_(0),sales_(0),discount_(0),bonus_(0) { if (lifecycleLog()) cout << "SalesSkill constructor\n"; }
SalesSkill::SalesSkill(const SalesSkill& o) : product(o.product),brand(o.brand),section(o.section),plan_(o.plan_),total_(o.total_),sales_(o.sales_),discount_(o.discount_),bonus_(o.bonus_) {}
SalesSkill::~SalesSkill() { if (lifecycleLog()) cout << "SalesSkill destructor\n"; }
void SalesSkill::show() const { cout << "Sales: " << product << ", total: " << total_ << '\n'; }
void SalesSkill::show(bool d) const { show();if(d)cout<<brand<<' '<<section<<" plan="<<plan_<<" sales="<<sales_<<" discount="<<discount_<<" bonus="<<bonus_<<'\n'; }
void SalesSkill::sell(int amount) { sell(amount,0); }
void SalesSkill::sell(int amount,int extra) { if(amount>0){total_+=amount+extra-discount_;++sales_;bonus_+=extra;} }
int SalesSkill::total() const { return total_; }
SalesSkill SalesSkill::copy() const { return SalesSkill(*this); }
void SalesSkill::save(const string& f) const { ofstream o(f);o<<product<<'\n'<<brand<<'\n'<<section<<'\n'<<plan_<<' '<<total_<<' '<<sales_<<' '<<discount_<<' '<<bonus_<<'\n'; }
void SalesSkill::load(const string& f) { ifstream i(f);if(!i)return;getline(i,product);getline(i,brand);getline(i,section);i>>plan_>>total_>>sales_>>discount_>>bonus_; }

ScheduleSkill::ScheduleSkill() : ScheduleSkill("Monday","Room1","Open",9) {}
ScheduleSkill::ScheduleSkill(string d,string r,string c,int start) : day(d),room(r),comment(c),start_(start),end_(18),slots_(8),bookings_(0),breaks_(1) { if (lifecycleLog()) cout << "ScheduleSkill constructor\n"; }
ScheduleSkill::ScheduleSkill(const ScheduleSkill& o) : day(o.day),room(o.room),comment(o.comment),start_(o.start_),end_(o.end_),slots_(o.slots_),bookings_(o.bookings_),breaks_(o.breaks_) {}
ScheduleSkill::~ScheduleSkill() { if (lifecycleLog()) cout << "ScheduleSkill destructor\n"; }
void ScheduleSkill::show() const { cout << "Schedule: " << day << ", bookings: " << bookings_ << '\n'; }
void ScheduleSkill::show(bool d) const { show();if(d)cout<<room<<' '<<comment<<" start="<<start_<<" end="<<end_<<" slots="<<slots_<<" breaks="<<breaks_<<'\n'; }
void ScheduleSkill::book() { book(1); }
void ScheduleSkill::book(int hours) { if(hours>0 && bookings_+hours<=slots_)bookings_+=hours; }
int ScheduleSkill::bookings() const { return bookings_; }
ScheduleSkill ScheduleSkill::copy() const { return ScheduleSkill(*this); }
void ScheduleSkill::save(const string& f) const { ofstream o(f);o<<day<<'\n'<<room<<'\n'<<comment<<'\n'<<start_<<' '<<end_<<' '<<slots_<<' '<<bookings_<<' '<<breaks_<<'\n'; }
void ScheduleSkill::load(const string& f) { ifstream i(f);if(!i)return;getline(i,day);getline(i,room);getline(i,comment);i>>start_>>end_>>slots_>>bookings_>>breaks_; }

SeniorBarber::SeniorBarber() : SeniorBarber("Unknown",0,200) {}
SeniorBarber::SeniorBarber(string n,int id,int rate)
    : Barber(n,"Fade","Morning",id,rate), HairSkill("Fade","Scissors","Pro",3),
      SalesSkill("Shampoo","Brand","Hair",500), ScheduleSkill("Monday","Main","Open",9),
      title("Senior"),roomName("VIP"),team("A"),rank_(3),clients_(0),targets_(10),awards_(1),overtime_(0) { if (lifecycleLog()) cout << "SeniorBarber constructor\n"; }
SeniorBarber::SeniorBarber(const SeniorBarber& o) : Barber(o),HairSkill(o),SalesSkill(o),ScheduleSkill(o),title(o.title),roomName(o.roomName),team(o.team),rank_(o.rank_),clients_(o.clients_),targets_(o.targets_),awards_(o.awards_),overtime_(o.overtime_) {}
SeniorBarber::~SeniorBarber() { if (lifecycleLog()) cout << "SeniorBarber destructor\n"; }
void SeniorBarber::show() const { cout << "Senior barber: " << name << ", income: " << totalIncome() << '\n'; }
void SeniorBarber::show(bool d) const { show();if(d)cout<<title<<' '<<roomName<<' '<<team<<" rank="<<rank_<<" clients="<<clients_<<" targets="<<targets_<<" awards="<<awards_<<" overtime="<<overtime_<<'\n'; }
void SeniorBarber::work(Client& c) { work(c,0); }
void SeniorBarber::work(Client& c,int tip) { Barber::serve(c,tip); if(c.isPaid()){++clients_;HairSkill::train();SalesSkill::sell(50);ScheduleSkill::book();} }
int SeniorBarber::totalIncome() const { return Barber::earned()+SalesSkill::total(); }
SeniorBarber SeniorBarber::copy() const { return SeniorBarber(*this); }
void SeniorBarber::save(const string& f) const { ofstream o(f);o<<name<<'\n'<<title<<'\n'<<roomName<<'\n'<<team<<'\n'<<rank_<<' '<<clients_<<' '<<targets_<<' '<<awards_<<' '<<overtime_<<'\n'; }
void SeniorBarber::load(const string& f) { ifstream i(f);if(!i)return;getline(i,name);getline(i,title);getline(i,roomName);getline(i,team);i>>rank_>>clients_>>targets_>>awards_>>overtime_; }
void SeniorBarber::summary() const { Barber::show(); HairSkill::show(); SalesSkill::show(); ScheduleSkill::show(); }
