#ifndef SALON_H_
#define SALON_H_
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

bool& lifecycleLog();  // показ повідомлень про життєвий цикл

// п.1, 2, 8: базовий клас, 8 полів, public/protected/private
class Person {
 public:
  string name, phone, city;                 // 3 public поля
  Person();
  Person(string name, string phone, string city, int id, int age,
         int experience, int rating, int visits);
  Person(const Person& other);
  virtual ~Person();
  virtual void show() const;
  void show(bool details) const;             // п.6: перевантаження
  void setName(string value);
  void setPhone(string value);
  int getId() const;
  int getAge() const;
  int getRating() const;
  void save(const string& file) const;       // п.7: файл
  void load(const string& file);
  static int alive();                       // п.18: static метод
  friend class Auditor;                    // п.17: дружній клас
  friend void inspectPerson(const Person& p); // п.16: дружня функція
 protected:
  int id_;                                  // protected
  int experience_;
 private:
  int age_, rating_, visits_;               // private, разом 8 полів
  static int alive_;
};

// п.1, 2: похідний клас клієнта (8 власних полів)
class Client : public Person {
 public:
  string haircut, email, note;              // 3 public
  Client();
  Client(string name, string haircut, string phone, int id, int queue, int price);
  Client(const Client& other);
  ~Client() override;
  void show() const override;
  void show(bool details) const;
  void pay();
  void pay(int amount);                    // п.6: перевантаження
  int price() const;
  int queue() const;
  bool isPaid() const;
  void setQueue(int value);
  bool sameHaircut(const Client& other) const; // об'єкт як параметр
  Client copy() const;                     // повертає Client
  void save(const string& file) const;
  void load(const string& file);
 private:
  int queue_, price_, paid_, visitsCount_, discount_; // 5 private
};

// п.1, 2: похідний клас перукаря
class Barber : public Person {
 public:
  string specialty, shift, chair;          // 3 public
  Barber();
  Barber(string name, string specialty, string shift, int id, int rate);
  Barber(const Barber& other);
  ~Barber() override;
  void show() const override;
  void show(bool details) const;
  void catalog() const;
  void serve(Client& client);
  void serve(Client& client, int bonus);    // перевантаження
  int rate() const;
  int earned() const;
  int served() const;
  Barber copy() const;
  void save(const string& file) const;
  void load(const string& file);
 private:
  int rate_, earned_, served_, bonus_, tips_; // 5 private
};

// п.1, 8: менеджер наслідує працівника через public
class Manager : public Barber {
 public:
  using Barber::catalog; // п.11: using відкриває метод базового класу
  string department, schedule, position;
  Manager();
  Manager(string name, int id, int rate, string department);
  Manager(const Manager& other);
  ~Manager() override;
  void show() const override;
  void show(bool details) const;
  void showQueue(const Client clients[], int count) const;
  void assign(Client& client, Barber& barber) const;
  void approve(int amount);
  void approve(int amount, int bonus);
  int dailyTotal() const;
  Manager copy() const;
  void save(const string& file) const;
  void load(const string& file);
 private:
  int target_, total_, orders_, level_, commission_;
  const int branchCode_;
  const int& branchReference_; // п.5: константа і посилання через список ініціалізації
};

// п.9: додатковий клас із private наслідуванням
class Assistant : private Barber {
 public:
  Assistant();
  Assistant(string name, int id);
  Assistant(const Assistant& other);
  ~Assistant();
  void show() const;
  void show(bool details) const;
  void help(Client& client);
  int salary() const;
  Assistant copy() const;
  void save(const string& file) const;
  void load(const string& file);
  void raise(int sum);
 private:
  int salary_, tasks_, bonus_, days_, level_;
  string tool_, area_, status_;
};

// п.10: три додаткові класи для множинного наслідування
class HairSkill {
 public:
  string style, tool, certificate;
  HairSkill();
  HairSkill(string style, string tool, string certificate, int level);
  HairSkill(const HairSkill& other);
  ~HairSkill();
  void show() const;
  void show(bool details) const;
  void train();
  void train(int hours);
  int level() const;
  HairSkill copy() const;
  void save(const string& file) const;
  void load(const string& file);
 private:
  int level_, hours_, courses_, clients_, score_;
};

class SalesSkill {
 public:
  string product, brand, section;
  SalesSkill();
  SalesSkill(string product, string brand, string section, int plan);
  SalesSkill(const SalesSkill& other);
  ~SalesSkill();
  void show() const;
  void show(bool details) const;
  void sell(int amount);
  void sell(int amount, int extra);
  int total() const;
  SalesSkill copy() const;
  void save(const string& file) const;
  void load(const string& file);
 private:
  int plan_, total_, sales_, discount_, bonus_;
};

class ScheduleSkill {
 public:
  string day, room, comment;
  ScheduleSkill();
  ScheduleSkill(string day, string room, string comment, int start);
  ScheduleSkill(const ScheduleSkill& other);
  ~ScheduleSkill();
  void show() const;
  void show(bool details) const;
  void book();
  void book(int hours);
  int bookings() const;
  ScheduleSkill copy() const;
  void save(const string& file) const;
  void load(const string& file);
 private:
  int start_, end_, slots_, bookings_, breaks_;
};

// п.10, 12: множинне наслідування
class SeniorBarber : public Barber, public HairSkill,
                     public SalesSkill, public ScheduleSkill {
 public:
  SeniorBarber();
  SeniorBarber(string name, int id, int rate);
  SeniorBarber(const SeniorBarber& other);
  ~SeniorBarber() override;
  void show() const override;
  void show(bool details) const;
  void work(Client& client);
  void work(Client& client, int tip);
  int totalIncome() const;
  SeniorBarber copy() const;
  void save(const string& file) const;
  void load(const string& file);
  void summary() const;
  string title, roomName, team;
 private:
  int rank_, clients_, targets_, awards_, overtime_;
};

// п.3: композиція, об'єкти класів зберігаються в іншому класі
class SalonSystem {
 public:
  string branch, address, status;
  SalonSystem();
  SalonSystem(string branch, string address);
  SalonSystem(const SalonSystem& other);
  ~SalonSystem();
  void show() const;
  void show(bool details) const;
  void run();
  void run(int amount);
  bool sameBranch(const SalonSystem& other) const;
  SalonSystem copy() const;
  void save(const string& file) const;
  void load(const string& file);
 private:
  Client client_;
  Barber barber_;
  Manager manager_;
  Assistant assistant_;
  SeniorBarber senior_;
};

class Auditor { public: void check(const Person& p) const; };
void inspectPerson(const Person& p);
void calculate(const Client& client);      // п.19
void calculate(const Client* client);      // п.20
Client makeClient(const Client& client);   // п.21

#endif
