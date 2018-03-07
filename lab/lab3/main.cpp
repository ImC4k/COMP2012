
#include "CellularPhone.h"
#include "SmartPhone.h"
#include "iPhone.h"


int main() {
    CellularPhone* my_phone = new CellularPhone("Nokia", 12345678);
    my_phone->print();
    my_phone->call(12344321);
    my_phone->turn_on();
    my_phone->call(12344321);
    my_phone->print();
    delete my_phone; // NOTE: added by Calvin

    cout << endl;

    SmartPhone* my_smartphone = new SmartPhone("Samsung", 23456789);
    my_smartphone->print();
    { // NOTE: added by Calvin
      const OS* os = my_smartphone->get_os(); // NOTE: added by Calvin
      os->print(); // NOTE: added by Calvin
    } // NOTE: added by Calvin
    my_smartphone->turn_on();
    my_smartphone->call(12344321);
    my_smartphone->browse_web("http://www.google.com/");
    my_smartphone->turn_off();
    my_smartphone->browse_web("http://www.yahoo.com/");
    my_smartphone->print();
    delete my_smartphone; // NOTE: added by Calvin

    cout << endl;

    iPhone* my_iphone = new iPhone(34567890);
    my_iphone->print();
    my_iphone->turn_on();
    my_iphone->call(12344321);
    const OS* os = my_iphone->get_os();
    os->print();
    my_iphone->upgrade_os();
    os->print();
    my_iphone->print();
    delete my_iphone; // NOTE: added by Calvin
    return 0;
}
