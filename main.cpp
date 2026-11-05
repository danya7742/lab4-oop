#include "Salon.h"
#include <memory>
using namespace std;

int main() {
  cout << "===== LAB 4: BARBERSHOP =====\n";
  cout << "\n[1] Creating objects\n";
  // п.22: три способи створення об'єктів
  Client first("Client1", "Classic", "111", 1, 1, 200);
  Client second("Client2", "Fade", "222", 2, 2, 250);
  Client third = Client("Client3", "Crop", "333", 3, 3, 300);
  Client fourth("Client4", "Classic", "444", 4, 4, 350);
  Client fifth("Client5", "Fade", "555", 5, 5, 400);
  Client copyOfSecond(second);              // конструктор копіювання
  Client clients[5] = {first, second, third, fourth, fifth}; // п.23, 24

  // п.14: ще 5 динамічних об'єктів
  Client* dynamicClients[5];
  for (int i = 0; i < 5; ++i)
    dynamicClients[i] = new Client("Dynamic" + to_string(i + 1), "Classic", "555", i + 10, i, 200);

  // п.11: public наслідування, доступ через :: та using
  Barber barber("Barber1", "Fade", "Morning", 11, 150);
  Manager manager("Manager1", 21, 170, "Main salon");
  Assistant assistant("Helper1", 30);      // п.9: private наслідування
  SeniorBarber senior("Senior1", 40, 200); // п.10: множинне наслідування

  cout << "\n[2] Salon workflow\n";
  manager.showQueue(clients, 5);
  manager.catalog(); // п.11: using Barber::catalog
  manager.Barber::show(); // п.11: оператор ::
  barber.catalog();
  manager.assign(clients[0], barber);
  clients[0].pay();
  barber.serve(clients[0]);
  manager.approve(clients[0].price());
  assistant.help(clients[1]);
  assistant.raise(20);
  clients[1].pay(250);
  senior.work(clients[1], 30);
  senior.summary();
  senior.HairSkill::show(true);
  senior.SalesSkill::show(true);
  senior.ScheduleSkill::show(true);
  senior.HairSkill::train(2);
  senior.SalesSkill::sell(80, 5);
  senior.ScheduleSkill::book(2);
  cout << "Manager total: " << manager.dailyTotal() << '\n';

  cout << "\n--- Methods and calculations ---\n";
  // п.6: перевантажені методи, функції з об'єктами
  clients[0].show(true);
  barber.show(true);
  manager.show(true);
  assistant.show(true);
  senior.show(true);
  cout << "Same haircut: " << (clients[0].sameHaircut(clients[3]) ? "yes" : "no") << '\n';
  calculate(clients[0]);                   // п.19: зовнішня функція
  calculate(&clients[0]);                  // п.20: покажчик
  Client returned = makeClient(clients[0]); // п.21: функція повертає Client
  returned.show();
  Client copiedAgain = clients[0].copy();
  copiedAgain.show();
  barber.copy().show();
  manager.copy().show();
  assistant.copy().show();
  senior.copy().show();

  cout << "\n--- Files ---\n";
  // п.7: читання/запис у файли
  clients[0].save("client.txt");
  barber.save("barber.txt");
  manager.save("manager.txt");
  assistant.save("assistant.txt");
  senior.save("senior.txt");
  Person person;
  person.setName("DemoPerson"); person.setPhone("000");
  person.show(true); person.save("person.txt");
  Person personLoaded; personLoaded.load("person.txt"); personLoaded.show();
  Client loaded;
  loaded.load("client.txt");
  Barber barberLoaded; barberLoaded.load("barber.txt"); barberLoaded.show();
  Manager managerLoaded; managerLoaded.load("manager.txt"); managerLoaded.show();
  Assistant assistantLoaded; assistantLoaded.load("assistant.txt"); assistantLoaded.show();
  SeniorBarber seniorLoaded; seniorLoaded.load("senior.txt"); seniorLoaded.show();
  cout << "Loaded client: "; loaded.show();

  cout << "\n--- Composition ---\n";
  // п.3: об’єкти Client, Barber, Manager тощо всередині SalonSystem
  SalonSystem system("Barbershop", "Main street");
  system.show(true);
  system.run();
  system.show();
  system.save("salon.txt");
  SalonSystem otherSystem(system);
  cout << "Same branch: " << system.sameBranch(otherSystem) << '\n';
  SalonSystem systemLoaded; systemLoaded.load("salon.txt"); systemLoaded.show();

  cout << "\n--- Friend access ---\n";
  // п.16, 17: friend функція та friend клас
  inspectPerson(clients[0]);
  Auditor auditor;
  auditor.check(barber);

  cout << "\n--- Static counter and destructors ---\n";
  // п.18: статичний елемент і метод
  cout << "People alive: " << Person::alive() << '\n';
  // п.15: деструктори при виході з блоку
  lifecycleLog() = true;
  {
    Client temporary("Temporary", "Crop", "000", 99, 0, 300);
    cout << "Inside block: " << Person::alive() << '\n';
  }
  lifecycleLog() = false;
  cout << "After block: " << Person::alive() << '\n';

  cout << "\n--- Pointers and cleanup ---\n";
  // п.12, 23: поліморфізм через покажчик на базовий клас
  Person* ptr = &senior;
  ptr->show();
  for (Client* p : dynamicClients) delete p;
  cout << "After delete: " << Person::alive() << '\n';

  return 0;
}
