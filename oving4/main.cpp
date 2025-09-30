#include <iostream>
#include <vector>
#include <algorithm>
#include <gtkmm.h>
using namespace std;

void task1();

int task2();

int main() {
  task1();
  return task2();
}

void task1() {
  vector<double> v = {1.1, 2.2, 3.3, 4.4, 5.5};
  
  // Teste front() og back()
  cout << "Første element (front): " << v.front() << endl;
  cout << "Siste element (back): " << v.back() << endl;
  
  // Bruk emplace() også skriv ut front()
  v.emplace(v.begin() + 1, 9.9);
  cout << "Første element etter emplace: " << v.front() << endl;
  
  // Skriv ut hele vektoren for oversikt
  cout << "Vektoren inneholder: ";
  for (double x : v) {
      cout << x << " ";
  }
  cout << endl;
  
  // Bruk find()
  double soekVerdi = 3.3;
  auto it = find(v.begin(), v.end(), soekVerdi);
  
  if (it != v.end()) {
      cout << "Fant verdien " << *it << " i vektoren." << endl;
  } else {
      cout << "Fant ikke verdien " << soekVerdi << " i vektoren." << endl;
  }
}

class Window : public Gtk::Window {
public:
  Gtk::Box box;
  Gtk::Entry entry_first_name;
  Gtk::Entry entry_last_name;
  Gtk::Button button;
  Gtk::Label label_first_name;
  Gtk::Label label_last_name;
  Gtk::Label label_result;

  Window() : box(Gtk::Orientation::ORIENTATION_VERTICAL) {
    // Fixed names
    button.set_label("Combine names");
    label_first_name.set_text("First name");
    label_last_name.set_text("Last name");

    // Add elements
    box.pack_start(label_first_name);
    box.pack_start(entry_first_name);
    box.pack_start(label_last_name);
    box.pack_start(entry_last_name);
    box.pack_start(button);
    box.pack_start(label_result);
    
    add(box);   // Add vbox to window
    show_all(); // Show all widgets
    
    // Button sensitivity
    button.set_sensitive(false); // Initially disable the button
    auto update_button_state = [this]() {
      bool enable = !entry_first_name.get_text().empty() && !entry_last_name.get_text().empty();
      button.set_sensitive(enable);
    };
    entry_first_name.signal_changed().connect(update_button_state);
    entry_last_name.signal_changed().connect(update_button_state);

    // Button function
    button.signal_clicked().connect([this]() {
      label_result.set_text(
          "Names combined: "
          + entry_first_name.get_text()
          + " "
          + entry_last_name.get_text()
      );
    });
  }
};

int task2() {
  auto app = Gtk::Application::create();
  Window window;
  return app->run(window);
}
