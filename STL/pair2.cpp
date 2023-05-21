#include <algorithm>
#include <iostream>
#include <iterator>
#include <queue>
#include <string>
#include <tuple>
#include <utility>
using namespace std;

struct worker_info {
  // id, name, phone_num, country, city
  pair<pair<pair<int, string>, int>, pair<string, string>> w;

  worker_info() {}
  worker_info(int _id, string _name, int _phone_num, string _country,
              string _city) {
    // unpacking for these variable to pairs
    w.first.first.first = _id;
    w.first.first.second = _name;
    w.first.second = _phone_num;
    w.second.first = _country;
    w.second.second = _city;
  }

  bool find(string worker_name) {
    if (w.first.first.second == worker_name)
      return true;
    return false;
  }
};

// struct worker_queue {
//   queue<worker_info> worker_q;
//   worker_queue(){};
//
//
// };

int main(int argc, char *argv[]) {
  pair<int, string> p{10, "mostafa"};
  cout << p.first << p.second << endl;

  cout << "************* end **************" << endl;
  queue<worker_info> worker_queue;

  // id, name, phone number, <country, city>
  // pair<pair<pair<int, string>, int>, pair<string, string>> worker{
  //     {{151, "Ahemd ali"}, 01020301250}, {"Egypt", "Desouk"}};

  worker_info w1(151, "Ahmed ali", 01020301250, "Egypt", "Desouk");
  worker_info w2(152, "Ramy Islam", 01020301250, "Egypt", "Desouk");
  worker_info w3(153, "Mostafa Saad", 01020301250, "Egypt", "Desouk");

  worker_info w11(151, "Ahmed ali", 01020301250, "Egypt", "Desouk");
  worker_queue.push(w1);
  worker_queue.push(w2);
  worker_queue.push(w3);

  string worker_name = worker_queue.back().w.first.first.second;
  cout << worker_name << endl;

  if (worker_queue.back().find("Mostafa Saad"))
    cout << "i found the best worker" << endl;
  else
    cout << "we lost the best worker in our company" << endl;

  return 0;
}
// cout << "Hello People This Worker his name is: " << worker.first.first.second
//      << " and also i have his id whihc is: " << worker.first.first.first
//      << " i have call you for many hours in your phone number "
//      << worker.first.second << " and your city " << worker.second.first
//      << " is really cool i didn't know that " << worker.second.first
//      << " have some beatiful cities like yours." << endl;
